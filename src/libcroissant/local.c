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
#include "croissant/local.h"
#include "croissant/node.h"


/*-----------------------------------------------------------------------
 * Local nodes
 */

CORK_LOCAL struct crs_node_address *
crs_local_node_address_new(crs_local_node_id id)
{
    struct crs_node_address  *address = cork_new(struct crs_node_address);
    address->type = CRS_NODE_TYPE_LOCAL;
    address->local_id = id;
    return address;
}

CORK_LOCAL struct crs_node_address *
crs_local_node_address_decode(struct crs_message *msg)
{
    crs_local_node_id  id;
    rpi_check(crs_message_decode_uint32(msg, &id, "local node ID"));
    return crs_local_node_address_new(id);
}

CORK_LOCAL void
crs_local_node_address_encode(struct crs_message *msg,
                              const struct crs_node_address *address)
{
    crs_message_encode_uint32(msg, address->local_id);
}

CORK_LOCAL void
crs_local_node_print(struct cork_buffer *dest,
                     const struct crs_node_address *address)
{
    cork_buffer_append_printf(dest, "local:%u", address->local_id);
}


/*-----------------------------------------------------------------------
 * Local node references
 */

static crs_node_ref_send_f  crs_local_node_ref__send;

static int
crs_local_node_ref__send(struct crs_node_ref *ref, crs_id src, crs_id dest,
                         struct crs_message *msg)
{
    /* We should never actually call the `send` method for a local node; the
     * `crs_node_ref_send` method should have noticed that the node was local to
     * the process, and sent the message to the node directly.  So if we ever
     * make it here, something is wrong. */
    crs_io_error("Should have already sent the message to this node");
    return -1;
}

CORK_LOCAL struct crs_node_ref *
crs_local_node_ref_new(struct crs_node *owner, crs_id node_id,
                       const struct crs_node_address *address,
                       struct crs_node *local_node)
{
    /* We always use a proximity of 0 for local nodes, since it should be faster
     * to send a message to a node in the same local process than any other
     * communication mechanism. */
    return crs_node_ref_new_priv
        (owner, node_id, address, 0, local_node,
         NULL, NULL, crs_local_node_ref__send);
}
