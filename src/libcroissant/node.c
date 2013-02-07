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
#include "croissant/tests.h"


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
crs_node_address_print(const struct crs_node_address *address,
                       struct cork_buffer *dest)
{
    switch (address->type) {
        case CRS_NODE_TYPE_LOCAL:
            crs_local_node_print(address, dest);
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
 * Sending messages
 */

int
crs_node_send_message(const struct crs_node_address *dest,
                      const void *message, size_t message_length)
{
    /* If the node in question is in the current process, just sent the message
     * directly. */
    if (dest->local_id != CRS_LOCAL_NODE_ID_NONE) {
        return crs_local_node_send(dest, message, message_length);
    } else {
        crs_io_error("Don't know how to send to this node.");
        return -1;
    }
}


/*-----------------------------------------------------------------------
 * Nodes
 */

static struct crs_node *
crs_node_new_with_id(const struct crs_id *id,
                     const struct crs_node_address *address)
{
    struct crs_node  *node = cork_new(struct crs_node);
    node->id = *id;
    crs_local_message_queue_init(&node->local_messages);
    if (address == NULL) {
        node->address.type = CRS_NODE_TYPE_LOCAL;
        node->address.local_id = node->local_messages.id;
    } else {
        node->address = *address;
        node->address.local_id = node->local_messages.id;
    }
    return node;
}

struct crs_node *
crs_node_new(const struct crs_node_address *address)
{
    struct crs_id  id;
    memset(&id, 0, sizeof(struct crs_id));
    return crs_node_new_with_id(&id, address);
}

void
crs_node_free(struct crs_node *node)
{
    crs_local_message_queue_done(&node->local_messages);
    free(node);
}

const struct crs_id *
crs_node_get_id(struct crs_node *node)
{
    return &node->id;
}

const struct crs_node_address *
crs_node_get_address(struct crs_node *node)
{
    struct crs_node_address  *address = cork_new(struct crs_node_address);
    *address = node->address;
    return address;
}


/*-----------------------------------------------------------------------
 * Test case helper functions
 */

struct crs_node *
crs_test_node_new(const struct crs_id *id,
                  const struct crs_node_address *address)
{
    return crs_node_new_with_id(id, address);
}

bool
crs_node_has_local_messages(struct crs_node *node)
{
    return !crs_local_message_queue_is_empty(&node->local_messages);
}

struct cork_buffer *
crs_node_peek_local_message(struct crs_node *node)
{
    return crs_local_message_queue_peek(&node->local_messages);
}

int
crs_node_pop_local_message(struct crs_node *node)
{
    return crs_local_message_queue_pop(&node->local_messages);
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
