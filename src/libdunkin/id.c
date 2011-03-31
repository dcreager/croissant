/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2011, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>

#include <libcork/core.h>

#include "dunkin/id.h"


void
dunkin_id_copy(cork_context_t *ctx, dunkin_id_t *id, const dunkin_id_t *src)
{
    memcpy(id, src, sizeof(dunkin_id_t));
}


bool
dunkin_id_init(cork_context_t *ctx, dunkin_id_t *id, const char *src)
{
    if (src == NULL) {
        return false;
    }

    unsigned int  id_idx = 0;
    unsigned int  str_idx = 0;

    for (id_idx = 0; id_idx < sizeof(dunkin_id_t); id_idx++) {
        uint8_t  digit;

#define GET_DIGIT \
        if (src[str_idx] == '\0') { \
            /* String is too short! */ \
            return false; \
        } \
        \
        if ((src[str_idx] >= '0') && (src[str_idx] <= '9')) { \
            digit = src[str_idx] - '0'; \
        } else if ((src[str_idx] >= 'a') && (src[str_idx] <= 'f')) { \
            digit = src[str_idx] - 'a' + 10; \
        } else if ((src[str_idx] >= 'A') && (src[str_idx] <= 'F')) { \
            digit = src[str_idx] - 'A' + 10; \
        } else { \
            return false; \
        }

        GET_DIGIT;
        id->u8[id_idx] = (digit << 4);
        str_idx++;
        GET_DIGIT;
        id->u8[id_idx] |= digit;
        str_idx++;

#undef GET_DIGIT
    }

    return true;
}


void
dunkin_id_to_raw_string(cork_context_t *ctx, const dunkin_id_t *id, char *str)
{
    snprintf(str, DUNKIN_ID_STRING_LENGTH,
             "%016" PRIx64 "%016" PRIx64,
             CORK_UINT64_BIG_TO_HOST(id->u64[0]),
             CORK_UINT64_BIG_TO_HOST(id->u64[1]));
}


bool
dunkin_id_equals(const dunkin_id_t *id1, const dunkin_id_t *id2)
{
    return (id1->u64[0] == id2->u64[0]) && (id1->u64[1] == id2->u64[1]);
}
