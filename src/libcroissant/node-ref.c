/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013, RedJack, LLC.
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
#include "croissant/node.h"


/*-----------------------------------------------------------------------
 * Node references
 */

CORK_LOCAL struct crs_node_ref *
crs_node_ref_new_priv(const struct crs_id *node_id,
                      const struct crs_node_address *address,
                      struct crs_node *local_node,
                      void *user_data, cork_free_f free_user_data,
                      crs_node_ref_send_f send)
{
    struct crs_node_ref  *ref = cork_new(struct crs_node_ref);
    ref->id = *node_id;
    ref->address = *address;
    ref->local_node = local_node;
    ref->user_data = user_data;
    ref->free_user_data = free_user_data;
    ref->send = send;
    return ref;
}

struct crs_node_ref *
crs_node_ref_new(const struct crs_id *node_id,
                 const struct crs_node_address *address)
{
    struct crs_node  *local_node = NULL;

    if (address->local_id != CRS_LOCAL_NODE_ID_NONE) {
        /* The node in question is in the local process, so let's link the node
         * reference to the node object. */
        rpp_check(local_node = crs_local_node_get(address->local_id));
    }

    switch (address->type) {
        case CRS_NODE_TYPE_LOCAL:
            return crs_local_node_ref_new(node_id, address, local_node);

        default:
            cork_unreachable();
    }
}

void
crs_node_ref_free(struct crs_node_ref *ref)
{
    cork_free_user_data(ref);
    free(ref);
}

int
crs_node_ref_send(struct crs_node_ref *dest, const struct crs_node *src,
                  const void *message, size_t message_length)
{
    /* If the node in question is in the current process, just sent the message
     * directly. */
    if (dest->local_node != NULL) {
        return crs_node_process_message
            (dest->local_node, &src->id, message, message_length);
    } else {
        return dest->send(dest, src, message, message_length);
    }
}
