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
 * Error handling
 */

/* hash of "crossaint/parsing.h" */
#define CRS_PARSE_ERROR  0x278ade13

enum crs_parse_error {
    /* Invalid message content */
    CRS_INVALID_MESSAGE,
    /* Ran out of space */
    CRS_TRUNCATED_MESSAGE
};

#define crs_set_parse_error(code, ...) \
    (cork_error_set(CRS_PARSE_ERROR, code, __VA_ARGS__))
#define crs_invalid_message(...) \
    crs_set_parse_error(CRS_INVALID_MESSAGE, __VA_ARGS__)
#define crs_truncated_message(...) \
    crs_set_parse_error(CRS_TRUNCATED_MESSAGE, __VA_ARGS__)


/*-----------------------------------------------------------------------
 * Decoding messages
 */

struct crs_decode_state {
    const void  *cursor;
    size_t  bytes_left;
};

#define CRS_DECODE_STATE_INIT(src, size)  { src, size }


const void *
crs_decode_bytes(struct crs_decode_state *state, size_t size,
                 const char *description);


int
crs_decode_uint8(struct crs_decode_state *state, uint8_t *dest);

int
crs_decode_uint16(struct crs_decode_state *state, uint16_t *dest);

int
crs_decode_uint32(struct crs_decode_state *state, uint32_t *dest);

int
crs_decode_uint64(struct crs_decode_state *state, uint64_t *dest);


int
crs_decode_int8(struct crs_decode_state *state, int8_t *dest);

int
crs_decode_int16(struct crs_decode_state *state, int16_t *dest);

int
crs_decode_int32(struct crs_decode_state *state, int32_t *dest);

int
crs_decode_int64(struct crs_decode_state *state, int64_t *dest);


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
