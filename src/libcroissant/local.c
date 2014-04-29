/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013-2014, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <stdlib.h>

#include <clogger.h>
#include <libcork/core.h>
#include <libcork/ds.h>
#include <libcork/helpers/errors.h>

#include "croissant.h"
#include "croissant/node.h"

#define CLOG_CHANNEL  "croissant:local"


/*-----------------------------------------------------------------------
 * Local nodes
 */

#define CRS_CONN_TYPE_LOCAL  0x01d3dfa1  /* "local" */

struct crs_local_address {
    unsigned int  local_id;
};

struct crs_locals {
    struct cork_hash_table  *nodes;
};


static struct crs_node *
crs_locals_get_node(struct crs_locals *locals, unsigned int local_id)
{
    return cork_hash_table_get_hash
        (locals->nodes, (cork_hash) local_id, (void *) (uintptr_t) local_id);
}


static void *
crs_local__new_address(void *ct)
{
    return cork_new(struct crs_local_address);
}

static void
crs_local__free_address(void *vaddr)
{
    struct crs_local_address  *addr = vaddr;
    free(addr);
}

static int
crs_local__decode_address(void *vaddr, struct crs_message *msg,
                          const char *field_name)
{
    struct crs_local_address  *addr = vaddr;
    return crs_message_decode_uint32(msg, &addr->local_id, "local node ID");
}

static void
crs_local__encode_address(void *vaddr, struct crs_message *msg)
{
    struct crs_local_address  *addr = vaddr;
    crs_message_encode_uint32(msg, addr->local_id);
}

static int
crs_local__parse_address(void *vaddr, char *str)
{
    struct crs_local_address  *addr = vaddr;
    unsigned long  id;
    char  *endptr = NULL;

    if (CORK_UNLIKELY(*str == '\0')) {
        crs_parse_error("Missing local address identifier");
        return -1;
    }

    id = strtoul(str, &endptr, 10);
    if (CORK_LIKELY(*endptr == '\0')) {
        addr->local_id = id;
        return 0;
    } else {
        crs_parse_error("Invalid local address identifier \"%s\"", str);
        return -1;
    }
}

static void
crs_local__print_address(void *vaddr, struct cork_buffer *dest)
{
    struct crs_local_address  *addr = vaddr;
    cork_buffer_append_printf(dest, "local:%u", addr->local_id);
}


static int
crs_local__bind(void *ct, void *vaddr, struct crs_node *node)
{
    struct crs_locals  *locals = ct;
    struct crs_local_address  *addr = vaddr;
    unsigned int  local_id = addr->local_id;
    bool  is_new;
    struct cork_hash_table_entry  *entry;

    entry = cork_hash_table_get_or_create_hash
        (locals->nodes, (cork_hash) local_id,
         (void *) (uintptr_t) local_id, &is_new);

    if (CORK_LIKELY(is_new)) {
        clog_debug("[%s] Register new node local:%u",
                   crs_node_get_address_str(node), local_id);
        entry->value = node;
        return 0;
    } else {
        crs_io_error("Local node %u already exists", local_id);
        return -1;
    }
}

static int
crs_local__send(void *ref, struct crs_node *node, crs_id src, crs_id dest,
                struct crs_message *msg)
{
    struct crs_node  *target = ref;
    clog_debug("[%s] {local} Send message to %s",
               crs_node_get_address_str(node),
               crs_node_get_address_str(target));
    return crs_node_route_message(target, src, dest, msg);
}

static int
crs_local__connect(void *ct, void *vaddr, struct crs_node *node,
                   struct crs_node_ref *ref, bool bootstrap)
{
    struct crs_locals  *locals = ct;
    struct crs_local_address  *addr = vaddr;
    unsigned int  local_id = addr->local_id;
    struct crs_node  *local_node = crs_locals_get_node(locals, local_id);
    if (CORK_UNLIKELY(local_node == NULL)) {
        crs_io_error("Local node %u doesn't exit", local_id);
        return -1;
    } else {
        clog_debug("[%s] Connect to local:%u",
                   crs_node_get_address_str(node), local_id);
        crs_node_ref_set_user_data(ref, local_node, NULL);
        crs_node_ref_set_send(ref, crs_local__send);
        /* We always use a proximity of 0 for local nodes, since it should be
         * faster to send a message to a node in the same local process than any
         * other communication mechanism. */
        crs_node_ref_set_proximity(ref, 0);
        if (bootstrap) {
            return crs_node_ref_set_id(ref, local_node->id);
        } else {
            return 0;
        }
    }
}


static struct crs_locals *
crs_locals_new(void)
{
    struct crs_locals  *locals = cork_new(struct crs_locals);
    locals->nodes = cork_pointer_hash_table_new(0, 0);
    return locals;
}

static void
crs_locals__free(void *ud)
{
    struct crs_locals  *locals = ud;
    cork_hash_table_free(locals->nodes);
    free(locals);
}

void
crs_ctx_add_locals(struct crs_ctx *ctx)
{
    struct crs_locals  *locals;
    struct crs_conn_type  *type;
    locals = crs_locals_new();
    type = crs_conn_type_new(CRS_CONN_TYPE_LOCAL, "local");
    crs_conn_type_set_user_data(type, locals, crs_locals__free);
    crs_conn_type_set_new_address(type, crs_local__new_address);
    crs_conn_type_set_free_address(type, crs_local__free_address);
    crs_conn_type_set_decode_address(type, crs_local__decode_address);
    crs_conn_type_set_encode_address(type, crs_local__encode_address);
    crs_conn_type_set_parse_address(type, crs_local__parse_address);
    crs_conn_type_set_print_address(type, crs_local__print_address);
    crs_conn_type_set_bind_node(type, crs_local__bind);
    crs_conn_type_set_connect_ref(type, crs_local__connect);
    crs_ctx_add_conn_type(ctx, type);
}
