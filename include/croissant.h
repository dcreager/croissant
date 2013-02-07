/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012-2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef CROISSANT_H
#define CROISSANT_H

#include <string.h>

#include <libcork/core.h>
#include <libcork/ds.h>


/*-----------------------------------------------------------------------
 * Error handling
 */

/* hash of "crossaint.h" */
#define CRS_ERROR  0x60b9b93f

enum crs_error {
    /* No messages */
    CRS_EMPTY_LOCAL_NODE_QUEUE,
    /* A parse error while parsing an identifier. */
    CRS_ID_PARSE_ERROR,
    /* A transmission error while sending or receiving a message. */
    CRS_IO_ERROR,
    /* An unknown error */
    CRS_UNKNOWN_ERROR
};

#define crs_set_error(code, ...)  cork_error_set(CRS_ERROR, code, __VA_ARGS__)
#define crs_empty_local_node_queue(...) \
    crs_set_error(CRS_EMPTY_LOCAL_NODE_QUEUE, __VA_ARGS__)
#define crs_id_parse_error(...) \
    crs_set_error(CRS_ID_PARSE_ERROR, __VA_ARGS__)
#define crs_io_error(...) \
    crs_set_error(CRS_IO_ERROR, __VA_ARGS__)
#define crs_unknown_error(...) \
    crs_set_error(CRS_UNKNOWN_ERROR, __VA_ARGS__)


/*-----------------------------------------------------------------------
 * Pastry identifiers
 */

#define CRS_ID_BIT_LENGTH  128
#define CRS_ID_NYBBLE_LENGTH  (CRS_ID_BIT_LENGTH / 4)

struct crs_id {
    union {
        uint8_t  u8[CRS_ID_BIT_LENGTH / 8];
        uint32_t  u32[CRS_ID_BIT_LENGTH / 32];
    } _;
};


int
crs_id_init(struct crs_id *id, const char *src);

#define crs_id_copy(id, src) \
    (memcpy((id), (src), sizeof(struct crs_id)))

/* includes NUL terminator */
#define CRS_ID_STRING_LENGTH  (CRS_ID_NYBBLE_LENGTH + 1)

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


/*-----------------------------------------------------------------------
 * Node addresses
 */

struct crs_node_address;

void
crs_node_address_print(const struct crs_node_address *address,
                       struct cork_buffer *dest);

void
crs_node_address_free(const struct crs_node_address *address);


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
crs_node_new(const struct crs_node_address *address);

/* The node should not belong to a Pastry network; you should call
 * crs_node_detach to remove the node from its network before freeing it. */
void
crs_node_free(struct crs_node *node);

/* If bootstrap_node is NULL, create a new Pastry network with this node as the
 * only member.  Otherwise, add the node to the Pastry network that
 * bootstrap_node belongs to. */
int
crs_node_bootstrap(struct crs_node *node,
                   const struct crs_node_address *bootstrap_node);

/* Detach node from the Pastry network that it belongs to. */
int
crs_node_detach(struct crs_node *node);

const struct crs_id *
crs_node_get_id(struct crs_node *node);

const struct crs_node_address *
crs_node_get_address(struct crs_node *node);


int
crs_node_send_message(const struct crs_node_address *dest,
                      const void *message, size_t message_length);


#endif  /* CROISSANT_H */
