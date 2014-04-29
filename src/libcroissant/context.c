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

#include "croissant.h"
#include "croissant/context.h"
#include "croissant/node.h"


/*-----------------------------------------------------------------------
 * Contexts
 */

struct crs_ctx {
    struct cork_hash_table  *types_by_name;
    struct cork_hash_table  *types_by_id;
};

struct crs_ctx *
crs_ctx_new(void)
{
    struct crs_ctx  *ctx = cork_new(struct crs_ctx);
    ctx->types_by_name = cork_string_hash_table_new(0, 0);
    ctx->types_by_id = cork_pointer_hash_table_new(0, 0);
    cork_hash_table_set_free_value
        (ctx->types_by_id, (cork_free_f) crs_conn_type_free);
    return ctx;
}

void
crs_ctx_free(struct crs_ctx *ctx)
{
    cork_hash_table_free(ctx->types_by_name);
    cork_hash_table_free(ctx->types_by_id);
    free(ctx);
}

void
crs_ctx_add_conn_type(struct crs_ctx *ctx, struct crs_conn_type *type)
{
    cork_hash_table_put
        (ctx->types_by_name, (void *) type->name, type, NULL, NULL, NULL);
    cork_hash_table_put_hash
        (ctx->types_by_id, (cork_hash) type->id,
         (void *) (uintptr_t) type->id, type, NULL, NULL, NULL);
}

CORK_LOCAL struct crs_node_address *
crs_ctx_decode_node_address(struct crs_message *msg, struct crs_ctx *ctx,
                            const char *field_name)
{
    crs_conn_type_id  id;
    struct crs_conn_type  *type;
    rii_check(crs_message_decode_uint32(msg, &id, "address type"));
    type = cork_hash_table_get_hash
        (ctx->types_by_id, (cork_hash) id, (void *) (uintptr_t) id);
    if (CORK_UNLIKELY(type == NULL)) {
        crs_parse_error("Unknown address type 0x%08" PRIx32, id);
        return NULL;
    } else {
        int  rc;
        struct crs_node_address  *address = crs_node_address_new(type);
        rc = type->decode_address(address->user_data, msg, "address");
        if (CORK_LIKELY(rc == 0)) {
            return address;
        } else {
            crs_node_address_free(address);
            return NULL;
        }
    }
}

CORK_LOCAL struct crs_node_address *
crs_ctx_parse_node_address(struct crs_ctx *ctx, const char *str)
{
    struct cork_buffer  buf = CORK_BUFFER_INIT();
    char  *type_name;
    char  *colon;
    char  *address_detail;
    struct crs_conn_type  *type;

    cork_buffer_set_string(&buf, str);
    colon = strchr(buf.buf, ':');
    if (CORK_UNLIKELY(colon == NULL)) {
        cork_buffer_done(&buf);
        crs_parse_error("Missing address type");
        return NULL;
    }

    type_name = buf.buf;
    *colon = '\0';
    address_detail = colon + 1;

    type = cork_hash_table_get(ctx->types_by_name, type_name);
    if (CORK_UNLIKELY(type == NULL)) {
        cork_buffer_done(&buf);
        crs_parse_error("Unknown address type %s", type_name);
        return NULL;
    } else {
        int  rc;
        struct crs_node_address  *address = crs_node_address_new(type);
        rc = type->parse_address(address->user_data, address_detail);
        if (CORK_LIKELY(rc == 0)) {
            cork_buffer_done(&buf);
            return address;
        } else {
            cork_buffer_done(&buf);
            crs_node_address_free(address);
            return NULL;
        }
    }
}
