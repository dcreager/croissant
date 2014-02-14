/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2014, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef CROISSANT_MAINTENANCE_H
#define CROISSANT_MAINTENANCE_H

#include <libcork/core.h>
#include <libcork/ds.h>

#include "croissant.h"


/*-----------------------------------------------------------------------
 * Node maintainance application
 */

struct crs_maintenance;

CORK_LOCAL struct crs_maintenance *
crs_maintenance_new(struct crs_node *node);

CORK_LOCAL void
crs_maintenance_free(struct crs_maintenance *maint);

/* node takes control of maint */
CORK_LOCAL int
crs_maintenance_register(struct crs_maintenance *maint, struct crs_node *node);

CORK_LOCAL struct crs_maintenance *
crs_maintenance_get(struct crs_node *node);

CORK_LOCAL int
crs_maintenance_join(struct crs_maintenance *maint,
                     const struct crs_node_address *bootstrap_node);

CORK_LOCAL int
crs_maintenance_find_joiner(struct crs_maintenance *maint,
                            struct crs_node_ref *dest);

CORK_LOCAL int
crs_maintenance_send_leaf_set(struct crs_maintenance *maint,
                              struct crs_node_ref *dest);

CORK_LOCAL int
crs_maintenance_send_routing_table(struct crs_maintenance *maint,
                                   struct crs_node_ref *dest,
                                   unsigned int row_count);

CORK_LOCAL int
crs_maintenance_announce(struct crs_maintenance *maint,
                         struct crs_node_ref *dest);


#endif  /* CROISSANT_MAINTENANCE_H */
