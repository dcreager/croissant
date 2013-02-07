/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012-2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef CROISSANT_LOCAL_H
#define CROISSANT_LOCAL_H

#include <libcork/core.h>
#include <libcork/ds.h>


/*-----------------------------------------------------------------------
 * Local nodes
 */

typedef unsigned int  crs_local_node_id;

#define CRS_LOCAL_NODE_ID_NONE  0

struct crs_local_message_queue {
    crs_local_node_id  id;
    struct cork_dllist  message_queue;
    struct crs_local_message_queue  *next;
};


CORK_LOCAL void
crs_local_message_queue_init(struct crs_local_message_queue *queue);

CORK_LOCAL void
crs_local_message_queue_done(struct crs_local_message_queue *queue);

#define crs_local_message_queue_is_empty(queue) \
    (cork_dllist_is_empty(&(queue)->message_queue))

CORK_LOCAL void
crs_local_message_queue_add(struct crs_local_message_queue *queue,
                            const void *message, size_t message_length);

CORK_LOCAL struct cork_buffer *
crs_local_message_queue_peek(struct crs_local_message_queue *queue);

CORK_LOCAL int
crs_local_message_queue_pop(struct crs_local_message_queue *queue);

CORK_LOCAL struct crs_local_message_queue *
crs_local_message_queue_get(crs_local_node_id id);


CORK_LOCAL void
crs_local_node_print(const struct crs_node_address *address,
                     struct cork_buffer *dest);

CORK_LOCAL int
crs_local_node_send(const struct crs_node_address *address, const void *message,
                    size_t message_length);


#endif  /* CROISSANT_LOCAL_H */
