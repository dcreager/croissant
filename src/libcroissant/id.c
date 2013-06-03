/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2011-2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <stdio.h>

#include <libcork/core.h>

#include "croissant.h"


int
crs_id_init(struct crs_id *id, const char *src)
{
    unsigned int  id_idx = 0;
    unsigned int  str_idx = 0;

    for (id_idx = 0; id_idx < sizeof(struct crs_id); id_idx++) {
        uint8_t  digit = 0;

#define GET_DIGIT \
        if (CORK_UNLIKELY(src[str_idx] == '\0')) { \
            /* String is too short! */ \
            crs_parse_error("Pastry identifier is too short"); \
            return -1; \
        } \
        \
        if ((src[str_idx] >= '0') && (src[str_idx] <= '9')) { \
            digit |= src[str_idx] - '0'; \
        } else if ((src[str_idx] >= 'a') && (src[str_idx] <= 'f')) { \
            digit |= src[str_idx] - 'a' + 10; \
        } else if ((src[str_idx] >= 'A') && (src[str_idx] <= 'F')) { \
            digit |= src[str_idx] - 'A' + 10; \
        } else { \
            crs_parse_error \
                ("Pastry identifier contains invalid character " \
                 "'%c' at position %u", src[str_idx], str_idx); \
            return -1; \
        }

        GET_DIGIT;
        digit <<= 4;
        str_idx++;
        GET_DIGIT;
        cork_u128_be8(id->u128, id_idx) = digit;
        str_idx++;

#undef GET_DIGIT
    }

    if (src[str_idx] != '\0') {
        crs_parse_error("Pastry identifier is too long");
        return -1;
    }

    return 0;
}


const char *
crs_id_to_raw_string(const struct crs_id *id, char *str)
{
    cork_u128_to_padded_hex(str, id->u128);
    return str;
}

void
crs_id_print(struct cork_buffer *dest, const struct crs_id *id)
{
    char  str[CRS_ID_STRING_LENGTH];
    crs_id_to_raw_string(id, str);
    cork_buffer_append_string(dest, str);
}


int
crs_id_get_msdd(const struct crs_id *id1, const struct crs_id *id2)
{
    unsigned int  i;
    for (i = 0; i < CRS_ID_NYBBLE_LENGTH; i++) {
        unsigned int  digit1 = crs_id_get_nybble(id1, i);
        unsigned int  digit2 = crs_id_get_nybble(id2, i);

        if (digit1 != digit2) {
            return i;
        }
    }

    return -1;
}
