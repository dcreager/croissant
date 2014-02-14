/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2011-2014, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <stdio.h>

#include <libcork/core.h>

#include "croissant.h"


crs_id
crs_id_init(const char *src)
{
    crs_id  id;
    unsigned int  id_idx = 0;
    unsigned int  str_idx = 0;

    for (id_idx = 0; id_idx < sizeof(crs_id); id_idx++) {
        uint8_t  digit = 0;

#define GET_DIGIT \
        if (CORK_UNLIKELY(src[str_idx] == '\0')) { \
            /* String is too short! */ \
            crs_parse_error("Pastry identifier is too short"); \
            goto error; \
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
            goto error; \
        }

        GET_DIGIT;
        digit <<= 4;
        str_idx++;
        GET_DIGIT;
        cork_u128_be8(id.u128, id_idx) = digit;
        str_idx++;

#undef GET_DIGIT
    }

    if (src[str_idx] != '\0') {
        crs_parse_error("Pastry identifier is too long");
        goto error;
    }

    return id;

error:
    id.u128._.be64.lo = 0;
    id.u128._.be64.hi = 0;
    return id;
}


const char *
crs_id_to_raw_string(char *str, crs_id id)
{
    cork_u128_to_padded_hex(str, id.u128);
    return str;
}

void
crs_id_print(struct cork_buffer *dest, crs_id id)
{
    char  str[CRS_ID_STRING_LENGTH];
    cork_u128_to_padded_hex(str, id.u128);
    cork_buffer_append_string(dest, str);
}

void
crs_id_fprint(FILE *out, crs_id id)
{
    char  str[CRS_ID_STRING_LENGTH];
    cork_u128_to_padded_hex(str, id.u128);
    fputs(str, out);
}


int
crs_id_decode(struct crs_message *msg, crs_id *dest, const char *field_name)
{
    return crs_message_decode_bytes(msg, dest, sizeof(*dest), field_name);
}

void
crs_id_encode(struct crs_message *msg, crs_id id)
{
    crs_message_encode_bytes(msg, &id, sizeof(id));
}
