/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012-2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef CROISSANT_NODE_H
#define CROISSANT_NODE_H

#include <libcork/core.h>
#include <libcork/ds.h>

#include "croissant.h"
#include "croissant/local.h"


/*-----------------------------------------------------------------------
 * Node types
 */

/* We support several ways of addressing remote nodes, each with its own
 * communication protocol. */

enum crs_node_type {
    /* A node that can only be accessed from within the current process */
    CRS_NODE_TYPE_LOCAL
};

typedef uint32_t  crs_node_type_id;

#define CRS_NODE_TYPE_ID_LOCAL  0x01d3dfa1  /* "local" */

CORK_LOCAL crs_node_type_id
crs_node_id_for_type(enum crs_node_type type);

CORK_LOCAL enum crs_node_type
crs_node_type_for_id(crs_node_type_id id);


/*-----------------------------------------------------------------------
 * Node addresses
 */

struct crs_node_address {
    enum crs_node_type  type;
    /* All node addresses can have a local ID, regardless of the node type.
     * This lets us address nodes that happen to be in the current process,
     * while still encoding the externally visible address that other machines
     * must use. */
    crs_local_node_id  local_id;
};


/*-----------------------------------------------------------------------
 * Nodes
 */

struct crs_node {
    struct crs_id  id;
    struct crs_node_address  address;
    struct cork_hash_table  applications;
    struct crs_node_ref  *ref;
    struct crs_node  *next;
};

CORK_LOCAL int
crs_node_process_message(struct crs_node *node,
                         const struct crs_id *src, const struct crs_id *dest,
                         const void *message, size_t message_length);


/*-----------------------------------------------------------------------
 * Node references
 */

typedef int
(*crs_node_ref_send_f)(struct crs_node_ref *ref,
                       const struct crs_id *src, const struct crs_id *dest,
                       const void *message, size_t message_length);

struct crs_node_ref {
    struct crs_id  id;
    struct crs_node_address  address;
    crs_proximity  proximity;
    struct crs_node  *local_node;
    void  *user_data;
    cork_free_f  free_user_data;
    crs_node_ref_send_f  send;
    char  id_str[CRS_ID_STRING_LENGTH];
};

CORK_LOCAL struct crs_node_ref *
crs_node_ref_new_priv(const struct crs_id *node_id,
                      const struct crs_node_address *address,
                      crs_proximity proximity,
                      struct crs_node *local_node,
                      void *user_data, cork_free_f free_user_data,
                      crs_node_ref_send_f send);


#endif  /* CROISSANT_NODE_H */
