/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012-2014, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef CROISSANT_H
#define CROISSANT_H

#include <libcork/core.h>
#include <libcork/ds.h>


/*-----------------------------------------------------------------------
 * Error handling
 */

#define CRS_EMPTY_LOCAL_NODE_QUEUE    0x3aa8deda
#define CRS_IO_ERROR                  0x0064429b
#define CRS_PARSE_ERROR               0x2c3ff31d

#define crs_empty_local_node_queue(...) \
    cork_error_set_printf(CRS_EMPTY_LOCAL_NODE_QUEUE, __VA_ARGS__)
#define crs_io_error(...) \
    cork_error_set_printf(CRS_IO_ERROR, __VA_ARGS__)
#define crs_parse_error(...) \
    cork_error_set_printf(CRS_PARSE_ERROR, __VA_ARGS__)


/*-----------------------------------------------------------------------
 * Pastry identifiers
 */

#define CRS_ID_BIT_LENGTH  128
#define CRS_ID_NYBBLE_LENGTH  (CRS_ID_BIT_LENGTH / 4)

typedef struct {
    cork_u128  u128;
} crs_id;


#define CRS_ID_ZERO  {{{{0}}}}

crs_id
crs_id_init(const char *src);

/* includes NUL terminator */
#define CRS_ID_STRING_LENGTH  CORK_U128_HEX_LENGTH

const char *
crs_id_to_raw_string(char *str, crs_id id);

void
crs_id_print(struct cork_buffer *dest, crs_id id);

#define crs_id_equals(id1, id2) (cork_u128_eq((id1).u128, (id2).u128))

#define crs_id_get_nybble(id, index) \
    ((((index) % 2) == 0)? \
     ((cork_u128_be8((id).u128, (index) / 2) & 0xf0) >> 4):  /* even index */ \
      (cork_u128_be8((id).u128, (index) / 2) & 0x0f))        /* odd index */

CORK_ATTR_UNUSED
static int
crs_id_get_msdd(crs_id id1, crs_id id2)
{
    unsigned int  i;
    for (i = 0; i < CRS_ID_NYBBLE_LENGTH; i++) {
        unsigned int  digit1 = crs_id_get_nybble(id1, i);
        unsigned int  digit2 = crs_id_get_nybble(id2, i);
        if (digit1 != digit2) {
            return i;
        }
    }
    return -1;
}


/*-----------------------------------------------------------------------
 * Identifier arithmetic
 */

#ifndef CRS_DEBUG_ID_ARITHMETIC
#define CRS_DEBUG_ID_ARITHMETIC  0
#endif

/* Returns if A is clockwise of B (A >= B).  An id is clockwise of itself. */
CORK_ATTR_UNUSED
static bool
crs_id_is_cw(crs_id a, crs_id b)
{
    cork_u128  diff = cork_u128_sub(a.u128, b.u128);
#if CRS_DEBUG_ID_ARITHMETIC
    fprintf(stderr,
            "%016" PRIx64 "%016" PRIx64 " >= "
            "%016" PRIx64 "%016" PRIx64 "\n"
            "%016" PRIx64 "%016" PRIx64 "\n",
            a.u128._.be.hi, a.u128._.be.lo,
            b.u128._.be.hi, b.u128._.be.lo,
            diff._.be.hi, diff._.be.lo);
#endif
    return (cork_u128_be8(diff, 0) < 0x80);
}

/* Returns if A is counter-clockwise of B (A < B).  An id is clockwise of
 * itself. */
CORK_ATTR_UNUSED
static bool
crs_id_is_ccw(crs_id a, crs_id b)
{
    return !crs_id_is_cw(a, b);
}


/* Returns whether A is within [lo, hi] (inclusive). */
CORK_ATTR_UNUSED
static bool
crs_id_is_between(crs_id a, crs_id lo, crs_id hi)
{
    return crs_id_is_cw(a, lo) && crs_id_is_cw(hi, a);
}


/* The shortest distance that you travel on the ring from `a` to `b` */
CORK_ATTR_UNUSED
static cork_u128
crs_id_distance_between(crs_id a, crs_id b)
{
    cork_u128  diff = cork_u128_sub(a.u128, b.u128);
    if (cork_u128_be8(diff, 0) >= 0x80) {
        cork_u128  zero = cork_u128_from_64(0, 0);
        return cork_u128_sub(zero, diff);
    } else {
        return diff;
    }
}

/* The clockwise distance that you travel on the ring from `a` to `b` */
CORK_ATTR_UNUSED
static cork_u128
crs_id_cw_distance_between(crs_id a, crs_id b)
{
    return cork_u128_sub(b.u128, a.u128);
}


/*-----------------------------------------------------------------------
 * Node addresses
 */

struct crs_node_address;

void
crs_node_address_print(struct cork_buffer *dest,
                       const struct crs_node_address *address);

void
crs_node_address_free(const struct crs_node_address *address);

const struct crs_node_address *
crs_node_address_decode(const void *message, size_t message_length);

void
crs_node_address_encode(const struct crs_node_address *address,
                        struct cork_buffer *dest);


/*-----------------------------------------------------------------------
 * Contexts
 */

struct crs_ctx;

struct crs_ctx *
crs_ctx_new(void);

void
crs_ctx_free(struct crs_ctx *ctx);

struct crs_node *
crs_ctx_get_node_with_id(struct crs_ctx *ctx, crs_id id);


/*-----------------------------------------------------------------------
 * Nodes
 */

struct crs_node;

/* Creates a new Pastry node that will listen on the given address.  The node
 * does not belong to any Pastry network yet; you must call crs_node_bootstrap
 * to create a new network or add the node to an existing network.  If address
 * is NULL, this node will only be accessible within the current process.  (This
 * is mostly useful for test cases.) */
struct crs_node *
crs_node_new(struct crs_ctx *ctx, crs_id id,
             const struct crs_node_address *address);

/* If bootstrap_node is NULL, create a new Pastry network with this node as the
 * only member.  Otherwise, add the node to the Pastry network that
 * bootstrap_node belongs to. */
int
crs_node_bootstrap(struct crs_node *node,
                   const struct crs_node_address *bootstrap_node);

/* Detach node from the Pastry network that it belongs to. */
int
crs_node_detach(struct crs_node *node);

crs_id
crs_node_get_id(const struct crs_node *node);

const char *
crs_node_get_id_str(const struct crs_node *node);

const struct crs_node_address *
crs_node_get_address(const struct crs_node *node);

const char *
crs_node_get_address_str(const struct crs_node *node);

int
crs_node_route_message(struct crs_node *node, crs_id src, crs_id dest,
                       const void *message, size_t message_length);

int
crs_node_send_message(struct crs_node *node, crs_id dest,
                      const void *message, size_t message_length);


/*-----------------------------------------------------------------------
 * Node references
 */

#define CRS_NODE_REF_SELF  ((struct crs_node_ref *) (intptr_t) 1)

/* Larger values are "further away" */
typedef unsigned long  crs_proximity;
#define CRS_PROXIMITY_UNKNOWN  LONG_MAX

struct crs_node_ref;

/* Each node maintains its own set of references to other nodes. */

struct crs_node_ref *
crs_node_get_ref(struct crs_node *node);

struct crs_node_ref *
crs_node_new_ref(struct crs_node *owner, crs_id node_id,
                 const struct crs_node_address *address);

crs_id
crs_node_ref_get_id(const struct crs_node_ref *ref);

const const char *
crs_node_ref_get_id_str(const struct crs_node_ref *ref);

const struct crs_node_address *
crs_node_ref_get_address(const struct crs_node_ref *ref);

const const char *
crs_node_ref_get_address_str(const struct crs_node_ref *ref);

crs_proximity
crs_node_ref_get_proximity(const struct crs_node_ref *ref);

void
crs_node_ref_set_proximity(struct crs_node_ref *ref, crs_proximity proximity);

/* This is not the main public function for sending a message.  (For that, use
 * crs_node_send.)  This is used when you want to send a message directly to a
 * particular node that we've already seen and know how to contact.  It is
 * mostly used internally by the message routing functions. */
int
crs_node_ref_send(struct crs_node_ref *ref, crs_id src, crs_id dest,
                  const void *message, size_t message_length);


/*-----------------------------------------------------------------------
 * Routing state
 */

#define CRS_ROUTING_TABLE_BIT_SIZE  4
#define CRS_ROUTING_TABLE_COLUMN_COUNT \
    (1 << CRS_ROUTING_TABLE_BIT_SIZE)
#define CRS_ROUTING_TABLE_ROW_COUNT \
    (CRS_ID_BIT_LENGTH / CRS_ROUTING_TABLE_BIT_SIZE)

struct crs_routing_table;

struct crs_routing_table *
crs_routing_table_new(struct crs_node *node);

void
crs_routing_table_free(struct crs_routing_table *table);

bool
crs_routing_table_has_entry(const struct crs_routing_table *table,
                            unsigned int row, unsigned int column);

struct crs_node_ref *
crs_routing_table_get(const struct crs_routing_table *table,
                      unsigned int row, unsigned int column);

/* id must not be equal to the leaf set's node's ID. */
struct crs_node_ref *
crs_routing_table_get_closest(const struct crs_routing_table *table, crs_id id);

/* id must not be equal to the leaf set's node's ID. */
struct crs_node_ref *
crs_routing_table_get_fallback(const struct crs_routing_table *table,
                               crs_id id);

/* ref's ID must not be equal to the leaf set's node's ID. */
void
crs_routing_table_set(struct crs_routing_table *table,
                      struct crs_node_ref *ref);

void
crs_routing_table_clear(struct crs_routing_table *table,
                        unsigned int row, unsigned int column);

void
crs_routing_table_print(struct cork_buffer *dest,
                        const struct crs_routing_table *table);


/* This is l/2 from the Pastry papers — i.e., the size of one half of the leaf
 * set. */
#define CRS_LEAF_SET_SIZE  16

struct crs_leaf_set;

struct crs_leaf_set *
crs_leaf_set_new(struct crs_node *node);

void
crs_leaf_set_free(struct crs_leaf_set *set);

/* ref must not refer to the local node. */
void
crs_leaf_set_add(struct crs_leaf_set *set, struct crs_node_ref *ref);

/* Returns NULL if id isn't in the range of entries in the leaf set.  Returns
 * CRS_NODE_REF_SELF if the local node is closest. */
struct crs_node_ref *
crs_leaf_set_get_closest(const struct crs_leaf_set *set, crs_id id);

struct crs_node_ref *
crs_leaf_set_get_fallback(const struct crs_leaf_set *set, crs_id id);

void
crs_leaf_set_print(struct cork_buffer *dest, const struct crs_leaf_set *set);


struct crs_leaf_set *
crs_node_get_leaf_set(struct crs_node *node);

struct crs_routing_table *
crs_node_get_routing_table(struct crs_node *node);

struct crs_node_ref *
crs_node_get_next_hop(struct crs_node *node, crs_id key);


/*-----------------------------------------------------------------------
 * Applications
 */

typedef uint32_t  crs_application_id;

typedef int
(*crs_application_process_f)(void *user_data, struct crs_node *node,
                             crs_id src, crs_id dest,
                             const void *message, size_t message_length);


struct crs_application *
crs_application_new(crs_application_id id,
                    void *user_data, cork_free_f free_user_data,
                    crs_application_process_f process);

void
crs_application_free(struct crs_application *app);

/* Takes control of app */
int
crs_node_add_application(struct crs_node *node, struct crs_application *app);


#endif  /* CROISSANT_H */
