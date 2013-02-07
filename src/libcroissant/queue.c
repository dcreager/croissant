/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012, RedJack, LLC.
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
 * Local node registry
 */

static crs_local_node_id  last_id = 0;
static struct crs_local_message_queue  *queues = NULL;

#define crs_local_node_id_get_next() \
    (++last_id)

static void
crs_local_message_queue_save(struct crs_local_message_queue *queue)
{
    queue->next = queues;
    queues = queue;
}

static void
crs_local_message_queue_remove(struct crs_local_message_queue *queue)
{
    struct crs_local_message_queue  *prev = NULL;
    struct crs_local_message_queue  *curr = queues;
    while (curr != NULL) {
        if (curr == queue) {
            if (prev == NULL) {
                queues = curr->next;
            } else {
                prev->next = curr->next;
            }
            return;
        }
    }
}

CORK_LOCAL struct crs_local_message_queue *
crs_local_message_queue_get(crs_local_node_id id)
{
    struct crs_local_message_queue  *curr = queues;
    while (curr != NULL) {
        if (curr->id == id) {
            return curr;
        }
    }
    return NULL;
}

int
crs_finalize_tests(void)
{
    if (CORK_LIKELY(queues == NULL)) {
        last_id = 0;
        return 0;
    } else {
        crs_unknown_error("Some local nodes have not been freed");
        return -1;
    }
}


/*-----------------------------------------------------------------------
 * Local nodes
 */

struct crs_local_message {
    struct cork_dllist_item  list;
    struct cork_buffer  content;
};


CORK_LOCAL void
crs_local_message_queue_init(struct crs_local_message_queue *queue)
{
    queue->id = crs_local_node_id_get_next();
    cork_dllist_init(&queue->message_queue);
    crs_local_message_queue_save(queue);
}

static void
crs_local_message_free(struct crs_local_message *msg)
{
    cork_buffer_done(&msg->content);
    free(msg);
}


CORK_LOCAL void
crs_local_message_queue_done(struct crs_local_message_queue *queue)
{
    struct cork_dllist_item  *curr;
    struct cork_dllist_item  *next;
    for (curr = cork_dllist_start(&queue->message_queue);
         !cork_dllist_is_end(&queue->message_queue, curr);
         curr = next) {
        struct crs_local_message  *msg =
            cork_container_of(curr, struct crs_local_message, list);
        next = curr->next;
        crs_local_message_free(msg);
    }

    crs_local_message_queue_remove(queue);
}

CORK_LOCAL struct cork_buffer *
crs_local_message_queue_peek(struct crs_local_message_queue *queue)
{
    if (CORK_UNLIKELY(crs_local_message_queue_is_empty(queue))) {
        crs_empty_local_node_queue("Local node %u has no messages", queue->id);
        return NULL;
    } else {
        struct crs_local_message  *msg =
            cork_container_of(cork_dllist_head(&queue->message_queue),
                              struct crs_local_message, list);
        return &msg->content;
    }
}

CORK_LOCAL int
crs_local_message_queue_pop(struct crs_local_message_queue *queue)
{
    if (CORK_UNLIKELY(crs_local_message_queue_is_empty(queue))) {
        crs_empty_local_node_queue("Local node %u has no messages", queue->id);
        return -1;
    } else {
        struct crs_local_message  *msg =
            cork_container_of(cork_dllist_head(&queue->message_queue),
                              struct crs_local_message, list);
        cork_dllist_remove(&msg->list);
        crs_local_message_free(msg);
        return 0;
    }
}

CORK_LOCAL void
crs_local_message_queue_add(struct crs_local_message_queue *queue,
                            const void *message, size_t message_length)
{
    struct crs_local_message  *msg = cork_new(struct crs_local_message);
    cork_buffer_init(&msg->content);
    cork_buffer_set(&msg->content, message, message_length);
    cork_dllist_add(&queue->message_queue, &msg->list);
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
