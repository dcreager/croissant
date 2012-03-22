/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2011-2012, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef CROISSANT_ID_H
#define CROISSANT_ID_H

#include <string.h>

#include <libcork/core.h>


struct crs_id {
    union {
        uint8_t  u8[20];
        uint32_t  u32[5];
    } _;
};


#define CRS_ID_BIT_LENGTH  160
#define CRS_ID_NYBBLE_LENGTH  (CRS_ID_BIT_LENGTH / 4)

/* includes NUL terminator */
#define CRS_ID_STRING_LENGTH  (CRS_ID_NYBBLE_LENGTH + 1)


bool
crs_id_init(struct crs_id *id, const char *src);

#define crs_id_copy(id, src) \
    (memcpy((id), (src), sizeof(struct crs_id)))


void
crs_id_to_raw_string(const struct crs_id *id, char *str);


#define crs_id_equals(id1, id2) \
    (memcmp((id1), (id2), sizeof(struct crs_id)) == 0)

#define crs_id_get_nybble(id, index) \
    (((index % 2) == 0)? \
     (((id)->_.u8[index/2] & 0xf0) >> 4):  /* an even index */ \
      ((id)->_.u8[index/2] & 0x0f))        /* an odd index */


int
crs_id_get_msdd(const struct crs_id *id1, const struct crs_id *id2);


#endif  /* CROISSANT_ID_H */
