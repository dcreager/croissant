/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013-2014, RedJack, LLC.
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

static crs_application_process_f  crs_save_message__callback;

static int
crs_save_message__callback(void *user_data, struct crs_node *node,
                           crs_id src, crs_id dest,
                           struct crs_message *msg)
{
    struct cork_buffer  *buf = user_data;
    uint32_t  size;
    rii_check(crs_message_decode_uint32(msg, &size, "message size"));
    cork_buffer_ensure_size(buf, size);
    rii_check(crs_message_decode_bytes(msg, buf->buf, size, "message"));
    buf->size = size;
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

struct crs_print_message {
    FILE  *out;
    struct cork_buffer  buf;
};

static int
crs_print_message__callback(void *user_data, struct crs_node *node,
                            crs_id src, crs_id dest,
                            struct crs_message *msg)
{
    struct crs_print_message  *self = user_data;
    cork_buffer_printf
        (&self->buf, "[%s] Received ", crs_node_get_address_str(node));
    crs_id_print(&self->buf, dest);
    cork_buffer_append(&self->buf, " ", 1);
    rii_check(crs_message_decode_buffer_append(msg, &self->buf, "message"));
    cork_buffer_append(&self->buf, "\n", 1);
    fwrite(self->buf.buf, self->buf.size, 1, self->out);
    return 0;
}

static void
crs_print_message__free(void *user_data)
{
    struct crs_print_message  *self = user_data;
    cork_buffer_done(&self->buf);
    free(self);
}

struct crs_application *
crs_print_message_application_new(FILE *out)
{
    struct crs_print_message  *self = cork_new(struct crs_print_message);
    self->out = out;
    cork_buffer_init(&self->buf);
    return crs_application_new
        (CRS_PRINT_MESSAGE_ID,
         self, crs_print_message__free,
         crs_print_message__callback);
}

int
crs_send_print_message(struct crs_node *node, crs_id dest, const char *message)
{
    struct crs_message  *msg;
    msg = crs_node_new_message(node);
    crs_message_encode_application_id(msg, CRS_PRINT_MESSAGE_ID);
    crs_message_encode_string(msg, message);
    return crs_node_send_message(node, dest, msg);
}
