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

#include <croissant/node.h>


/*-----------------------------------------------------------------------
 * Error handling
 */

/* hash of "crossaint/context.h" */
#define CRS_CONTEXT_ERROR  0x7adc07fd

enum crs_context_error {
    /* Multiple entities with the same ID */
    CRS_DUPLICATE_ENTITY,
    /* No entity with a given ID */
    CRS_UNKNOWN_ENTITY
};

#define crs_set_context_error(code, ...) \
    (cork_error_set(CRS_CONTEXT_ERROR, code, __VA_ARGS__))
#define crs_duplicate_entity(...) \
    crs_set_parse_error(CRS_DUPLICATE_ENTITY, __VA_ARGS__)
#define crs_unknown_entity(...) \
    crs_set_parse_error(CRS_UNKNOWN_ENTITY, __VA_ARGS__)


/*-----------------------------------------------------------------------
 * Contexts
 */

struct crs_context;

struct crs_context *
crs_context_new(void);

void
crs_context_free(struct crs_context *ctx);

/* Takes control of manager */
int
crs_context_add_node_manager(struct crs_context *ctx,
                             struct crs_node_manager *manager);

struct crs_node_ref *
crs_context_decode_address(struct crs_context *ctx, const void *src,
                           size_t size);


#endif  /* CROISSANT_CONTEXT_H */
