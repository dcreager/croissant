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
#include "croissant/local.h"
#include "croissant/node.h"
#include "croissant/parse.h"


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
crs_local_node_address_decode(const void *message, size_t message_length)
{
    crs_local_node_id  id;
    rpi_check(crs_ensure_size
              (message_length, sizeof(uint32_t), "local node ID"));
    id = crs_decode_uint32(&message, &message_length);
    return crs_local_node_address_new(id);
}

CORK_LOCAL void
crs_local_node_address_encode(const struct crs_node_address *address,
                              struct cork_buffer *dest)
{
    crs_encode_uint32(dest, address->local_id);
}

CORK_LOCAL void
crs_local_node_print(const struct crs_node_address *address,
                     struct cork_buffer *dest)
{
    cork_buffer_append_printf(dest, "local:%u", address->local_id);
}


CORK_LOCAL int
crs_local_node_send(const struct crs_node_address *address, const void *message,
                    size_t message_length)
{
    struct crs_local_message_queue  *queue;
    rip_check(queue = crs_local_message_queue_get(address->local_id));
    crs_local_message_queue_add(queue, message, message_length);
    return 0;
}
