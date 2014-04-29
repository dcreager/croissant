/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012-2014, RedJack, LLC.
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


/*-----------------------------------------------------------------------
 * Connection types
 */

struct crs_conn_type {
    crs_conn_type_id  id;
    const char  *name;
    void  *user_data;
    cork_free_f  free_user_data;
    crs_node_address_new_f  *new_address;
    cork_free_f  free_address;
    crs_node_address_decode_f  *decode_address;
    crs_node_address_encode_f  *encode_address;
    crs_node_address_parse_f  *parse_address;
    crs_node_address_print_f  *print_address;
    crs_node_bind_f  *bind;
    crs_node_ref_connect_f  *connect;
};


/*-----------------------------------------------------------------------
 * Node addresses
 */

struct crs_node_address {
    void  *user_data;
    struct crs_conn_type  *type;
};

CORK_LOCAL struct crs_node_address *
crs_node_address_new(struct crs_conn_type *type);


/*-----------------------------------------------------------------------
 * Nodes
 */

struct crs_node {
    struct crs_ctx  *ctx;
    crs_id  id;
    struct crs_node_address  *address;
    struct crs_routing_table  *routing_table;
    struct crs_leaf_set  *leaf_set;
    struct crs_maintenance  *maint;
    struct cork_hash_table  *applications;
    struct crs_node_ref  *ref;  /* A reference to the this node */
    struct cork_hash_table  *refs;

    void  *user_data;
    cork_free_f  free_user_data;
    crs_node_detach_f  *detach;

    struct {
        void  *user_data;
        crs_node_ready_f  *ready;
        crs_error_f  *error;
    } bootstrap;

    char  id_str[CRS_ID_STRING_LENGTH];
    struct cork_buffer  address_str;
};

/* Takes control of address */
CORK_LOCAL struct crs_node *
crs_node_new(crs_id id, struct crs_node_address *address);

CORK_LOCAL void
crs_node_bootstrap(struct crs_node *node,
                   struct crs_node_address *bootstrap_address,
                   void *user_data, crs_node_ready_f *ready,
                   crs_error_f *error);

CORK_LOCAL void
crs_node_free(struct crs_node *node);


/*-----------------------------------------------------------------------
 * Node references
 */

struct crs_node_ref {
    struct crs_node  *owner;
    crs_id  id;
    struct crs_node_address  address;
    crs_proximity  proximity;
    bool  bootstrapping;

    void  *user_data;
    cork_free_f  free_user_data;
    crs_node_ref_send_f  *send;

    char  id_str[CRS_ID_STRING_LENGTH];
    struct cork_buffer  address_str;
};

/* Takes control of address */
CORK_LOCAL struct crs_node_ref *
crs_node_ref_new(struct crs_node *owner, crs_id id,
                 struct crs_node_address *address);

/* Takes control of address */
CORK_LOCAL struct crs_node_ref *
crs_node_ref_new_bootstrap(struct crs_node *owner,
                           struct crs_node_address *address);

CORK_LOCAL void
crs_node_ref_free(struct crs_node_ref *ref);


#endif  /* CROISSANT_NODE_H */
