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
#include <libcork/ds.h>
#include <libcork/helpers/errors.h>

#include "croissant/context.h"
#include "croissant/node.h"


struct crs_context {
    struct cork_hash_table  managers;
};


static enum cork_hash_table_map_result
free_manager(struct cork_hash_table_entry *entry, void *user_data)
{
    struct crs_node_manager  *manager = entry->value;
    crs_node_manager_free(manager);
    return CORK_HASH_TABLE_MAP_DELETE;
}

struct crs_context *
crs_context_new(void)
{
    struct crs_context  *ctx = cork_new(struct crs_context);
    cork_pointer_hash_table_init(&ctx->managers, 0);
    return ctx;
}

void
crs_context_free(struct crs_context *ctx)
{
    cork_hash_table_map(&ctx->managers, free_manager, NULL);
    cork_hash_table_done(&ctx->managers);
    free(ctx);
}

int
crs_context_add_node_manager(struct crs_context *ctx,
                             struct crs_node_manager *manager)
{
    bool  is_new;
    struct cork_hash_table_entry  *entry =
        cork_hash_table_get_or_create
        (&ctx->managers, (void *) (uintptr_t) manager->id, &is_new);

    if (is_new) {
        entry->value = manager;
        return 0;
    } else {
        crs_duplicate_entity
            ("Already have a node manager with ID 0x%08" PRIx32, manager->id);
        crs_node_manager_free(manager);
        return -1;
    }
}

static struct crs_node_manager *
crs_context_get_node_manager(struct crs_context *ctx, crs_node_type_id id)
{
    struct crs_node_manager  *result =
        cork_hash_table_get(&ctx->managers, (void *) (uintptr_t) id);
    if (CORK_UNLIKELY(result == NULL)) {
        crs_unknown_entity("No node manager for type 0x%08" PRIx32, id);
    }
    return result;
}

struct crs_node_ref *
crs_context_decode_address(struct crs_context *ctx, const void *src,
                           size_t size)
{
    struct crs_decode_state  state = CRS_DECODE_STATE_INIT(src, size);
    crs_node_type_id  id;
    struct crs_node_manager  *manager;
    rpi_check(crs_decode_uint32(&state, &id));
    rpp_check(manager = crs_context_get_node_manager(ctx, id));
    return manager->decode_address(manager, crs_decode_state_get(&state));
}
