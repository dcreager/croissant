/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013-2014, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the COPYING file in this distribution for license details.
 * ----------------------------------------------------------------------
 */

#include <clogger.h>
#include <libcork/core.h>
#include <libcork/ds.h>
#include <libcork/helpers/errors.h>

#include "croissant.h"
#include "croissant/application.h"
#include "croissant/node.h"

#define CLOG_CHANNEL  "croissant:node"


static int
crs_application__default_intercept(void *user_data, struct crs_node *node,
                                   struct crs_node_ref *next_hop,
                                   crs_id src, crs_id dest,
                                   struct crs_message *msg)
{
    return crs_node_ref_forward(next_hop, src, dest, msg);
}

static int
crs_application__default_receive(void *user_data, struct crs_node *node,
                                 crs_id src, crs_id dest,
                                 struct crs_message *msg)
{
    return 0;
}

struct crs_application *
crs_application_new(crs_application_id id, const char *name)
{
    struct crs_application  *app = cork_new(struct crs_application);
    app->id = id;
    app->name = cork_strdup(name);
    app->node = NULL;
    app->user_data = NULL;
    app->free_user_data = NULL;
    app->intercept = crs_application__default_intercept;
    app->receive = crs_application__default_receive;
    return app;
}

void
crs_application_free(struct crs_application *app)
{
    cork_free_user_data(app);
    cork_strfree(app->name);
    cork_delete(struct crs_application, app);
}

crs_application_id
crs_application_get_id(const struct crs_application *app)
{
    return app->id;
}

const char *
crs_application_get_name(const struct crs_application *app)
{
    return app->name;
}

struct crs_node *
crs_application_get_node(const struct crs_application *app)
{
    return app->node;
}

void *
crs_application_get_user_data(const struct crs_application *app)
{
    return app->user_data;
}

void
crs_application_set_user_data(struct crs_application *app,
                              void *user_data, cork_free_f free_user_data)
{
    cork_free_user_data(app);
    app->user_data = user_data;
    app->free_user_data = free_user_data;
}

void
crs_application_set_intercept(struct crs_application *app,
                              crs_application_intercept_f *intercept)
{
    app->intercept = intercept;
}

void
crs_application_set_receive(struct crs_application *app,
                            crs_application_receive_f *receive)
{
    app->receive = receive;
}


struct crs_message *
crs_application_new_message(struct crs_application *app)
{
    struct crs_message  *msg = crs_node_new_message(app->node);
    crs_message_encode_uint32(msg, app->id);
    return msg;
}

void
crs_application_free_message(struct crs_application *app,
                             struct crs_message *msg)
{
    return crs_node_free_message(app->node, msg);
}

int
crs_application_send_message(struct crs_application *app, crs_id dest,
                             struct crs_message *msg)
{
    return crs_node_send_message(app->node, dest, msg);
}
