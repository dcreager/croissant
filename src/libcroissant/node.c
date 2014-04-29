/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013-2014, RedJack, LLC.
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
#include "croissant/maintenance.h"
#include "croissant/message.h"
#include "croissant/node.h"
#include "croissant/tests.h"

#define CLOG_CHANNEL  "croissant:node"


/*-----------------------------------------------------------------------
 * Nodes
 */

static int
crs_node__default_detach(void *node)
{
    return 0;
}

CORK_LOCAL struct crs_node *
crs_node_new(crs_id id, struct crs_node_address *address)
{
    struct crs_node  *node = cork_new(struct crs_node);
    node->user_data = NULL;
    node->free_user_data = NULL;
    node->detach = crs_node__default_detach;
    node->id = id;
    crs_id_to_raw_string(node->id_str, id);
    node->address = address;
    cork_buffer_init(&node->address_str);
    crs_node_address_print(&node->address_str, node->address);
    clog_debug("[%s] New node %s",
               (char *) node->address_str.buf, node->id_str);
    node->applications = cork_pointer_hash_table_new(0, 0);
    cork_hash_table_set_free_value
        (node->applications, (cork_free_f) crs_application_free);
    node->ref = crs_self_ref_new(node);
    node->refs = crs_id_hash_table_new(0, 0);
    cork_hash_table_set_free_value(node->refs, (cork_free_f) crs_node_ref_free);
    cork_hash_table_put
        (node->refs, &node->id, node->ref, NULL, NULL, NULL);
    node->routing_table = crs_routing_table_new(node);
    node->leaf_set = crs_leaf_set_new(node);
    node->maint = crs_maintenance_new(node);
    crs_maintenance_register(node->maint, node);
    return node;
}

CORK_LOCAL void
crs_node_free(struct crs_node *node)
{
    clog_debug("[%s] Free node", (char *) node->address_str.buf);
    cork_hash_table_free(node->applications);
    cork_hash_table_free(node->refs);
    cork_buffer_done(&node->address_str);
    crs_routing_table_free(node->routing_table);
    crs_leaf_set_free(node->leaf_set);
    cork_free_user_data(node);
    free(node);
}

void
crs_node_set_user_data(struct crs_node *node,
                       void *user_data, cork_free_f free_user_data)
{
    cork_free_user_data(node);
    node->user_data = user_data;
    node->free_user_data = free_user_data;
}

void
crs_node_set_detach(struct crs_node *node, crs_node_detach_f *detach)
{
    node->detach = detach;
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

struct crs_node_address *
crs_node_get_address(const struct crs_node *node)
{
    return node->address;
}

const char *
crs_node_get_address_str(const struct crs_node *node)
{
    return node->address_str.buf;
}

struct crs_node_ref *
crs_node_get_self_ref(struct crs_node *node)
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
crs_node_get_ref(struct crs_node *owner, crs_id id,
                 struct crs_node_address *address)
{
    bool  is_new;
    struct cork_hash_table_entry  *entry;
    /* If we already have a reference to a node with this address, just return
     * it.  Otherwise, create a new reference. */
    entry = cork_hash_table_get_or_create(owner->refs, &id, &is_new);
    if (is_new) {
        struct crs_node_ref  *ref = crs_node_ref_new(owner, id, address);
        entry->key = &ref->id;
        entry->value = ref;
        return ref;
    } else {
        crs_node_address_free(address);
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
 * Joining and leaving networks
 */

CORK_LOCAL void
crs_node_bootstrap(struct crs_node *node,
                   struct crs_node_address *bootstrap_address,
                   void *user_data, crs_node_ready_f *ready,
                   crs_error_f *on_error)
{
    struct crs_conn_type  *type = node->address->type;
    ei_check(type->bind(type->user_data, node));

    if (bootstrap_node == NULL) {
        /* We don't know about any other nodes to start with. */
        ready(user_data, node);
        return;
    } else {
        return crs_maintenance_join(node->maint, bootstrap_node);
    }

error:
    on_error(user_data);
}

int
crs_node_detach(struct crs_node *node)
{
    return node->detach(node->user_data);
}
