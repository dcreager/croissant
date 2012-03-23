/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012, RedJack, LLC.
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


struct crs_node_ref;

/* We support several ways of addressing remote nodes, each with its own
 * communication protocol. */

struct crs_node_type {
    const char  *name;

    int
    (*send_message)(struct crs_node_ref *dest, struct cork_buffer *msg);

    void
    (*print_address)(struct crs_node_ref *ref, struct cork_buffer *dest);

    void
    (*free_ref)(struct crs_node_ref *ref);
};


/* a reference to another Pastry node */

struct crs_node_ref {
    const struct crs_node_type  *type;
};


#define crs_node_ref_send_message(dest, msg) \
    ((dest)->type->send_message((dest), (msg)))

#define crs_node_ref_print_address(ref, dest) \
    ((ref)->type->print_address((ref), (dest)))

#define crs_node_ref_free(ref) \
    ((ref)->type->free_ref((ref)))


#endif  /* CROISSANT_NODE_H */
