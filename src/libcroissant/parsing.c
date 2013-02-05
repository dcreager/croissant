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
#include <libcork/helpers/errors.h>

#include "croissant/parsing.h"


/*-----------------------------------------------------------------------
 * Decoding messages
 */

static const void *
crs_decode_bytes_priv(struct crs_decode_state *state, size_t size,
                      const char *description)
{
    if (CORK_LIKELY(size <= state->bytes_left)) {
        const void  *result = state->cursor;
        state->cursor += size;
        state->bytes_left -= size;
        return result;
    } else {
        crs_truncated_message
            ("Expected %zu bytes for %s (only have %zu)",
             size, description, state->bytes_left);
        return NULL;
    }
}

const void *
crs_decode_bytes(struct crs_decode_state *state, size_t size,
                 const char *description)
{
    return crs_decode_bytes_priv(state, size, description);
}


#define int_decoder(name, swapper) \
int \
crs_decode_##name(struct crs_decode_state *state, name##_t *dest) \
{ \
    const name##_t  *__val; \
    rip_check(__val = crs_decode_bytes_priv(state, sizeof(name##_t), #name)); \
    *dest = swapper(*__val); \
    return 0; \
}

int_decoder(uint8,  /* nothing to swap */)
int_decoder(uint16, CORK_UINT16_HOST_TO_BIG)
int_decoder(uint32, CORK_UINT32_HOST_TO_BIG)
int_decoder(uint64, CORK_UINT64_HOST_TO_BIG)

int_decoder(int8,  /* nothing to swap */)
int_decoder(int16, CORK_UINT16_HOST_TO_BIG)
int_decoder(int32, CORK_UINT32_HOST_TO_BIG)
int_decoder(int64, CORK_UINT64_HOST_TO_BIG)
