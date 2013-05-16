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
#include "croissant/application.h"


struct crs_application *
crs_application_new(crs_application_id id,
                    void *user_data, cork_free_f free_user_data,
                    crs_application_process_f process)
{
    struct crs_application  *app = cork_new(struct crs_application);
    app->id = id;
    app->user_data = user_data;
    app->free_user_data = free_user_data;
    app->process = process;
    return app;
}

void
crs_application_free(struct crs_application *app)
{
    cork_free_user_data(app);
    free(app);
}
