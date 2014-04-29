/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2014, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <clogger.h>
#include <libcork/core.h>
#include <libcork/ds.h>
#include <libcork/helpers/errors.h>

#include "croissant.h"


/*-----------------------------------------------------------------------
 * Connection types
 */

static void *
crs_conn_type__default_new_address(void *ct)
{
    return NULL;
}

static int
crs_conn_type__default_decode_address(void *ct, struct crs_message *msg)
{
    return 0;
}

static void
crs_conn_type__default_encode_address(void *ct, struct crs_message *msg)
{
}

static void
crs_conn_type__default_print_address(void *ct, struct crs_buffer *dest)
{
}

static int
crs_conn_type__default_bind(void *ct, struct crs_node *node)
{
    return 0;
}

static int
crs_conn_type__default_connect(void *ct, struct crs_node_ref *ref)
{
    return 0;
}

struct crs_conn_type *
crs_conn_type_new(crs_conn_type_id id, const char *name)
{
    struct crs_conn_type  *type = cork_new(struct crs_conn_type);
    type->id = id;
    type->name = cork_strdup(name);
    type->user_data = NULL;
    type->free_user_data = NULL;
    type->new_address = crs_conn_type__default_new_address;
    type->free_address = NULL;
    type->decode_address = crs_conn_type__default_decode_address;
    type->encode_address = crs_conn_type__default_encode_address;
    type->print_address = crs_conn_type__default_print_address;
    type->bind = crs_conn_type__default_bind;
    type->connect = crs_conn_type__default_connect;
    return type;
}

void
crs_conn_type_set_user_data(struct crs_conn_type *type,
                            void *user_data, cork_free_f free_user_data)
{
    cork_free_user_data(type);
    type->user_data = user_data;
    type->free_user_data = free_user_data;
}

void
crs_conn_type_set_new_address(struct crs_conn_type *type,
                              crs_node_address_new_f *new_address)
{
    type->new_address = new_address;
}

void
crs_conn_type_set_free_address(struct crs_conn_type *type,
                               cork_free_f *free_address)
{
    type->free_address = free_address;
}

void
crs_conn_type_set_decode_address(struct crs_conn_type *type,
                                 crs_node_address_decode_f *decode_address)
{
    type->decode_address = decode_address;
}

void
crs_conn_type_set_encode_address(struct crs_conn_type *type,
                                 crs_node_address_encode_f *encode_address)
{
    type->encode_address = encode_address;
}

void
crs_conn_type_set_parse_address(struct crs_conn_type *type,
                                crs_node_address_parse_f *parse_address)
{
    type->parse_address = parse_address;
}

void
crs_conn_type_set_print_address(struct crs_conn_type *type,
                                crs_node_address_print_f *print_address)
{
    type->print_address = print_address;
}

void
crs_conn_type_set_bind_node(struct crs_conn_type *type,
                            crs_node_bind_f *bind)
{
    type->bind = bind;
}

void
crs_conn_type_set_connect_ref(struct crs_conn_type *type,
                              crs_node_ref_connect_f *connect)
{
    type->connect = connect;
}

void
crs_conn_type_free(struct crs_conn_type *type)
{
    cork_free_user_data(type);
    free(type);
}


/*-----------------------------------------------------------------------
 * Node addresses
 */

struct crs_node_address {
    struct crs_conn_type  *type;
    void  *user_data;
};

void
crs_node_address_print(struct cork_buffer *dest,
                       const struct crs_node_address *address)
{
    address->type->print_address(address->user_data, dest);
}

void
crs_node_address_free(struct crs_node_address *address)
{
    address->type->free_address(address->user_data);
    free(address);
}

void
crs_node_address_encode(struct crs_message *msg,
                        const struct crs_node_address *address)
{
    address->type->encode_address(address->user_data, msg);
}

const struct crs_node_address *
crs_node_address_decode(struct crs_message *msg, const char *field_name)
{
    crs_node_type_id  type;
    rpi_check(crs_message_decode_uint32(msg, &type, field_name));
    switch (type) {
        case CRS_NODE_TYPE_ID_LOCAL:
            return crs_local_node_address_decode(msg);
        default:
            crs_parse_error("Unknown node type 0x%08" PRIx32, type);
            return NULL;
    }
}
