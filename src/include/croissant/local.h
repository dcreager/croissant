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

#include "croissant.h"


/*-----------------------------------------------------------------------
 * Local nodes
 */

typedef unsigned int  crs_local_node_id;

#define CRS_LOCAL_NODE_ID_NONE  0

CORK_LOCAL struct crs_node *
crs_local_node_get(crs_local_node_id id);

CORK_LOCAL struct crs_node_address *
crs_local_node_address_new(crs_local_node_id id);

CORK_LOCAL struct crs_node_address *
crs_local_node_address_decode(const void *message, size_t message_length);

CORK_LOCAL void
crs_local_node_address_encode(const struct crs_node_address *address,
                              struct cork_buffer *dest);

CORK_LOCAL void
crs_local_node_print(const struct crs_node_address *address,
                     struct cork_buffer *dest);

CORK_LOCAL int
crs_local_node_send(struct crs_node *src, const struct crs_node_address *dest,
                    const void *message, size_t message_length);


#endif  /* CROISSANT_LOCAL_H */