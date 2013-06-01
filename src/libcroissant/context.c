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
#include <libcork/helpers/errors.h>

#include "croissant.h"
#include "croissant/context.h"
#include "croissant/local.h"
#include "croissant/node.h"


/*-----------------------------------------------------------------------
 * Contexts
 */

struct crs_ctx *
crs_ctx_new(void)
{
    struct crs_ctx  *ctx = cork_new(struct crs_ctx);
    ctx->nodes = NULL;
    ctx->last_id = 0;
    return ctx;
}

void
crs_ctx_free(struct crs_ctx *ctx)
{
    struct crs_node  *curr;
    struct crs_node  *next;
    for (curr = ctx->nodes; curr != NULL; curr = next) {
        next = curr->next;
        crs_node_free(curr);
    }
    free(ctx);
}

CORK_LOCAL crs_local_node_id
crs_ctx_next_node_id(struct crs_ctx *ctx)
{
    return ++ctx->last_id;
}

CORK_LOCAL void
crs_ctx_add_node(struct crs_ctx *ctx, struct crs_node *node)
{
    node->ctx = ctx;
    node->next = ctx->nodes;
    ctx->nodes = node;
}

CORK_LOCAL void
crs_ctx_remove_node(struct crs_ctx *ctx, struct crs_node *node)
{
    struct crs_node  *prev = NULL;
    struct crs_node  *curr = ctx->nodes;
    for (curr = ctx->nodes; curr != NULL; curr = curr->next) {
        if (curr == node) {
            if (prev == NULL) {
                ctx->nodes = curr->next;
            } else {
                prev->next = curr->next;
            }
            return;
        }
    }
}

CORK_LOCAL struct crs_node *
crs_ctx_get_node(struct crs_ctx *ctx, crs_local_node_id id)
{
    struct crs_node  *curr;
    for (curr = ctx->nodes; curr != NULL; curr = curr->next) {
        if (curr->address.local_id == id) {
            return curr;
        }
    }
    return NULL;
}

struct crs_node *
crs_ctx_get_node_with_id(struct crs_ctx *ctx, const struct crs_id *id)
{
    struct crs_node  *curr;
    for (curr = ctx->nodes; curr != NULL; curr = curr->next) {
        if (crs_id_equals(id, &curr->id)) {
            return curr;
        }
    }
    return NULL;
}
