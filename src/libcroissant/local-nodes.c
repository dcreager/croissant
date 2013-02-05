/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012-2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <libcork/core.h>
#include <libcork/ds.h>
#include <libcork/helpers/errors.h>

#include "croissant/local.h"
#include "croissant/node.h"


/*-----------------------------------------------------------------------
 * Types
 */

struct crs_local_message {
    struct cork_dllist_item  list;
    struct cork_buffer  content;
};

struct crs_local_node {
    struct cork_dllist  message_queue;
    crs_local_node_id  id;
    const char  *name;
    struct crs_local_node_ctx  *context;
};

struct crs_local_node_ctx {
    struct crs_node_manager  manager;
    cork_array(struct crs_local_node *)  nodes;
};

struct crs_local_node_ref {
    struct crs_node_ref  parent;
    crs_local_node_id  id;
};


/*-----------------------------------------------------------------------
 * Nodes
 */

static void
crs_local_message_free(struct crs_local_message *msg)
{
    cork_buffer_done(&msg->content);
    free(msg);
}

static struct crs_local_node *
crs_local_node_new(struct crs_local_node_ctx *context,
                   crs_local_node_id id, const char *name)
{
    struct crs_local_node  *self = cork_new(struct crs_local_node);
    cork_dllist_init(&self->message_queue);
    self->id = id;
    self->name = cork_strdup(name);
    self->context = context;
    return self;
}

static void
crs_local_node_free(struct crs_local_node *self)
{
    struct cork_dllist_item  *curr;
    struct cork_dllist_item  *next;
    cork_strfree(self->name);
    for (curr = cork_dllist_start(&self->message_queue);
         !cork_dllist_is_end(&self->message_queue, curr);
         curr = next) {
        struct crs_local_message  *msg =
            cork_container_of(curr, struct crs_local_message, list);
        next = curr->next;
        crs_local_message_free(msg);
    }
    free(self);
}

crs_local_node_id
crs_local_node_get_id(struct crs_local_node *self)
{
    return self->id;
}

const char *
crs_local_node_get_name(struct crs_local_node *self)
{
    return self->name;
}

static void
crs_local_node_queue_message(struct crs_local_node *self,
                             struct cork_buffer *src)
{
    struct crs_local_message  *msg = cork_new(struct crs_local_message);
    msg->content = *src;
    cork_buffer_init(src);
    cork_dllist_add(&self->message_queue, &msg->list);
}

#define crs_local_node_has_messages_priv(node) \
    (!cork_dllist_is_empty(&(node)->message_queue))

bool
crs_local_node_has_messages(struct crs_local_node *node)
{
    return crs_local_node_has_messages_priv(node);
}

struct cork_buffer *
crs_local_node_peek_message(struct crs_local_node *node)
{
    if (CORK_LIKELY(crs_local_node_has_messages_priv(node))) {
        struct crs_local_message  *msg =
            cork_container_of(cork_dllist_head(&node->message_queue),
                              struct crs_local_message, list);
        return &msg->content;
    } else {
        cork_error_set
            (CRS_LOCAL_ERROR, CRS_EMPTY_LOCAL_NODE_QUEUE,
             "Local node %" PRIu32 " (%s) has no messages",
             node->id, node->name);
        return NULL;
    }
}

int
crs_local_node_pop_message(struct crs_local_node *node)
{
    if (CORK_LIKELY(crs_local_node_has_messages_priv(node))) {
        struct crs_local_message  *msg =
            cork_container_of(cork_dllist_head(&node->message_queue),
                              struct crs_local_message, list);
        cork_dllist_remove(&msg->list);
        crs_local_message_free(msg);
        return 0;
    } else {
        cork_error_set
            (CRS_LOCAL_ERROR, CRS_EMPTY_LOCAL_NODE_QUEUE,
             "Local node %" PRIu32 " (%s) has no messages",
             node->id, node->name);
        return 1;
    }
}


/*-----------------------------------------------------------------------
 * Node references
 */

static struct crs_node_ref *
crs_local_node_ref_new(struct crs_local_node_ctx *context, crs_local_node_id id)
{
    struct crs_local_node_ref  *ref = cork_new(struct crs_local_node_ref);
    ref->parent.manager = &context->manager;
    ref->id = id;
    return &ref->parent;
}

static void
crs_local_node_ref_free(struct crs_local_node_ref *ref)
{
    free(ref);
}

struct crs_node_ref *
crs_local_node_get_ref(struct crs_local_node *node)
{
    return crs_local_node_ref_new(node->context, node->id);
}


/*-----------------------------------------------------------------------
 * Node contexts
 */

static int
crs_local_node_ctx__send_message(struct crs_node_ref *vdest,
                                 struct cork_buffer *msg)
{
    struct crs_local_node_ref  *dest =
        cork_container_of(vdest, struct crs_local_node_ref, parent);
    struct crs_local_node_ctx  *ctx =
        cork_container_of(vdest->manager, struct crs_local_node_ctx, manager);
    struct crs_local_node  *node;
    rip_check(node = crs_local_node_ctx_get_node(ctx, dest->id));
    crs_local_node_queue_message(node, msg);
    return 0;
}

static void
crs_local_node_ctx__print_address(struct crs_node_ref *vref,
                                  struct cork_buffer *dest)
{
    struct crs_local_node_ref  *ref =
        cork_container_of(vref, struct crs_local_node_ref, parent);
    cork_buffer_append_printf(dest, "local:%" PRIu32, ref->id);
}

static void
crs_local_node_ctx__free_ref(struct crs_node_ref *vref)
{
    struct crs_local_node_ref  *ref =
        cork_container_of(vref, struct crs_local_node_ref, parent);
    crs_local_node_ref_free(ref);
}

static void
crs_local_node_ctx__free_manager(struct crs_node_manager *vmanager)
{
    struct crs_local_node_ctx  *self =
        cork_container_of(vmanager, struct crs_local_node_ctx, manager);
    crs_local_node_ctx_free(self);
}

struct crs_local_node_ctx *
crs_local_node_ctx_new(void)
{
    struct crs_local_node_ctx  *self = cork_new(struct crs_local_node_ctx);
    cork_array_init(&self->nodes);
    self->manager.send_message = crs_local_node_ctx__send_message;
    self->manager.print_address = crs_local_node_ctx__print_address;
    self->manager.free_ref = crs_local_node_ctx__free_ref;
    self->manager.free_manager = crs_local_node_ctx__free_manager;
    return self;
}

void
crs_local_node_ctx_free(struct crs_local_node_ctx *self)
{
    size_t  i;
    for (i = 0; i < cork_array_size(&self->nodes); i++) {
        struct crs_local_node  *node = cork_array_at(&self->nodes, i);
        crs_local_node_free(node);
    }
    free(self);
}

struct crs_local_node *
crs_local_node_ctx_add_node(struct crs_local_node_ctx *self, const char *name)
{
    crs_local_node_id  new_id = cork_array_size(&self->nodes);
    struct crs_local_node  *node = crs_local_node_new(self, new_id, name);
    cork_array_append(&self->nodes, node);
    return node;
}

struct crs_local_node *
crs_local_node_ctx_get_node(struct crs_local_node_ctx *self,
                            crs_local_node_id id)
{
    if (CORK_LIKELY(id < cork_array_size(&self->nodes))) {
        return cork_array_at(&self->nodes, id);
    } else {
        cork_error_set
            (CRS_LOCAL_ERROR, CRS_UNKNOWN_LOCAL_NODE,
             "No local node with ID %" PRIu32, id);
        return NULL;
    }
}
