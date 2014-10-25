/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013-2014, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the COPYING file in this distribution for license details.
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
#include "croissant/maintenance.h"
#include "croissant/message.h"
#include "croissant/node.h"
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
    cork_delete(struct crs_node_address, (struct crs_node_address *) address);
}

const struct crs_node_address *
crs_node_address_decode(struct crs_message *msg, const char *field_name)
{
    crs_node_type_id  type;
    rpi_check(crs_message_decode_uint32(msg, &type, field_name));
    switch (type) {
        case CRS_NODE_TYPE_ID_LOCAL:
            return crs_local_node_address_decode(msg);
        default:
            crs_parse_error("Unknown node type 0x%08" PRIx32, type);
            return NULL;
    }
}

void
crs_node_address_encode(struct crs_message *msg,
                        const struct crs_node_address *address)
{
    crs_message_encode_uint32(msg, crs_node_id_for_type(address->type));
    switch (address->type) {
        case CRS_NODE_TYPE_LOCAL:
            crs_local_node_address_encode(msg, address);
            return;
        default:
            cork_unreachable();
    }
}


static bool
crs_node_address_equals(void *user_data, const void *vaddr1, const void *vaddr2)
{
    const struct crs_node_address  *addr1 = vaddr1;
    const struct crs_node_address  *addr2 = vaddr2;
    if (addr1 == addr2) {
        return true;
    } else if (CORK_UNLIKELY(addr1->type != addr2->type)) {
        return false;
    }
    switch (addr1->type) {
        case CRS_NODE_TYPE_LOCAL:
            return crs_local_node_address_equals(addr1, addr2);
        default:
            cork_unreachable();
    }
}

static cork_hash
crs_node_address_hash(void *user_data, const void *vaddress)
{
    const struct crs_node_address  *address = vaddress;
    switch (address->type) {
        case CRS_NODE_TYPE_LOCAL:
            return crs_local_node_address_hash(address);
        default:
            cork_unreachable();
    }
}

CORK_LOCAL struct cork_hash_table *
crs_node_address_hash_table_new(size_t initial_size, unsigned int flags)
{
    struct cork_hash_table  *table = cork_hash_table_new(initial_size, flags);
    cork_hash_table_set_equals(table, crs_node_address_equals);
    cork_hash_table_set_hash(table, crs_node_address_hash);
    return table;
}


/*-----------------------------------------------------------------------
 * Nodes
 */

static struct crs_node *
crs_node_new_with_id(struct crs_ctx *ctx, crs_id id,
                     const struct crs_node_address *address)
{
    struct crs_node  *node = cork_new(struct crs_node);
    printf("=== %p %p\n", node, &node->id);
    node->id = id;
    crs_id_to_raw_string(node->id_str, id);
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
    node->applications = cork_pointer_hash_table_new(0, 0);
    cork_hash_table_set_free_value
        (node->applications, (cork_free_f) crs_application_free);
    node->ref = crs_local_node_ref_new_self(node);
    node->refs = crs_node_address_hash_table_new(0, 0);
    cork_hash_table_set_free_value(node->refs, (cork_free_f) crs_node_ref_free);
    cork_hash_table_put
        (node->refs, &node->address, node->ref, NULL, NULL, NULL);
    node->routing_table = crs_routing_table_new(node);
    node->leaf_set = crs_leaf_set_new(node);
    node->maint = crs_maintenance_new(node);
    crs_maintenance_register(node->maint, node);
    return node;
}

struct crs_node *
crs_node_new(struct crs_ctx *ctx, crs_id id,
             const struct crs_node_address *address)
{
    return crs_node_new_with_id(ctx, id, address);
}

CORK_LOCAL void
crs_node_free(struct crs_node *node)
{
    clog_debug("[%s] Free node", (char *) node->address_str.buf);
    crs_ctx_remove_node(node->ctx, node);
    cork_hash_table_free(node->applications);
    cork_hash_table_free(node->refs);
    cork_buffer_done(&node->address_str);
    crs_routing_table_free(node->routing_table);
    crs_leaf_set_free(node->leaf_set);
    cork_delete(struct crs_node, node);
}

crs_id
crs_node_get_id(const struct crs_node *node)
{
    return node->id;
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

struct crs_routing_table *
crs_node_get_routing_table(struct crs_node *node)
{
    return node->routing_table;
}

struct crs_leaf_set *
crs_node_get_leaf_set(struct crs_node *node)
{
    return node->leaf_set;
}

struct crs_node_ref *
crs_node_new_ref(struct crs_node *owner,
                 const struct crs_node_address *address)
{
    bool  is_new;
    struct cork_hash_table_entry  *entry;
    /* If we already have a reference to a node with this address, just return
     * it.  Otherwise, create a new reference. */
    entry = cork_hash_table_get_or_create
        (owner->refs, (void *) address, &is_new);
    if (is_new) {
        struct crs_node_ref  *ref = crs_node_ref_new(owner, address);
        entry->key = &ref->address;
        entry->value = ref;
        return ref;
    } else {
        return entry->value;
    }
}


struct crs_node_ref *
crs_node_get_next_hop(struct crs_node *node, crs_id key)
{
    struct crs_node_ref  *ref;

    /* First try the node's leaf set */
    ref = crs_leaf_set_get_closest(node->leaf_set, key);
    if (ref != NULL) {
        clog_debug("[%s] Next hop is %s (leaf set)",
                   (char *) node->address_str.buf,
                   (ref == CRS_NODE_REF_SELF)? "self":
                       crs_node_ref_get_id_str(ref));
        return ref;
    }

    /* Then try the routing table */
    ref = crs_routing_table_get_closest(node->routing_table, key);
    if (ref != NULL) {
        clog_debug("[%s] Next hop is %s (routing table)",
                   (char *) node->address_str.buf,
                   crs_node_ref_get_id_str(ref));
        return ref;
    }

    /* Then look for a fallback */
    ref = crs_leaf_set_get_fallback(node->leaf_set, key);
    if (ref != NULL) {
        clog_debug("[%s] Next hop is %s (leaf set fallback)",
                   (char *) node->address_str.buf,
                   crs_node_ref_get_id_str(ref));
        return ref;
    }

    ref = crs_routing_table_get_fallback(node->routing_table, key);
    if (ref != NULL) {
        clog_debug("[%s] Next hop is %s (routing table fallback)",
                   (char *) node->address_str.buf,
                   crs_node_ref_get_id_str(ref));
        return ref;
    }

    /* And if none of those worked, deliver to the local node */
    clog_debug("[%s] Next hop is self (last resort)",
               (char *) node->address_str.buf);
    return CRS_NODE_REF_SELF;
}

struct crs_message *
crs_node_new_message(struct crs_node *node)
{
    return crs_message_new();
}

void
crs_node_free_message(struct crs_node *node, struct crs_message *msg)
{
    crs_message_free(msg);
}

int
crs_node_route_message(struct crs_node *node, crs_id src, crs_id dest,
                       struct crs_message *msg)
{
    struct crs_node_ref  *next_hop;
    crs_application_id  id;
    struct crs_application  *app;

    /* Determine the next hop for this message. */
    ep_check(next_hop = crs_node_get_next_hop(node, dest));

    /* Decode the beginning of the message to find out which application is
     * belongs to. */
    crs_message_start_reading(msg);
    ei_check(crs_message_decode_uint32(msg, &id, "application ID"));
    ep_check(app = crs_node_get_application(node, id));

    /* Deliver the message to one of the application's callbacks, depending on
     * whether this is the final destination. */
    if (next_hop == CRS_NODE_REF_SELF) {
        int  rc;
        clog_debug("[%s] Deliver message to application \"%s\"",
                   (char *) node->address_str.buf, app->name);
        rc = crs_application_receive(app, node, src, dest, msg);
        crs_message_free(msg);
        return rc;
    } else {
        return crs_application_intercept(app, node, next_hop, src, dest, msg);
    }

error:
    crs_message_free(msg);
    return -1;
}

int
crs_node_send_message(struct crs_node *node, crs_id dest,
                      struct crs_message *msg)
{
    char  dest_str[CRS_ID_STRING_LENGTH];
    clog_debug("[%s] Send message to %s",
               (char *) node->address_str.buf,
               crs_id_to_raw_string(dest_str, dest));
    return crs_node_route_message(node, node->id, dest, msg);
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
        (node->applications, (void *) (uintptr_t) app->id, &is_new);

    if (is_new) {
        entry->value = app;
        app->node = node;
        return 0;
    } else {
        cork_redefined("Already have an application for 0x%08" PRIx32, app->id);
        crs_application_free(app);
        return -1;
    }
}

struct crs_application *
crs_node_get_application(struct crs_node *node, crs_application_id id)
{
    struct crs_application  *result =
        cork_hash_table_get(node->applications, (void *) (uintptr_t) id);
    if (CORK_UNLIKELY(result == NULL)) {
        cork_undefined("No application for 0x%08" PRIx32, id);
    }
    return result;
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

int
crs_node_bootstrap(struct crs_node *node,
                   const struct crs_node_address *bootstrap_node)
{
    /* TODO: We'll also need to fire up any listening servers as this point.
     * Right now we only support local nodes, so this isn't necessary. */
    if (bootstrap_node == NULL) {
        /* We don't know about any other nodes to start with. */
        return 0;
    } else {
        return crs_maintenance_join(node->maint, bootstrap_node);
    }
}

#if 0
int
crs_node_detach(struct crs_node *node)
{
}
#endif
