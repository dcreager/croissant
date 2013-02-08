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


/* Creates an application that saves each message received into a buffer.  This
 * is mainly used to verify that the contents of the message survive being
 * transported. */
struct crs_application *
crs_save_message_application_new(crs_application_id id,
                                 struct cork_buffer *dest);


#endif  /* CROISSANT_TESTS_H */
