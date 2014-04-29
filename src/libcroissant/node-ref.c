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
#include "croissant/context.h"
#include "croissant/message.h"
#include "croissant/node.h"

#define CLOG_CHANNEL  "croissant:node-ref"


/*-----------------------------------------------------------------------
 * Node references
 */

static int
crs_node_ref__default_send(void *ref, crs_id src, crs_id dest,
                           struct crs_message *msg)
{
    return 0;
}

CORK_LOCAL struct crs_node_ref *
crs_node_ref_new(struct crs_node *owner, crs_id id,
                 struct crs_node_address *address)
{
    struct crs_node_ref  *ref = cork_new(struct crs_node_ref);
    ref->bootstrapping = false;
    ref->owner = owner;
    ref->id = id;
    crs_id_to_raw_string(ref->id_str, id);
    ref->address = address;
    cork_buffer_init(&ref->address_str);
    crs_node_address_print(&ref->address_str, address);
    ref->proximity = CRS_PROXIMITY_UNKNOWN;
    ref->user_data = NULL;
    ref->free_user_data = NULL;
    ref->send = crs_node_ref__default_send;
    return ref;
}

CORK_LOCAL struct crs_node_ref *
crs_node_ref_new_bootstrap(struct crs_node *owner,
                           struct crs_node_address *address)
{
    struct crs_node_ref  *ref = cork_new(struct crs_node_ref);
    ref->bootstrapping = true;
    ref->owner = owner;
    crs_id_to_raw_string(ref->id_str, id);
    ref->address = address;
    cork_buffer_init(&ref->address_str);
    crs_node_address_print(&ref->address_str, address);
    ref->proximity = CRS_PROXIMITY_UNKNOWN;
    ref->user_data = NULL;
    ref->free_user_data = NULL;
    ref->send = crs_node_ref__default_send;
    return ref;
}

CORK_LOCAL void
crs_node_ref_free(struct crs_node_ref *ref)
{
    cork_free_user_data(ref);
    cork_buffer_done(&ref->address_str);
    free(ref);
}

void
crs_node_ref_set_user_data(struct crs_node_ref *ref,
                           void *user_data, cork_free_f free_user_data)
{
    cork_free_user_data(ref);
    ref->user_data = user_data;
    ref->free_user_data = free_user_data;
}

void
crs_node_ref_set_send(struct crs_node_ref *ref, crs_node_ref_send_f *send)
{
    ref->send = send;
}

crs_id
crs_node_ref_get_id(const struct crs_node_ref *ref)
{
    return ref->id;
}

int
crs_node_ref_set_id(struct crs_node_ref *ref, crs_id id)
{
    if (ref->bootstrapping) {
        ref->id = id;
        ref->bootstrapping = false;
        return 0;
    } else if (CORK_LIKELY(ref->id == id)) {
        return 0;
    } else {
        crs_io_error
}

const char *
crs_node_ref_get_id_str(const struct crs_node_ref *ref)
{
    return ref->id_str;
}

struct crs_node_address *
crs_node_ref_get_address(const struct crs_node_ref *ref)
{
    return &ref->address;
}

const char *
crs_node_ref_get_address_str(const struct crs_node_ref *ref)
{
    return ref->address_str.buf;
}

crs_proximity
crs_node_ref_get_proximity(const struct crs_node_ref *ref)
{
    return ref->proximity;
}

void
crs_node_ref_set_proximity(struct crs_node_ref *ref, crs_proximity proximity)
{
    ref->proximity = proximity;
}

int
crs_node_ref_send(struct crs_node_ref *ref, crs_id src, crs_id dest,
                  struct crs_message *msg)
{
    return ref->send(ref->user_data, src, dest, msg);
}

int
crs_node_ref_forward(struct crs_node_ref *next_hop, crs_id src, crs_id dest,
                     struct crs_message *msg)
{
    clog_debug("[%s] Forward via %s",
               (char *) next_hop->owner->address_str.buf,
               (char *) next_hop->address_str.buf);
    return crs_node_ref_send(next_hop, src, dest, msg);
}


struct crs_node_ref *
crs_node_ref_decode(struct crs_message *msg, struct crs_node *owner,
                    const char *field_name)
{
    struct crs_ctx  *ctx = owner->ctx;
    crs_id  id;
    const struct crs_node_address  *address;
    rpi_check(crs_id_decode(msg, &id, field_name));
    rpp_check(address = crs_ctx_decode_node_address(msg, ctx, field_name));
    return crs_node_new_ref(owner, id, address);
}

void
crs_node_ref_encode(struct crs_message *msg, const struct crs_node_ref *ref)
{
    crs_id_encode(msg, ref->id);
    crs_node_address_encode(msg, &ref->address);
}
