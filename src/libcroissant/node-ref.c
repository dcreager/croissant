/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013-2014, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <libcork/core.h>
#include <libcork/ds.h>
#include <libcork/helpers/errors.h>

#include "croissant.h"
#include "croissant/context.h"
#include "croissant/node.h"


/*-----------------------------------------------------------------------
 * Node references
 */

CORK_LOCAL struct crs_node_ref *
crs_node_ref_new_priv(struct crs_node *owner, crs_id node_id,
                      const struct crs_node_address *address,
                      crs_proximity proximity,
                      struct crs_node *local_node,
                      void *user_data, cork_free_f free_user_data,
                      crs_node_ref_send_f *send)
{
    struct crs_node_ref  *ref = cork_new(struct crs_node_ref);
    ref->owner = owner;
    ref->id = node_id;
    crs_id_to_raw_string(ref->id_str, node_id);
    ref->address = *address;
    cork_buffer_init(&ref->address_str);
    crs_node_address_print(&ref->address_str, address);
    ref->proximity = proximity;
    ref->local_node = local_node;
    ref->user_data = user_data;
    ref->free_user_data = free_user_data;
    ref->send = send;
    return ref;
}

CORK_LOCAL struct crs_node_ref *
crs_node_ref_new(struct crs_node *owner,
                 const struct crs_node_address *address)
{
    switch (address->type) {
        case CRS_NODE_TYPE_LOCAL:
            /* We ignore the proximity value for local nodes; since they're
             * local, we always use a proximity of 0. */
            return crs_local_node_ref_new(owner, address);
        default:
            cork_unreachable();
    }
}

void
crs_node_ref_free(struct crs_node_ref *ref)
{
    cork_free_user_data(ref);
    cork_buffer_done(&ref->address_str);
    free(ref);
}

crs_id
crs_node_ref_get_id(const struct crs_node_ref *ref)
{
    return ref->id;
}

const char *
crs_node_ref_get_id_str(const struct crs_node_ref *ref)
{
    return ref->id_str;
}

const struct crs_node_address *
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
    /* If the node in question is in the current process, just sent the message
     * directly. */
    if (ref->local_node == NULL) {
        return ref->send(ref, src, dest, msg);
    } else {
        return crs_node_route_message(ref->local_node, src, dest, msg);
    }
}
