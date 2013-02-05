/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef CROISSANT_PARSING_H
#define CROISSANT_PARSING_H

#include <libcork/core.h>
#include <libcork/ds.h>


/*-----------------------------------------------------------------------
 * Encoding messages
 */

#define crs_define_cursor(name, max_size) \
    struct { \
        size_t  bytes_used; \
        char  buf[max_size]; \
    } name##__cursor = { 0 };

#define crs_message_append_cursor(dest, cursor) \
    cork_buffer_append(dest, cursor##__cursor.buf, cursor##__cursor.bytes_used)

#define crs_encode_type(cursor, var, type, swapper) \
    do { \
        type  __swapped = swapper((var)); \
        memcpy(cursor##__cursor.buf + cursor##__cursor.bytes_used, \
               &__swapped, sizeof(type)); \
        cursor##__cursor.bytes_used += sizeof(type); \
    } while (0)

#define crs_encode_uint8(c, v) \
    crs_encode_type(c, v, uint8_t, /* none */)
#define crs_encode_uint16(c, v) \
    crs_encode_type(c, v, uint16_t, CORK_UINT16_HOST_TO_BIG)
#define crs_encode_uint32(c, v) \
    crs_encode_type(c, v, uint32_t, CORK_UINT32_HOST_TO_BIG)
#define crs_encode_uint64(c, v) \
    crs_encode_type(c, v, uint64_t, CORK_UINT64_HOST_TO_BIG)

#define crs_encode_int8(c, v) \
    crs_encode_type(c, v, int8_t, /* none */)
#define crs_encode_int16(c, v) \
    crs_encode_type(c, v, int16_t, CORK_UINT16_HOST_TO_BIG)
#define crs_encode_int32(c, v) \
    crs_encode_type(c, v, int32_t, CORK_UINT32_HOST_TO_BIG)
#define crs_encode_int64(c, v) \
    crs_encode_type(c, v, int64_t, CORK_UINT64_HOST_TO_BIG)


#endif  /* CROISSANT_PARSING_H */
