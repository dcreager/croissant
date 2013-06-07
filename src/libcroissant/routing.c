/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <assert.h>
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

/* A NULL ref means that this entry is empty. */
struct crs_routing_table_entry {
    struct crs_node_ref  *ref;
};

struct crs_routing_table {
    struct crs_node  *node;
    struct crs_routing_table_entry  entries[CRS_ROUTING_TABLE_ENTRY_COUNT];
};

#define crs_routing_table_get_entry(t, r, c) \
    (&(t)->entries[(r) * CRS_ROUTING_TABLE_COLUMN_COUNT + (c)])


struct crs_routing_table *
crs_routing_table_new(struct crs_node *node)
{
    struct crs_routing_table  *table = cork_new(struct crs_routing_table);
    memset(table, 0, sizeof(struct crs_routing_table));
    table->node = node;
    clog_debug("[%s] New routing table", crs_node_get_address_str(node));
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
crs_routing_table_get_entry_for_id(struct crs_routing_table *table, crs_id id,
                                   int *row_out, unsigned int *column_out)
{
    int  row;
    unsigned int  column;
    assert(!crs_id_equals(table->node->id, id));
    row = crs_id_get_msdd(table->node->id, id);
    column = crs_id_get_nybble(id, row);
    if (row_out != NULL) {
        *row_out = row;
    }
    if (column_out != NULL) {
        *column_out = column;
    }
    return crs_routing_table_get_entry(table, row, column);
}

struct crs_node_ref *
crs_routing_table_get_closest(const struct crs_routing_table *table, crs_id id)
{
    const struct crs_routing_table_entry  *entry =
        crs_routing_table_get_entry_for_id
        ((struct crs_routing_table *) table, id, NULL, NULL);
    return (entry == NULL)? NULL: entry->ref;
}

struct crs_node_ref *
crs_routing_table_get_fallback(const struct crs_routing_table *table, crs_id id)
{
    unsigned int  i;
    int  local_msdd = crs_id_get_msdd(table->node->id, id);
    cork_u128  local_distance = crs_id_distance_between(table->node->id, id);
    for (i = 0; i < CRS_ROUTING_TABLE_ENTRY_COUNT; i++) {
        struct crs_node_ref  *curr = table->entries[i].ref;
        if (curr != NULL) {
            int  curr_msdd = crs_id_get_msdd(curr->id, id);
            cork_u128  curr_distance = crs_id_distance_between(curr->id, id);
            if (curr_msdd >= local_msdd &&
                cork_u128_lt(curr_distance, local_distance)) {
                return curr;
            }
        }
    }
    return NULL;
}

void
crs_routing_table_set(struct crs_routing_table *table,
                      struct crs_node_ref *ref)
{
    struct crs_routing_table_entry  *entry;
    int  r;
    unsigned int  c;
    entry = crs_routing_table_get_entry_for_id(table, ref->id, &r, &c);
    if (entry != NULL) {
        clog_debug("[%s] (rtable) [%2d/%hx] %s",
                   crs_node_get_address_str(table->node),
                   r, c, crs_node_ref_get_id_str(ref));
        if (entry->ref != NULL) {
            /* If there's already a node reference in this entry, then we should
             * keep the reference that's closer to the local process, according
             * to whichever proximity metric is being used. */
            if (entry->ref->proximity <= ref->proximity) {
                clog_debug("[%s] (rtable) [%2d/%x] %s is closer",
                           crs_node_get_address_str(table->node),
                           r, c, crs_node_ref_get_id_str(entry->ref));
                return;
            } else {
                clog_debug("[%s] (rtable) [%2d/%x] %s replaced",
                           crs_node_get_address_str(table->node),
                           r, c, crs_node_ref_get_id_str(entry->ref));
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
    unsigned int  r;
    unsigned int  c;

    for (r = 0; r < CRS_ROUTING_TABLE_ROW_COUNT; r++) {
        for (c = 0; c < CRS_ROUTING_TABLE_COLUMN_COUNT; c++, entry++) {
            if (entry->ref != NULL) {
                cork_buffer_append_printf(dest,
                    "[%2u/%x] %s %s\n",
                    r, c,
                    crs_node_ref_get_id_str(entry->ref),
                    crs_node_ref_get_address_str(entry->ref)
                );
            }
        }
    }
}


/*-----------------------------------------------------------------------
 * Leaf sets
 */

/* A NULL ref means that this entry is empty. */
struct crs_leaf_set_entry {
    struct crs_node_ref  *ref;
};

struct crs_leaf_set {
    struct crs_node  *node;
    /* The ID of the last entries in below and above */
    crs_id  below_least;
    crs_id  above_most;
    /* The entries in `below` are stored in reverse order, so that for both
     * fields, entry #0 is the one closest to the node, and any empty entries
     * are at the end of the array. */
    struct crs_leaf_set_entry  below[CRS_LEAF_SET_SIZE];
    struct crs_leaf_set_entry  above[CRS_LEAF_SET_SIZE];
};

struct crs_leaf_set *
crs_leaf_set_new(struct crs_node *node)
{
    struct crs_leaf_set  *set = cork_new(struct crs_leaf_set);
    memset(set, 0, sizeof(struct crs_leaf_set));
    set->node = node;
    set->below_least = node->id;
    set->above_most = node->id;
    clog_debug("[%s] New leaf set", crs_node_get_address_str(node));
    return set;
}

void
crs_leaf_set_free(struct crs_leaf_set *set)
{
    free(set);
}


static void
crs_leaf_set_add_below(struct crs_leaf_set *set, struct crs_node_ref *ref)
{
    unsigned int  i;
    unsigned int  j;
    cork_u128  ref_dist = crs_id_cw_distance_between(ref->id, set->node->id);

    /* Find the first entry that is further away from the local node than ref */
    for (i = 0; i < CRS_LEAF_SET_SIZE; i++) {
        struct crs_node_ref  *curr = set->below[i].ref;
        cork_u128  curr_dist;

        if (curr == NULL) {
            /* We've reached the end of the array, and the array is not full, so
             * just insert the new element here. */
            clog_debug("[%s] (leafset) [-%2u] Add %s",
                       crs_node_get_address_str(set->node),
                       i+1, crs_node_ref_get_id_str(ref));
            set->below[i].ref = ref;
            set->below_least = ref->id;
            return;
        }

        curr_dist = crs_id_cw_distance_between(curr->id, set->node->id);
        if (cork_u128_ge(curr_dist, ref_dist)) {
            clog_debug("[%s] (leafset) [-%2u] Found spot for %s",
                       crs_node_get_address_str(set->node),
                       i+1, crs_node_ref_get_id_str(ref));
            break;
        }
    }

    /* We now have the index of where the new reference should go.  Bubble up
     * any remaining elements to make room for the new one. */
    set->below_least = set->node->id;
    for (j = CRS_LEAF_SET_SIZE; --j > i; ) {
        struct crs_node_ref  *bubble = set->below[j-1].ref;
        set->below[j].ref = bubble;
        if (bubble != NULL) {
            clog_debug("[%s] (leafset) [-%2u] Bubble down %s",
                       crs_node_get_address_str(set->node),
                       j+1, crs_node_ref_get_id_str(bubble));
            if (crs_id_is_cw(set->below_least, bubble->id)) {
                set->below_least = bubble->id;
            }
        }
    }

    if (i == CRS_LEAF_SET_SIZE) {
        /* We ran out of space in the array. */
        clog_debug("[%s] (leafset)       Skip %s",
                   crs_node_get_address_str(set->node),
                   crs_node_ref_get_id_str(ref));
    } else {
        clog_debug("[%s] (leafset) [-%2u] Add %s",
                   crs_node_get_address_str(set->node),
                   i+1, crs_node_ref_get_id_str(ref));
        set->below[i].ref = ref;
        if (crs_id_is_cw(set->below_least, ref->id)) {
            set->below_least = ref->id;
        }
    }
}

static void
crs_leaf_set_add_above(struct crs_leaf_set *set, struct crs_node_ref *ref)
{
    unsigned int  i;
    unsigned int  j;
    cork_u128  ref_dist = crs_id_cw_distance_between(set->node->id, ref->id);

    /* Find the first entry that is <= the new reference. */
    for (i = 0; i < CRS_LEAF_SET_SIZE; i++) {
        struct crs_node_ref  *curr = set->above[i].ref;
        cork_u128  curr_dist;

        if (curr == NULL) {
            /* We've reached the end of the array, and the array is not full, so
             * just insert the new element here. */
            clog_debug("[%s] (leafset) [+%2u] Add %s",
                       crs_node_get_address_str(set->node),
                       i+1, crs_node_ref_get_id_str(ref));
            set->above[i].ref = ref;
            set->above_most = ref->id;
            return;
        }

        curr_dist = crs_id_cw_distance_between(set->node->id, curr->id);
        if (cork_u128_ge(curr_dist, ref_dist)) {
            clog_debug("[%s] (leafset) [+%2u] Found spot for %s",
                       crs_node_get_address_str(set->node),
                       i+1, crs_node_ref_get_id_str(ref));
            break;
        }
    }

    /* We now have the index of where the new reference should go.  Bubble up
     * any remaining elements to make room for the new one. */
    set->above_most = set->node->id;
    for (j = CRS_LEAF_SET_SIZE; --j > i; ) {
        struct crs_node_ref  *bubble = set->above[j-1].ref;
        set->above[j].ref = bubble;
        if (bubble != NULL) {
            clog_debug("[%s] (leafset) [+%2u] Bubble up %s",
                       crs_node_get_address_str(set->node),
                       j+1, crs_node_ref_get_id_str(bubble));
            if (crs_id_is_cw(bubble->id, set->above_most)) {
                set->above_most = bubble->id;
            }
        }
    }

    if (i == CRS_LEAF_SET_SIZE) {
        /* We ran out of space in the array. */
        clog_debug("[%s] (leafset)       Skip %s",
                   crs_node_get_address_str(set->node),
                   crs_node_ref_get_id_str(ref));
    } else {
        clog_debug("[%s] (leafset) [+%2u] Add %s",
                   crs_node_get_address_str(set->node),
                   i+1, crs_node_ref_get_id_str(ref));
        set->above[i].ref = ref;
        if (crs_id_is_cw(ref->id, set->above_most)) {
            set->above_most = ref->id;
        }
    }
}

void
crs_leaf_set_add(struct crs_leaf_set *set, struct crs_node_ref *ref)
{
    assert(!crs_id_equals(ref->id, set->node->id));
    /* Try to insert the new node into one of the arrays, depending on whether
     * the new ID is larger or smaller than the local node's. */
    if (crs_id_is_cw(ref->id, set->node->id)) {
        crs_leaf_set_add_above(set, ref);
    } else {
        crs_leaf_set_add_below(set, ref);
    }
}

/* Returns NULL if id is the same as the routing table's id, or if id isn't in
 * the range of entries in the leaf set. */
struct crs_node_ref *
crs_leaf_set_get_closest(const struct crs_leaf_set *set, crs_id id)
{
    unsigned int  i;
    const struct crs_leaf_set_entry  *array;
    struct crs_node_ref  *closest;
    cork_u128  distance;

    /* First make sure that the requested node is in range of the set. */
    if (!crs_id_is_between(id, set->below_least, set->above_most)) {
        return NULL;
    }

    /* Choose which array to check based on the requested node ID. */
    if (crs_id_is_cw(id, set->node->id)) {
        array = set->above;
    } else {
        array = set->below;
    }

    /* We need to search through the array looking for the node reference that
     * is closest to `id`.  Because the arrays are sorted by the distance from
     * the local node (i.e., the `below` array is in reverse order), we can use
     * the same for loop regardless of which array we need to search through.
     *
     * The arrays are small enough that we're going to do a simple, naive linear
     * search for now.  If profiling says we should switch to something more
     * complex, then we'll update this. */

    /* Start by assuming the local node is closest. */
    closest = CRS_NODE_REF_SELF;
    distance = crs_id_distance_between(id, set->node->id);

    for (i = 0; i < CRS_LEAF_SET_SIZE; i++) {
        struct crs_node_ref  *curr = array[i].ref;
        cork_u128  curr_distance;

        if (curr == NULL) {
            /* We've reached the end of the array. */
            return closest;
        }

        curr_distance = crs_id_distance_between(id, curr->id);
        if (cork_u128_gt(curr_distance, distance)) {
            /* Because of how the arrays are sorted, once we encounter a node
             * that is further away than the closest one we've seen so far, then
             * none of the ones later in the array could possibly be closer, so
             * we can abort processing. */
            return closest;
        } else if (cork_u128_eq(curr_distance, distance)) {
            /* If `id` is perfectly centered between two nodes, we return the
             * one that is further clockwise.  If we're searching the `above`
             * array, that's the node we encountered second; if we're searching
             * `below`, it's the node we encountered first. */
            if (array == set->below) {
                return closest;
            } else {
                return curr;
            }
        } else {
            closest = curr;
            distance = curr_distance;
        }
    }

    /* If we fall through the loop, then the final entry in the array is the
     * closest. */
    return closest;
}

struct crs_node_ref *
crs_leaf_set_get_fallback(const struct crs_leaf_set *set, crs_id id)
{
    unsigned int  i;
    int  local_msdd = crs_id_get_msdd(set->node->id, id);
    cork_u128  local_distance = crs_id_distance_between(set->node->id, id);
    for (i = 0; i < CRS_LEAF_SET_SIZE; i++) {
        struct crs_node_ref  *curr = set->below[i].ref;
        if (curr != NULL) {
            int  curr_msdd = crs_id_get_msdd(curr->id, id);
            cork_u128  curr_distance = crs_id_distance_between(curr->id, id);
            if (curr_msdd >= local_msdd &&
                cork_u128_lt(curr_distance, local_distance)) {
                return curr;
            }
        }
    }
    for (i = 0; i < CRS_LEAF_SET_SIZE; i++) {
        struct crs_node_ref  *curr = set->above[i].ref;
        if (curr != NULL) {
            int  curr_msdd = crs_id_get_msdd(curr->id, id);
            cork_u128  curr_distance = crs_id_distance_between(curr->id, id);
            if (curr_msdd >= local_msdd &&
                cork_u128_lt(curr_distance, local_distance)) {
                return curr;
            }
        }
    }
    return NULL;
}

void
crs_leaf_set_print(struct cork_buffer *dest, const struct crs_leaf_set *set)
{
    unsigned int  i;
    cork_buffer_append(dest, "[min] ", 6);
    crs_id_print(dest, set->below_least);
    cork_buffer_append(dest, "\n", 1);
    for (i = CRS_LEAF_SET_SIZE; i-- > 0; ) {
        struct crs_node_ref  *ref = set->below[i].ref;
        if (ref != NULL) {
            cork_buffer_append_printf(dest,
                "[-%2u] %s %s\n",
                i+1,
                crs_node_ref_get_id_str(ref),
                crs_node_ref_get_address_str(ref)
            );
        }
    }
    cork_buffer_append_printf(dest,
        "[  0] %s %s\n",
        crs_node_get_id_str(set->node),
        crs_node_get_address_str(set->node)
    );
    for (i = 0; i < CRS_LEAF_SET_SIZE; i++) {
        struct crs_node_ref  *ref = set->above[i].ref;
        if (ref != NULL) {
            cork_buffer_append_printf(dest,
                "[+%2u] %s %s\n",
                i+1,
                crs_node_ref_get_id_str(ref),
                crs_node_ref_get_address_str(ref)
            );
        }
    }
    cork_buffer_append(dest, "[max] ", 6);
    crs_id_print(dest, set->above_most);
    cork_buffer_append(dest, "\n", 1);
}
