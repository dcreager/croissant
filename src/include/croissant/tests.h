/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013-2014, RedJack, LLC.
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

/* Ensures that all local nodes have been freed, and resets the local node ID
 * counter.  Useful in test cases to get reproducible output. */
int
crs_finalize_tests(void);


/*-----------------------------------------------------------------------
 * Saving messages
 */

/* A Pastry application that saves each message received into a buffer.  This is
 * mainly used to verify that the contents of the message survive being
 * transported. */

struct crs_save_message;

struct crs_save_message *
crs_save_message_new(crs_application_id id, struct cork_buffer *dest);

void
crs_save_message_free(struct crs_save_message *app);

/* node takes control of app */
int
crs_save_message_register(struct crs_save_message *app, struct crs_node *node);


/*-----------------------------------------------------------------------
 * Printing messages
 */

/* A Pastry application that prints each message received to the given stream.
 * This is mainly used in test cases. */

struct crs_print_message;

struct crs_print_message *
crs_print_message_new(FILE *out);

void
crs_print_message_free(struct crs_print_message *app);

/* node takes control of app */
int
crs_print_message_register(struct crs_print_message *app,
                           struct crs_node *node);

struct crs_print_message *
crs_print_message_get(struct crs_node *node);

int
crs_print_message_send(struct crs_print_message *app, crs_id dest,
                       const char *message);


#endif  /* CROISSANT_TESTS_H */
