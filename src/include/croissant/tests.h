/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef CROISSANT_TESTS_H
#define CROISSANT_TESTS_H

#include <libcork/core.h>
#include <libcork/ds.h>

#include "croissant.h"


/*-----------------------------------------------------------------------
 * Test case helper functions
 */

/* Creates a new Pastry node with a specific node ID.  This should *only* be
 * used for test cases. */
struct crs_node *
crs_test_node_new(const struct crs_id *id,
                  const struct crs_node_address *address);

/* Ensures that all local nodes have been freed, and resets the local node ID
 * counter.  Useful in test cases to get reproducible output. */
int
crs_finalize_tests(void);

bool
crs_node_has_local_messages(struct crs_node *node);

struct cork_buffer *
crs_node_peek_local_message(struct crs_node *node);

int
crs_node_pop_local_message(struct crs_node *node);


#endif  /* CROISSANT_TESTS_H */

