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

#include <croissant/node.h>


/*-----------------------------------------------------------------------
 * Error handling
 */

/* hash of "crossaint/local.h" */
#define CRS_LOCAL_ERROR  0x795e9e28

enum crs_local_error {
    /* No messages */
    CRS_EMPTY_LOCAL_NODE_QUEUE,
    /* An unknown local node */
    CRS_UNKNOWN_LOCAL_NODE
};

#define crs_set_local_error(code, ...) \
    (cork_error_set(CRS_LOCAL_ERROR, code, __VA_ARGS__))
#define crs_empty_local_node_queue(...) \
    crs_set_local_error(CRS_EMPTY_LOCAL_NODE_QUEUE, __VA_ARGS__)
#define crs_unknown_local_node(...) \
    crs_set_local_error(CRS_UNKNOWN_LOCAL_NODE, __VA_ARGS__)


/*-----------------------------------------------------------------------
 * Types
 */

typedef uint32_t  crs_local_node_id;
struct crs_local_node;
struct crs_local_node_ctx;


/*-----------------------------------------------------------------------
 * Nodes
 */

crs_local_node_id
crs_local_node_get_id(struct crs_local_node *node);

const char *
crs_local_node_get_name(struct crs_local_node *node);

bool
crs_local_node_has_messages(struct crs_local_node *node);

struct cork_buffer *
crs_local_node_peek_message(struct crs_local_node *node);

int
crs_local_node_pop_message(struct crs_local_node *node);


/*-----------------------------------------------------------------------
 * Node contexts
 */

struct crs_local_node_ctx *
crs_local_node_ctx_new(void);

void
crs_local_node_ctx_free(struct crs_local_node_ctx *ctx);

struct crs_node_manager *
crs_local_node_ctx_get_manager(struct crs_local_node_ctx *ctx);

struct crs_local_node *
crs_local_node_ctx_add_node(struct crs_local_node_ctx *ctx, const char *name);

struct crs_local_node *
crs_local_node_ctx_get_node(struct crs_local_node_ctx *ctx,
                            crs_local_node_id id);


/*-----------------------------------------------------------------------
 * Node references
 */

struct crs_node_ref *
crs_local_node_get_ref(struct crs_local_node *node);


#endif  /* CROISSANT_LOCAL_H */
