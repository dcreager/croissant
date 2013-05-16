/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <libcork/core.h>
#include <libcork/ds.h>
#include <libcork/helpers/errors.h>

#include "croissant.h"


static int
crs_save_message__callback(void *user_data,
                           const struct crs_id *src, struct crs_node *dest,
                           const void *message, size_t message_length)
{
    struct cork_buffer  *buf = user_data;
    cork_buffer_set(buf, message, message_length);
    return 0;
}

struct crs_application *
crs_save_message_application_new(crs_application_id id,
                                 struct cork_buffer *dest)
{
    return crs_application_new(id, dest, NULL, crs_save_message__callback);
}
