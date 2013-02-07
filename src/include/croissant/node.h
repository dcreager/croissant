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
    struct crs_local_message_queue  local_messages;
};


#endif  /* CROISSANT_NODE_H */
