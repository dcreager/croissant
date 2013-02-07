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
#include "croissant/tests.h"


/*-----------------------------------------------------------------------
 * Node addresses
 */

void
crs_node_address_print(const struct crs_node_address *address,
                       struct cork_buffer *dest)
{
    switch (address->type) {
        case CRS_LOCAL_NODE:
            return crs_local_node_print(address, dest);

        default:
            cork_unreachable();
    }
}

void
crs_node_address_free(const struct crs_node_address *address)
{
    free((void *) address);
}


/*-----------------------------------------------------------------------
 * Sending messages
 */

int
crs_node_send_message(const struct crs_node_address *dest,
                      const void *message, size_t message_length)
{
    switch (dest->type) {
        case CRS_LOCAL_NODE:
            return crs_local_node_send(dest, message, message_length);

        default:
            cork_unreachable();
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
    if (address != NULL) {
        node->address = *address;
    }
    node->address.local_id = node->local_messages.id;
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
