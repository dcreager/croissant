/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012-2014, RedJack, LLC.
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

CORK_LOCAL struct crs_node_address *
crs_local_node_address_new(crs_local_node_id id);

CORK_LOCAL struct crs_node_address *
crs_local_node_address_decode(struct crs_message *msg);

CORK_LOCAL void
crs_local_node_address_encode(struct crs_message *msg,
                              const struct crs_node_address *address);

CORK_LOCAL void
crs_local_node_print(struct cork_buffer *dest,
                     const struct crs_node_address *address);


/*-----------------------------------------------------------------------
 * Local node references
 */

CORK_LOCAL struct crs_node_ref *
crs_local_node_ref_new(struct crs_node *owner, crs_id node_id,
                       const struct crs_node_address *address,
                       struct crs_node *local_node);


#endif  /* CROISSANT_LOCAL_H */
