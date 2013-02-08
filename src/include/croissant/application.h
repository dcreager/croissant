/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013, RedJack, LLC.
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
    crs_application_callback  callback;
    void  *user_data;
};


#endif  /* CROISSANT_APPLICATION_H */
