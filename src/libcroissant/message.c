/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2014, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <libcork/core.h>
#include <libcork/helpers/errors.h>

#include "croissant.h"
#include "croissant/message.h"


/*-----------------------------------------------------------------------
 * Messages
 */

CORK_LOCAL struct crs_message *
crs_message_new(void)
{
    struct crs_message  *msg = cork_new(struct crs_message);
    cork_buffer_init(&msg->buf);
    /* Ensure that buf->buf is always non-NULL */
    cork_buffer_ensure_size(&msg->buf, 0);
    msg->cursor = NULL;
    return msg;
}

CORK_LOCAL void
crs_message_free(struct crs_message *msg)
{
    cork_buffer_done(&msg->buf);
    free(msg);
}

CORK_LOCAL void
crs_message_start_reading(struct crs_message *msg)
{
    msg->cursor = msg->buf.buf;
    msg->remaining_bytes = msg->buf.size;
}

void
crs_message_to_buffer(struct cork_buffer *dest, struct crs_message *msg)
{
    cork_buffer_copy(dest, &msg->buf);
}


/*-----------------------------------------------------------------------
 * Decoding messages
 */

static int
crs_message_ensure_size(struct crs_message *msg, size_t required_size,
                        const char *field_name)
{
    if (CORK_UNLIKELY(msg->remaining_bytes < required_size)) {
        crs_parse_error("Truncated message: need %zu bytes for %s",
                        required_size, field_name);
        return -1;
    } else {
        return 0;
    }
}

int
crs_message_decode_bytes(struct crs_message *msg, void *dest, size_t size,
                         const char *field_name)
{
    rii_check(crs_message_ensure_size(msg, size, field_name));
    memcpy(dest, msg->cursor, size);
    msg->cursor += size;
    msg->remaining_bytes -= size;
    return 0;
}

int
crs_message_decode_buffer(struct crs_message *msg, struct cork_buffer *dest,
                          const char *field_name)
{
    uint32_t  size;
    rii_check(crs_message_decode_uint32(msg, &size, field_name));
    cork_buffer_ensure_size(dest, size);
    rii_check(crs_message_decode_bytes(msg, dest->buf, size, field_name));
    dest->size = size;
    return 0;
}

int
crs_message_decode_buffer_append(struct crs_message *msg,
                                 struct cork_buffer *dest, const char *field_name)
{
    void  *buf;
    size_t  old_size = dest->size;
    uint32_t  size;
    rii_check(crs_message_decode_uint32(msg, &size, field_name));
    cork_buffer_ensure_size(dest, old_size + size);
    buf = dest->buf + old_size;
    rii_check(crs_message_decode_bytes(msg, buf, size, field_name));
    dest->size += size;
    return 0;
}

int
crs_message_decode_uint8(struct crs_message *msg, uint8_t *dest,
                         const char *field_name)
{
    rii_check(crs_message_ensure_size(msg, sizeof(*dest), field_name));
    *dest = *((const uint8_t *) msg->cursor);
    msg->cursor += sizeof(*dest);
    msg->remaining_bytes -= sizeof(*dest);
    return 0;
}

int
crs_message_decode_uint16(struct crs_message *msg, uint16_t *dest,
                          const char *field_name)
{
    rii_check(crs_message_ensure_size(msg, sizeof(*dest), field_name));
    *dest = CORK_UINT16_BIG_TO_HOST(*((const uint16_t *) msg->cursor));
    msg->cursor += sizeof(*dest);
    msg->remaining_bytes -= sizeof(*dest);
    return 0;
}

int
crs_message_decode_uint32(struct crs_message *msg, uint32_t *dest,
                          const char *field_name)
{
    rii_check(crs_message_ensure_size(msg, sizeof(*dest), field_name));
    *dest = CORK_UINT32_BIG_TO_HOST(*((const uint32_t *) msg->cursor));
    msg->cursor += sizeof(*dest);
    msg->remaining_bytes -= sizeof(*dest);
    return 0;
}

int
crs_message_decode_uint64(struct crs_message *msg, uint64_t *dest,
                          const char *field_name)
{
    rii_check(crs_message_ensure_size(msg, sizeof(*dest), field_name));
    *dest = CORK_UINT64_BIG_TO_HOST(*((const uint64_t *) msg->cursor));
    msg->cursor += sizeof(*dest);
    msg->remaining_bytes -= sizeof(*dest);
    return 0;
}


/*-----------------------------------------------------------------------
 * Encoding messages
 */

void
crs_message_encode_bytes(struct crs_message *msg,
                         const void *src, size_t size)
{
    cork_buffer_append(&msg->buf, src, size);
}

void
crs_message_encode_buffer(struct crs_message *msg,
                          const struct cork_buffer *src)
{
    crs_message_encode_uint32(msg, src->size);
    cork_buffer_append_copy(&msg->buf, src);
}

void
crs_message_encode_string(struct crs_message *msg, const char *str)
{
    uint32_t  size = strlen(str);
    crs_message_encode_uint32(msg, size);
    cork_buffer_append(&msg->buf, str, size);
}

void
crs_message_encode_uint8(struct crs_message *msg, uint8_t src)
{
    cork_buffer_append(&msg->buf, &src, sizeof(src));
}

void
crs_message_encode_uint16(struct crs_message *msg, uint16_t src)
{
    CORK_UINT16_HOST_TO_BIG_IN_PLACE(src);
    cork_buffer_append(&msg->buf, &src, sizeof(src));
}

void
crs_message_encode_uint32(struct crs_message *msg, uint32_t src)
{
    CORK_UINT32_HOST_TO_BIG_IN_PLACE(src);
    cork_buffer_append(&msg->buf, &src, sizeof(src));
}

void
crs_message_encode_uint64(struct crs_message *msg, uint64_t src)
{
    CORK_UINT64_HOST_TO_BIG_IN_PLACE(src);
    cork_buffer_append(&msg->buf, &src, sizeof(src));
}

void
crs_message_encode_application_id(struct crs_message *msg,
                                  crs_application_id id)
{
    CORK_UINT32_HOST_TO_BIG_IN_PLACE(id);
    cork_buffer_append(&msg->buf, &id, sizeof(id));
}
