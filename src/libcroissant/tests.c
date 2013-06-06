/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <stdio.h>

#include <libcork/core.h>
#include <libcork/ds.h>
#include <libcork/helpers/errors.h>

#include "croissant.h"
#include "croissant/tests.h"


/*-----------------------------------------------------------------------
 * Saving messages into a buffer
 */

static int
crs_save_message__callback(void *user_data, struct crs_node *node,
                           const struct crs_id *src, const struct crs_id *dest,
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


/*-----------------------------------------------------------------------
 * Printing messages
 */

static int
crs_print_message__callback(void *user_data, struct crs_node *node,
                            const struct crs_id *src, const struct crs_id *dest,
                            const void *message, size_t message_length)
{
    struct cork_buffer  *buf = user_data;
    cork_buffer_printf(buf, "[%s] Received ", crs_node_get_address_str(node));
    crs_id_print(buf, dest);
    cork_buffer_append(buf, " ", 1);
    cork_buffer_append(buf, message, message_length);
    cork_buffer_append(buf, "\n", 1);
    fwrite(buf->buf, buf->size, 1, stdout);
    return 0;
}

struct crs_application *
crs_print_message_application_new(void)
{
    struct cork_buffer  *dest = cork_buffer_new();
    return crs_application_new
        (CRS_PRINT_MESSAGE_ID, dest, (cork_free_f) cork_buffer_free,
         crs_print_message__callback);
}

int
crs_send_print_message(struct crs_node *node, const struct crs_id *dest,
                       const char *message)
{
    int  rc;
    struct cork_buffer  buf = CORK_BUFFER_INIT();
    uint32_t  app_id = CORK_UINT32_HOST_TO_BIG(CRS_PRINT_MESSAGE_ID);
    cork_buffer_set(&buf, &app_id, sizeof(uint32_t));
    cork_buffer_append_string(&buf, message);
    rc = crs_node_send_message(node, dest, buf.buf, buf.size);
    cork_buffer_done(&buf);
    return rc;
}
