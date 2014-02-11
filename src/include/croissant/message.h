/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2014, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef CROISSANT_MESSAGE_H
#define CROISSANT_MESSAGE_H

#include <libcork/core.h>
#include <libcork/ds.h>

#include "croissant.h"


/*-----------------------------------------------------------------------
 * Messages
 */

/* cursor == NULL if the message is write-only; non-NULL if it's read-only. */
struct crs_message {
    struct cork_buffer  buf;
    const void  *cursor;
    size_t  remaining_bytes;
};

/* Message starts off write-only */
CORK_LOCAL struct crs_message *
crs_message_new(void);

CORK_LOCAL void
crs_message_free(struct crs_message *msg);

/* Switches a write-only message to read-only mode */
CORK_LOCAL void
crs_message_start_reading(struct crs_message *msg);


#endif  /* CROISSANT_MESSAGE_H */
