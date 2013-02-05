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

#include "croissant/node.h"


bool
crs_node_ref_equals(const struct crs_node_ref *ref1,
                    const struct crs_node_ref *ref2)
{
    if (CORK_LIKELY(ref1->manager == ref2->manager)) {
        return ref1->manager->ref_equals(ref1, ref2);
    } else {
        return false;
    }
}
