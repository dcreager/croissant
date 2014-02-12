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

#include <clogger.h>
#include <libcork/core.h>
#include <libcork/ds.h>
#include <libcork/helpers/errors.h>

#include "croissant.h"
#include "croissant/tests.h"

#define CLOG_CHANNEL  "croissant:tests"


/*-----------------------------------------------------------------------
 * Saving messages into a buffer
 */

struct crs_save_message {
    struct crs_application  *app;
    struct cork_buffer  *dest;
};

static crs_application_receive_f  crs_save_message__receive;

static int
crs_save_message__receive(void *user_data, struct crs_node *node,
                          crs_id src, crs_id dest, struct crs_message *msg)
{
    struct crs_save_message  *self = user_data;
    rii_check(crs_message_decode_buffer(msg, self->dest, "message"));
    clog_debug("{save} Received message \"%s\"", (char *) self->dest->buf);
    return 0;
}

static void
crs_save_message__free(void *user_data)
{
    struct crs_save_message  *self = user_data;
    free(self);
}

struct crs_save_message *
crs_save_message_new(crs_application_id id, struct cork_buffer *dest)
{
    struct crs_save_message  *self = cork_new(struct crs_save_message);
    self->dest = dest;
    self->app = crs_application_new(id, "crs_save_message");
    crs_application_set_user_data(self->app, self, crs_save_message__free);
    crs_application_set_receive(self->app, crs_save_message__receive);
    return self;
}

void
crs_save_message_free(struct crs_save_message *self)
{
    crs_application_free(self->app);
}

int
crs_save_message_register(struct crs_save_message *self, struct crs_node *node)
{
    return crs_node_add_application(node, self->app);
}


/*-----------------------------------------------------------------------
 * Printing messages
 */

#define CRS_PRINT_MESSAGE_ID  0x9703f971

struct crs_print_message {
    struct crs_application  *app;
    FILE  *out;
    struct cork_buffer  buf;
};

static int
crs_print_message__intercept(void *user_data, struct crs_node *node,
                             struct crs_node_ref *next_hop,
                             crs_id src, crs_id dest, struct crs_message *msg)
{
    char  src_str[CRS_ID_STRING_LENGTH];
    char  dest_str[CRS_ID_STRING_LENGTH];
    clog_debug("{print} Spy on message from %s to %s",
               crs_id_to_raw_string(src_str, src),
               crs_id_to_raw_string(dest_str, dest));
    return crs_node_ref_forward(next_hop, src, dest, msg);
}

static int
crs_print_message__receive(void *user_data, struct crs_node *node,
                           crs_id src, crs_id dest, struct crs_message *msg)
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

struct crs_print_message *
crs_print_message_new(FILE *out)
{
    struct crs_print_message  *self = cork_new(struct crs_print_message);
    self->out = out;
    cork_buffer_init(&self->buf);
    self->app = crs_application_new(CRS_PRINT_MESSAGE_ID, "crs_print_message");
    crs_application_set_user_data(self->app, self, crs_print_message__free);
    crs_application_set_intercept(self->app, crs_print_message__intercept);
    crs_application_set_receive(self->app, crs_print_message__receive);
    return self;
}

void
crs_print_message_free(struct crs_print_message *self)
{
    crs_application_free(self->app);
}

int
crs_print_message_register(struct crs_print_message *self,
                           struct crs_node *node)
{
    return crs_node_add_application(node, self->app);
}

struct crs_print_message *
crs_print_message_get(struct crs_node *node)
{
    struct crs_application  *app;
    rpp_check(app = crs_node_get_application(node, CRS_PRINT_MESSAGE_ID));
    return crs_application_get_user_data(app);
}

int
crs_print_message_send(struct crs_print_message *self, crs_id dest,
                       const char *message)
{
    struct crs_message  *msg;
    msg = crs_application_new_message(self->app);
    crs_message_encode_string(msg, message);
    return crs_application_send_message(self->app, dest, msg);
}
