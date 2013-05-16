/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <string.h>

#include <clogger.h>
#include <libcork/core.h>

#include "croissant.h"
#include "croissant/node.h"

#define CLOG_CHANNEL  "croissant:routing"


/*-----------------------------------------------------------------------
 * Routing tables
 */

#define CRS_ROUTING_TABLE_ENTRY_COUNT \
    (CRS_ROUTING_TABLE_COLUMN_COUNT * CRS_ROUTING_TABLE_ROW_COUNT)

/* A NULL address means that this entry is empty. */
struct crs_routing_table_entry {
    struct crs_node_ref  *ref;
};

struct crs_routing_table {
    struct crs_id  self;
    struct crs_routing_table_entry  entries[CRS_ROUTING_TABLE_ENTRY_COUNT];
};

#define crs_routing_table_get_entry(t, r, c) \
    (&(t)->entries[(r) * CRS_ROUTING_TABLE_COLUMN_COUNT + (c)])


struct crs_routing_table *
crs_routing_table_new(const struct crs_id *id)
{
    struct crs_routing_table  *table = cork_new(struct crs_routing_table);
    memset(table, 0, sizeof(struct crs_routing_table));
    table->self = *id;
    return table;
}

void
crs_routing_table_free(struct crs_routing_table *table)
{
    free(table);
}

bool
crs_routing_table_has_entry(const struct crs_routing_table *table,
                            unsigned int row, unsigned int column)
{
    const struct crs_routing_table_entry  *entry =
        crs_routing_table_get_entry(table, row, column);
    return entry->ref != NULL;
}

struct crs_node_ref *
crs_routing_table_get(const struct crs_routing_table *table,
                      unsigned int row, unsigned int column)
{
    const struct crs_routing_table_entry  *entry =
        crs_routing_table_get_entry(table, row, column);
    return entry->ref;
}

static struct crs_routing_table_entry *
crs_routing_table_get_entry_for_id(struct crs_routing_table *table,
                                   const struct crs_id *id)
{
    int  row = crs_id_get_msdd(&table->self, id);
    if (row >= 0) {
        unsigned int  column = crs_id_get_nybble(id, row);
        return crs_routing_table_get_entry(table, row, column);
    } else {
        return NULL;
    }
}

struct crs_node_ref *
crs_routing_table_get_closest(const struct crs_routing_table *table,
                              const struct crs_id *id)
{
    const struct crs_routing_table_entry  *entry =
        crs_routing_table_get_entry_for_id
        ((struct crs_routing_table *) table, id);
    return (entry == NULL)? NULL: entry->ref;
}

void
crs_routing_table_set(struct crs_routing_table *table,
                      struct crs_node_ref *ref)
{
    struct crs_routing_table_entry  *entry;
    clog_debug("Adding %s to routing table", crs_node_ref_get_id_str(ref));
    entry = crs_routing_table_get_entry_for_id(table, &ref->id);
    if (entry != NULL) {
        if (entry->ref != NULL) {
            /* If there's already a node reference in this entry, then we should
             * keep the reference that's closer to the local process, according
             * to whichever proximity metric is being used. */
            if (entry->ref->proximity <= ref->proximity) {
                clog_debug("Existing node %s is closer",
                           crs_node_ref_get_id_str(entry->ref));
                return;
            } else {
                clog_debug("Replacing node %s",
                           crs_node_ref_get_id_str(entry->ref));
            }
        }
        entry->ref = ref;
    }
}

void
crs_routing_table_clear(struct crs_routing_table *table,
                        unsigned int row, unsigned int column)
{
    struct crs_routing_table_entry  *entry =
        crs_routing_table_get_entry(table, row, column);
    entry->ref = NULL;
}

void
crs_routing_table_print(struct cork_buffer *dest,
                        const struct crs_routing_table *table)
{
    const struct crs_routing_table_entry  *entry = table->entries;
    size_t  r;
    size_t  c;

    for (r = 0; r < CRS_ROUTING_TABLE_ROW_COUNT; r++) {
        for (c = 0; c < CRS_ROUTING_TABLE_COLUMN_COUNT; c++, entry++) {
            if (entry->ref != NULL) {
                cork_buffer_append_printf(dest, "[%2zu/%zx] ", r, c);
                crs_id_print(dest, &entry->ref->id);
                cork_buffer_append(dest, " ", 1);
                crs_node_address_print(dest, &entry->ref->address);
                cork_buffer_append(dest, "\n", 1);
            }
        }
    }
}
