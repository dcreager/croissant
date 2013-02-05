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

#include <croissant/parsing.h>


struct crs_node_ref;

/* We support several ways of addressing remote nodes, each with its own
 * communication protocol. */

struct crs_node_manager {
    int
    (*send_message)(struct crs_node_ref *dest, struct cork_buffer *msg);

    int
    (*encode_address)(struct crs_node_ref *ref, struct cork_buffer *dest);

    void
    (*print_address)(struct crs_node_ref *ref, struct cork_buffer *dest);

    void
    (*free_ref)(struct crs_node_ref *ref);

    void
    (*free_manager)(struct crs_node_manager *manager);
};

#define crs_node_ref_send_message(dest, msg) \
    ((dest)->manager->send_message((dest), (msg)))
#define crs_node_ref_encode_address(ref, dest) \
    ((ref)->manager->encode_address((ref), (dest)))
#define crs_node_ref_print_address(ref, dest) \
    ((ref)->manager->print_address((ref), (dest)))
#define crs_node_ref_free(ref) \
    ((ref)->manager->free_ref((ref)))
#define crs_node_manager_free(manager) \
    ((manager)->free_manager((manager)))


/* a reference to another Pastry node */

struct crs_node_ref {
    struct crs_node_manager  *manager;
};


#endif  /* CROISSANT_NODE_H */
