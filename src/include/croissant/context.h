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
#include "croissant/node.h"


/*-----------------------------------------------------------------------
 * Contexts
 */

CORK_LOCAL struct crs_node_address *
crs_ctx_decode_node_address(struct crs_message *msg, struct crs_ctx *ctx,
                            const char *field_name);

CORK_LOCAL struct crs_node_address *
crs_ctx_parse_node_address(struct crs_ctx *ctx, const char *str);


#endif  /* CROISSANT_CONTEXT_H */
