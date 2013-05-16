/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef CROISSANT_CONTEXT_H
#define CROISSANT_CONTEXT_H

#include <libcork/core.h>

#include "croissant.h"
#include "croissant/local.h"


/*-----------------------------------------------------------------------
 * Contexts
 */

struct crs_ctx {
    struct crs_node  *nodes;
    struct crs_node_ref  *refs;
    crs_local_node_id  last_id;
};

CORK_LOCAL crs_local_node_id
crs_ctx_next_node_id(struct crs_ctx *ctx);

CORK_LOCAL void
crs_ctx_add_node(struct crs_ctx *ctx, struct crs_node *node);

CORK_LOCAL void
crs_ctx_remove_node(struct crs_ctx *ctx, struct crs_node *node);

CORK_LOCAL struct crs_node *
crs_ctx_get_node(struct crs_ctx *ctx, crs_local_node_id id);

CORK_LOCAL struct crs_node *
crs_ctx_get_node_with_id(struct crs_ctx *ctx, const struct crs_id *id);


#endif  /* CROISSANT_CONTEXT_H */
