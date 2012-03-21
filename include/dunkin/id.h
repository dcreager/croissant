/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2011, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef DUNKIN_ID_H
#define DUNKIN_ID_H

/**
 * @file
 * @brief Implementation of the @ref id module
 */

#include <libcork/core.h>

/**
 * @addtogroup id Node identifiers
 *
 * <tt>#%include \<dunkin/id.h\></tt>
 *
 * Defines some types and functions for handling 128-bit Pastry node
 * identifiers.
 *
 * @{
 */

/**
 * @brief A Pastry node identifier.
 * @since 0.0-dev
 */

struct dunkin_id {
    union {
        uint8_t  u8[20];
        uint32_t  u32[5];
    } _;
};

/**
 * @brief The number of bits in a Pastry identifier.
 * @showinitializer
 * @since 0.0-dev
 */

#define DUNKIN_ID_BIT_LENGTH  160

/**
 * @brief The number of nybbles in a Pastry identifier.
 * @showinitializer
 * @since 0.0-dev
 */

#define DUNKIN_ID_NYBBLE_LENGTH  (DUNKIN_ID_BIT_LENGTH / 4)

/**
 * @brief The minimum size of a buffer that can hold the string
 * representation of a Pastry identifier.
 * @showinitializer
 * @since 0.0-dev
 */

/* includes NUL terminator */
#define DUNKIN_ID_STRING_LENGTH  (DUNKIN_ID_NYBBLE_LENGTH + 1)

/* end of id group */
/**
 * @}
 */


/**
 * @brief Copy a Pastry identifier from some other source.
 * @param [in] ctx  A libcork context
 * @param [out] id  The identifier to initialize
 * @param [in] src  The identifier to copy
 * @public @memberof struct dunkin_id
 * @since 0.0-dev
 */

void
dunkin_id_copy(struct dunkin_id *id, const struct dunkin_id *src);


/**
 * @brief Initialize a Pastry identifier from a string.
 * @param [in] ctx  A libcork context
 * @param [out] id  The identifier to initialize
 * @param [in] src  The string to parse
 * @returns Whether the string contained a valid Pastry identifier.
 * @public @memberof struct dunkin_id
 * @since 0.0-dev
 */

bool
dunkin_id_init(struct dunkin_id *id, const char *src);


/**
 * @brief Render a Pastry identifier as a string.
 * @note You are responsible for ensuring that @a str has at least
 * enough room for @ref DUNKIN_ID_STRING_LENGTH bytes.
 * @param [in] ctx  A libcork context
 * @param [in] id  An identifier
 * @param [out] str  The destination buffer
 * @public @memberof struct dunkin_id
 * @since 0.0-dev
 */

void
dunkin_id_to_raw_string(const struct dunkin_id *id, char *str);


/**
 * @brief Compare two identifiers for equality.
 * @param [in] id1  An identifier
 * @param [in] id2  An identifier
 * @returns Whether the two identifiers are equal.
 * @public @memberof struct dunkin_id
 * @since 0.0-dev
 */

bool
dunkin_id_equals(const struct dunkin_id *id1, const struct dunkin_id *id2);


/**
 * @brief Return the nth nybble of the identifer.
 * @param [in] id  An identifier
 * @param [in] index  The index of the nybble to retrieve
 * @returns The nth nybble of the identifier.
 * @public @memberof struct dunkin_id
 * @since 0.0-dev
 */

#if defined(DUNKIN_DOCUMENTATION)
unsigned int
dunkin_id_get_nybble(const struct dunkin_id *id, const unsigned int index);
#else
#define dunkin_id_get_nybble(id, index) \
    (((index % 2) == 0)? \
     (((id)->_.u8[index/2] & 0xf0) >> 4):  /* an even index */ \
      ((id)->_.u8[index/2] & 0x0f))        /* an odd index */
#endif


/**
 * @brief Return the most-significant different digit (MSDD) between two
 * identifiers.
 * @param [in] id1  An identifier
 * @param [in] id2  An identifier
 * @returns The index of the first digit which is different in the two
 * identifiers, or -1 if the two identifiers are identical.
 * @public @memberof struct dunkin_id
 * @since 0.0-dev
 */

int
dunkin_id_get_msdd(const struct dunkin_id *id1, const struct dunkin_id *id2);


#endif  /* DUNKIN_ID_H */
