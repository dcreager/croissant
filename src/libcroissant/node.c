/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <clogger.h>
#include <libcork/core.h>
#include <libcork/ds.h>
#include <libcork/helpers/errors.h>

#include "croissant.h"
#include "croissant/application.h"
#include "croissant/context.h"
#include "croissant/local.h"
#include "croissant/node.h"
#include "croissant/parse.h"
#include "croissant/tests.h"

#define CLOG_CHANNEL  "croissant:node"


/*-----------------------------------------------------------------------
 * Node types
 */

CORK_LOCAL crs_node_type_id
crs_node_id_for_type(enum crs_node_type type)
{
    switch (type) {
        case CRS_NODE_TYPE_LOCAL:
            return CRS_NODE_TYPE_ID_LOCAL;

        default:
            cork_unreachable();
    }
}

CORK_LOCAL enum crs_node_type
crs_node_type_for_id(crs_node_type_id id)
{
    switch (id) {
        case CRS_NODE_TYPE_ID_LOCAL:
            return CRS_NODE_TYPE_LOCAL;

        default:
            cork_unreachable();
    }
}


/*-----------------------------------------------------------------------
 * Node addresses
 */

void
crs_node_address_print(struct cork_buffer *dest,
                       const struct crs_node_address *address)
{
    switch (address->type) {
        case CRS_NODE_TYPE_LOCAL:
            crs_local_node_print(dest, address);
            return;

        default:
            cork_unreachable();
    }
}

void
crs_node_address_free(const struct crs_node_address *address)
{
    free((void *) address);
}

const struct crs_node_address *
crs_node_address_decode(const void *message, size_t message_length)
{
    crs_node_type_id  type;
    rpi_check(crs_ensure_size(message_length, sizeof(uint32_t), "node type"));
    type = crs_decode_uint32(&message, &message_length);
    switch (type) {
        case CRS_NODE_TYPE_ID_LOCAL:
            return crs_local_node_address_decode(message, message_length);

        default:
            crs_parse_error("Unknown node type 0x%08" PRIx32, type);
            return NULL;
    }
}

void
crs_node_address_encode(const struct crs_node_address *address,
                        struct cork_buffer *dest)
{
    crs_encode_uint32(dest, crs_node_id_for_type(address->type));
    switch (address->type) {
        case CRS_NODE_TYPE_LOCAL:
            crs_local_node_address_encode(address, dest);
            return;

        default:
            cork_unreachable();
    }
}


/*-----------------------------------------------------------------------
 * Nodes
 */

static struct crs_node *
crs_node_new_with_id(struct crs_ctx *ctx, const struct crs_id *id,
                     const struct crs_node_address *address)
{
    struct crs_node  *node = cork_new(struct crs_node);
    node->id = *id;
    crs_id_to_raw_string(id, node->id_str);
    if (address == NULL) {
        node->address.type = CRS_NODE_TYPE_LOCAL;
    } else {
        node->address = *address;
    }
    node->address.local_id = crs_ctx_next_node_id(ctx);
    cork_buffer_init(&node->address_str);
    crs_node_address_print(&node->address_str, &node->address);
    clog_debug("[%s] New node %s", (char *) node->address_str.buf, node->id_str);
    crs_ctx_add_node(ctx, node);
    cork_pointer_hash_table_init(&node->applications, 0);
    node->ref = crs_local_node_ref_new(node, &node->id, &node->address, node);
    node->refs = NULL;
    return node;
}

struct crs_node *
crs_node_new(struct crs_ctx *ctx, const struct crs_id *id,
             const struct crs_node_address *address)
{
    if (id == NULL) {
        struct crs_id  zero_id;
        memset(&zero_id, 0, sizeof(struct crs_id));
        id = &zero_id;
    }
    return crs_node_new_with_id(ctx, id, address);
}

static enum cork_hash_table_map_result
free_application(struct cork_hash_table_entry *entry, void *user_data)
{
    struct crs_application  *app = entry->value;
    crs_application_free(app);
    return CORK_HASH_TABLE_MAP_DELETE;
}

CORK_LOCAL void
crs_node_free(struct crs_node *node)
{
    struct crs_node_ref  *curr;
    struct crs_node_ref  *next;
    clog_debug("[%s] Free node", (char *) node->address_str.buf);
    crs_ctx_remove_node(node->ctx, node);
    cork_hash_table_map(&node->applications, free_application, NULL);
    cork_hash_table_done(&node->applications);
    crs_node_ref_free(node->ref);
    for (curr = node->refs; curr != NULL; curr = next) {
        next = curr->next;
        crs_node_ref_free(curr);
    }
    cork_buffer_done(&node->address_str);
    free(node);
}

const struct crs_id *
crs_node_get_id(const struct crs_node *node)
{
    return &node->id;
}

const char *
crs_node_get_id_str(const struct crs_node *node)
{
    return node->id_str;
}

const struct crs_node_address *
crs_node_get_address(const struct crs_node *node)
{
    return &node->address;
}

const char *
crs_node_get_address_str(const struct crs_node *node)
{
    return node->address_str.buf;
}

struct crs_node_ref *
crs_node_get_ref(struct crs_node *node)
{
    return node->ref;
}

struct crs_node_ref *
crs_node_new_ref(struct crs_node *owner, const struct crs_id *node_id,
                 const struct crs_node_address *address)
{
    struct crs_node_ref  *ref;

    /* First see if node_id refers to the current node, or to a node that we've
     * already created a reference to. */
    if (crs_id_equals(node_id, &owner->id)) {
        return owner->ref;
    }

    for (ref = owner->refs; ref != NULL; ref = ref->next) {
        if (crs_id_equals(node_id, &ref->id)) {
            return ref;
        }
    }

    /* Otherwise create a new node reference. */
    ref = crs_node_ref_new(owner, node_id, address);
    ref->next = owner->refs;
    owner->refs = ref;
    return ref;
}


/*-----------------------------------------------------------------------
 * Node applications
 */

int
crs_node_add_application(struct crs_node *node, struct crs_application *app)
{
    bool  is_new;
    struct cork_hash_table_entry  *entry =
        cork_hash_table_get_or_create
        (&node->applications, (void *) (uintptr_t) app->id, &is_new);

    if (is_new) {
        entry->value = app;
        return 0;
    } else {
        crs_duplicate_application
            ("Already have an application for 0x%08" PRIx32, app->id);
        crs_application_free(app);
        return -1;
    }
}

static struct crs_application *
crs_node_get_application(struct crs_node *node, crs_application_id id)
{
    struct crs_application  *result =
        cork_hash_table_get(&node->applications, (void *) (uintptr_t) id);
    if (CORK_UNLIKELY(result == NULL)) {
        crs_unknown_application("No application for 0x%08" PRIx32, id);
    }
    return result;
}

CORK_LOCAL int
crs_node_process_message(struct crs_node *node,
                         const struct crs_id *src, const struct crs_id *dest,
                         const void *message, size_t message_length)
{
    crs_application_id  id;
    struct crs_application  *app;
    rii_check(crs_ensure_size
              (message_length, sizeof(uint32_t), "application ID"));
    id = crs_decode_uint32(&message, &message_length);
    rip_check(app = crs_node_get_application(node, id));
    return crs_application_process
        (app, node, src, dest, message, message_length);
}


/*-----------------------------------------------------------------------
 * Test case helper functions
 */

int
crs_finalize_tests(void)
{
    return 0;
}


/*-----------------------------------------------------------------------
 * Joining and leaving networks
 */

#if 0
int
crs_node_bootstrap(struct crs_node *node,
                   const struct crs_node_address *bootstrap_node)
{
}

int
crs_node_detach(struct crs_node *node)
{
}
#endif
