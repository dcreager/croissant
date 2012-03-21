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
dunkin_id_copy(struct dunkin_id *id, const struct dunkin_id *src)
{
    memcpy(id, src, sizeof(struct dunkin_id));
}


bool
dunkin_id_init(struct dunkin_id *id, const char *src)
{
    if (src == NULL) {
        return false;
    }

    unsigned int  id_idx = 0;
    unsigned int  str_idx = 0;

    for (id_idx = 0; id_idx < sizeof(struct dunkin_id); id_idx++) {
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
        id->_.u8[id_idx] = (digit << 4);
        str_idx++;
        GET_DIGIT;
        id->_.u8[id_idx] |= digit;
        str_idx++;

#undef GET_DIGIT
    }

    return true;
}


void
dunkin_id_to_raw_string(const struct dunkin_id *id, char *str)
{
    snprintf(str, DUNKIN_ID_STRING_LENGTH,
             "%08" PRIx32 "%08" PRIx32 "%08" PRIx32
             "%08" PRIx32 "%08" PRIx32,
             CORK_UINT32_BIG_TO_HOST(id->_.u32[0]),
             CORK_UINT32_BIG_TO_HOST(id->_.u32[1]),
             CORK_UINT32_BIG_TO_HOST(id->_.u32[2]),
             CORK_UINT32_BIG_TO_HOST(id->_.u32[3]),
             CORK_UINT32_BIG_TO_HOST(id->_.u32[4]));
}


bool
dunkin_id_equals(const struct dunkin_id *id1, const struct dunkin_id *id2)
{
    return
        (id1->_.u32[0] == id2->_.u32[0]) &&
        (id1->_.u32[1] == id2->_.u32[1]) &&
        (id1->_.u32[2] == id2->_.u32[2]) &&
        (id1->_.u32[3] == id2->_.u32[3]) &&
        (id1->_.u32[4] == id2->_.u32[4]);
}


int
dunkin_id_get_msdd(const struct dunkin_id *id1, const struct dunkin_id *id2)
{
    unsigned int  i;
    for (i = 0; i < DUNKIN_ID_NYBBLE_LENGTH; i++) {
        unsigned int  digit1 = dunkin_id_get_nybble(id1, i);
        unsigned int  digit2 = dunkin_id_get_nybble(id2, i);

        if (digit1 != digit2) {
            return i;
        }
    }

    return -1;
}
