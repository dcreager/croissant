/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012-2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef CROISSANT_PARSE_H
#define CROISSANT_PARSE_H

#include <libcork/core.h>
#include <libcork/ds.h>


/*-----------------------------------------------------------------------
 * Decoding
 */

CORK_ATTR_UNUSED
static int
crs_ensure_size(size_t message_length, size_t needed, const char *reason)
{
    if (CORK_UNLIKELY(message_length < needed)) {
        crs_parse_error("Truncated message: need %zu bytes for %s",
                        needed, reason);
        return -1;
    } else {
        return 0;
    }
}

#define crs_define_decoder(type, TYPE) \
CORK_ATTR_UNUSED \
static type##_t \
crs_decode_##type(const void **message, size_t *message_length) \
{ \
    type##_t  result = \
        CORK_##TYPE##_BIG_TO_HOST(*((const type##_t *) *message)); \
    *message += sizeof(type##_t); \
    *message_length -= sizeof(type##_t); \
    return result; \
}

#define CORK_UINT8_BIG_TO_HOST  /* nothing to swap */
crs_define_decoder(uint8, UINT8);
crs_define_decoder(uint16, UINT16);
crs_define_decoder(uint32, UINT32);
crs_define_decoder(uint64, UINT64);


/*-----------------------------------------------------------------------
 * Encoding
 */

#define crs_define_encoder(type, TYPE) \
CORK_ATTR_UNUSED \
static void \
crs_encode_##type(struct cork_buffer *dest, type##_t value) \
{ \
    value = CORK_##TYPE##_HOST_TO_BIG(value); \
    cork_buffer_append(dest, &value, sizeof(type##_t)); \
}

#define CORK_UINT8_HOST_TO_BIG  /* nothing to swap */
crs_define_encoder(uint8, UINT8);
crs_define_encoder(uint16, UINT16);
crs_define_encoder(uint32, UINT32);
crs_define_encoder(uint64, UINT64);


#endif  /* CROISSANT_PARSE_H */
