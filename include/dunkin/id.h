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

typedef union dunkin_id_t
{
    /**
     * @brief The individual bytes of the identifier.
     *
     * Internally, we always store the identifier in big-endian order.
     *
     * @private
     */

    uint8_t  u8[16];

    /** @brief 64-bit chunks of the identifier. @private */
    uint64_t  u64[2];
} dunkin_id_t;

/**
 * @brief The minimum size of a buffer that can hold the string
 * representation of a Pastry identifier.
 * @showinitializer
 * @since 0.0-dev
 */

#define DUNKIN_ID_STRING_LENGTH  33  /* includes NUL terminator */

/* end of id group */
/**
 * @}
 */


/**
 * @brief Copy a Pastry identifier from some other source.
 * @param [in] ctx  A libcork context
 * @param [out] id  The identifier to initialize
 * @param [in] src  The identifier to copy
 * @public @memberof dunkin_id_t
 * @since 0.0-dev
 */

void
dunkin_id_copy(cork_context_t *ctx, dunkin_id_t *id, const dunkin_id_t *src);


/**
 * @brief Initialize a Pastry identifier from a string.
 * @param [in] ctx  A libcork context
 * @param [out] id  The identifier to initialize
 * @param [in] src  The string to parse
 * @returns Whether the string contained a valid Pastry identifier.
 * @public @memberof dunkin_id_t
 * @since 0.0-dev
 */

bool
dunkin_id_init(cork_context_t *ctx, dunkin_id_t *id, const char *src);


/**
 * @brief Render a Pastry identifier as a string.
 * @note You are responsible for ensuring that @a str has at least
 * enough room for @ref DUNKIN_ID_STRING_LENGTH bytes.
 * @param [in] ctx  A libcork context
 * @param [in] id  An identifier
 * @param [out] str  The destination buffer
 * @public @memberof dunkin_id_t
 * @since 0.0-dev
 */

void
dunkin_id_to_raw_string(cork_context_t *ctx, const dunkin_id_t *id, char *str);


/**
 * @brief Compare two identifiers for equality.
 * @param [in] id1  An identifier
 * @param [in] id2  An identifier
 * @returns Whether the two identifiers are equal.
 * @since 0.0-dev
 */

bool
dunkin_id_equals(const dunkin_id_t *id1, const dunkin_id_t *id2);


#endif  /* DUNKIN_ID_H */
