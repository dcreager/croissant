/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013-2014, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef CROISSANT_APPLICATION_H
#define CROISSANT_APPLICATION_H

#include <libcork/core.h>
#include <libcork/ds.h>

#include "croissant.h"


/*-----------------------------------------------------------------------
 * Applications
 */

struct crs_application {
    crs_application_id  id;
    void  *user_data;
    cork_free_f  free_user_data;
    crs_application_process_f  *process;
};

#define crs_application_process(a, n, s, d, m) \
    ((a)->process((a)->user_data, (n), (s), (d), (m)))


#endif  /* CROISSANT_APPLICATION_H */
