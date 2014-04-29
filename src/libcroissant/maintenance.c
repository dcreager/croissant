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
#include <libcork/helpers/errors.h>

#include "croissant.h"
#include "croissant/maintenance.h"
#include "croissant/node.h"

#define CLOG_CHANNEL  "maintenance"


/*-----------------------------------------------------------------------
 * Node maintainance application
 */

#define CRS_MAINTENANCE_ID  0x9af7cb5f

#define JOIN                0
#define FIND_JOINER         1
#define SEND_LEAF_SET       2
#define SEND_ROUTING_TABLE  3
#define ANNOUNCE            4

struct crs_maintenance {
    struct crs_node  *node;
    struct crs_application  *app;
};

static int
crs_maintenance__JOIN(struct crs_maintenance *maint, struct crs_node *node,
                      crs_id src, crs_id dest, struct crs_message *msg)
{
    struct crs_node_ref  *join_ref;

    /* Parse the message. */
    rip_check(join_ref = crs_node_ref_decode(msg, node, "joining node"));
    clog_debug("[%s] {maint} Received join request from %s at %s",
               crs_node_get_address_str(node),
               crs_node_ref_get_id_str(join_ref),
               crs_node_ref_get_address_str(join_ref));

    /* Route a message back towards the joining node before adding the new node
     * to any of our routing tables. */
    return crs_maintenance_find_joiner(maint, join_ref);
}

static int
crs_maintenance__FIND_JOINER(struct crs_maintenance *maint,
                             struct crs_node *node, crs_id src, crs_id dest,
                             struct crs_message *msg)
{
    struct crs_node_ref  *join_ref;
    char  src_str[CRS_ID_STRING_LENGTH];
    int  msdd;

    /* Parse the message. */
    rip_check(join_ref = crs_node_ref_decode(msg, node, "joining node"));
    clog_debug("[%s] {maint} Received join reply from %s for %s at %s",
               crs_node_get_address_str(node),
               crs_id_to_raw_string(src_str, src),
               crs_node_ref_get_id_str(join_ref),
               crs_node_ref_get_address_str(join_ref));

    /* All of the nodes that we encounter while routing the FIND_JOINER message
     * from the bootstrap node to the new node should send part of their routing
     * tables to the new node.  This includes the final destination node, which
     * won't get an `intercept` callback for this message, so we need to send
     * the routing table here, too. */
    msdd = crs_id_get_msdd(node->id, dest);
    if (msdd >= 0) {
        rii_check(crs_maintenance_send_routing_table(maint, join_ref, msdd+1));
    }

    /* The node that receives this message is the existing node whose ID is
     * closest to the joining node.  We provide an initial leaf set to the
     * joining node. */
    return crs_maintenance_send_leaf_set(maint, join_ref);
}

static int
crs_maintenance__announce(void *user_data, struct crs_node_ref *ref)
{
    struct crs_maintenance  *maint = user_data;
    return crs_maintenance_announce(maint, ref);
}

static int
crs_maintenance__SEND_LEAF_SET(struct crs_maintenance *maint,
                               struct crs_node *node, crs_id src, crs_id dest,
                               struct crs_message *msg)
{
    struct crs_node_ref  *leaf_set_src;

    /* Parse the start of the message. */
    rip_check(leaf_set_src = crs_node_ref_decode(msg, node, "leaf set source"));
    clog_debug("[%s] {maint} Received initial leaf set from %s at %s",
               crs_node_get_address_str(node),
               crs_node_ref_get_id_str(leaf_set_src),
               crs_node_ref_get_address_str(leaf_set_src));

    /* Try to add the source of the leaf set to our set. */
    if (!crs_id_equals(leaf_set_src->id, node->id)) {
        crs_leaf_set_add(node->leaf_set, leaf_set_src);
    }

    /* Parse the remainder of the message to populate our leaf set. */
    rii_check(crs_leaf_set_decode(msg, node->leaf_set, "leaf set"));

    /* Announce ourselves to each member of our new leaf set. */
    return crs_leaf_set_visit_each
        (node->leaf_set, maint, crs_maintenance__announce);
}

static int
crs_maintenance__SEND_ROUTING_TABLE(struct crs_maintenance *maint,
                                    struct crs_node *node,
                                    crs_id src, crs_id dest,
                                    struct crs_message *msg)
{
    struct crs_node_ref  *routing_table_src;

    /* Parse the start of the message. */
    rip_check(routing_table_src =
              crs_node_ref_decode(msg, node, "routing table source"));
    clog_debug("[%s] {maint} Received partial routing table from %s at %s",
               crs_node_get_address_str(node),
               crs_node_ref_get_id_str(routing_table_src),
               crs_node_ref_get_address_str(routing_table_src));

    /* Try to add the source of the routing table to our routing table. */
    if (!crs_id_equals(routing_table_src->id, node->id)) {
        crs_routing_table_set(node->routing_table, routing_table_src);
    }

    /* Parse the remainder of the message to populate our leaf set. */
    return crs_routing_table_decode(msg, node->routing_table, "routing table");
}

static int
crs_maintenance__ANNOUNCE(struct crs_maintenance *maint, struct crs_node *node,
                          crs_id src, crs_id dest, struct crs_message *msg)
{
    struct crs_node_ref  *other_ref;

    /* Parse the message. */
    rip_check(other_ref = crs_node_ref_decode(msg, node, "node"));
    clog_debug("[%s] {maint} Received presence announcement from %s at %s",
               crs_node_get_address_str(node),
               crs_node_ref_get_id_str(other_ref),
               crs_node_ref_get_address_str(other_ref));

    /* Try to add the announcing node to our routing tables. */
    if (!crs_id_equals(other_ref->id, node->id)) {
        crs_leaf_set_add(node->leaf_set, other_ref);
        crs_routing_table_set(node->routing_table, other_ref);
    }

    return 0;
}

static int
crs_maintenance__receive(void *user_data, struct crs_node *node,
                         crs_id src, crs_id dest, struct crs_message *msg)
{
    struct crs_maintenance  *maint = user_data;
    uint8_t  command;
    rii_check(crs_message_decode_uint8(msg, &command, "maintenance command"));
    switch (command) {
        case JOIN:
            return crs_maintenance__JOIN(maint, node, src, dest, msg);
        case FIND_JOINER:
            return crs_maintenance__FIND_JOINER(maint, node, src, dest, msg);
        case SEND_LEAF_SET:
            return crs_maintenance__SEND_LEAF_SET(maint, node, src, dest, msg);
        case SEND_ROUTING_TABLE:
            return crs_maintenance__SEND_ROUTING_TABLE
                (maint, node, src, dest, msg);
        case ANNOUNCE:
            return crs_maintenance__ANNOUNCE(maint, node, src, dest, msg);
        default:
            crs_parse_error("Unknown maintenance command %" PRIu8, command);
            return -1;
    }
}

static int
crs_maintenance__intercept_FIND_JOINER(struct crs_maintenance *maint,
                                       struct crs_node *node,
                                       struct crs_node_ref *next_hop,
                                       crs_id src, crs_id dest,
                                       struct crs_message *msg)
{
    struct crs_node_ref  *join_ref;
    char  src_str[CRS_ID_STRING_LENGTH];
    int  msdd;

    /* Parse the message. */
    rip_check(join_ref = crs_node_ref_decode(msg, node, "joining node"));
    clog_debug("[%s] {maint} Intercept join reply from %s for %s at %s",
               crs_node_get_address_str(node),
               crs_id_to_raw_string(src_str, src),
               crs_node_ref_get_id_str(join_ref),
               crs_node_ref_get_address_str(join_ref));

    /* All of the nodes that we encounter while routing the FIND_JOINER message
     * from the bootstrap node to the new node should send part of their routing
     * tables to the new node. */
    msdd = crs_id_get_msdd(node->id, dest);
    if (msdd >= 0) {
        rii_check(crs_maintenance_send_routing_table(maint, join_ref, msdd+1));
    }
    return crs_node_ref_forward(next_hop, src, dest, msg);
}

static int
crs_maintenance__intercept(void *user_data, struct crs_node *node,
                           struct crs_node_ref *next_hop,
                           crs_id src, crs_id dest, struct crs_message *msg)
{
    struct crs_maintenance  *maint = user_data;
    uint8_t  command;
    rii_check(crs_message_decode_uint8(msg, &command, "maintenance command"));
    if (command == FIND_JOINER) {
        return crs_maintenance__intercept_FIND_JOINER
            (maint, node, next_hop, src, dest, msg);
    } else {
        return crs_node_ref_forward(next_hop, src, dest, msg);
    }
}

static void
crs_maintenance__free(void *user_data)
{
    struct crs_maintenance  *maint = user_data;
    free(maint);
}

CORK_LOCAL struct crs_maintenance *
crs_maintenance_new(struct crs_node *node)
{
    struct crs_maintenance  *maint = cork_new(struct crs_maintenance);
    maint->node = node;
    maint->app = crs_application_new(CRS_MAINTENANCE_ID, "crs_maintenance");
    crs_application_set_user_data(maint->app, maint, crs_maintenance__free);
    crs_application_set_intercept(maint->app, crs_maintenance__intercept);
    crs_application_set_receive(maint->app, crs_maintenance__receive);
    return maint;
}

CORK_LOCAL void
crs_maintenance_free(struct crs_maintenance *maint)
{
    crs_application_free(maint->app);
}

CORK_LOCAL int
crs_maintenance_register(struct crs_maintenance *maint, struct crs_node *node)
{
    return crs_node_add_application(node, maint->app);
}

CORK_LOCAL struct crs_maintenance *
crs_maintenance_get(struct crs_node *node)
{
    struct crs_application  *app;
    rpp_check(app = crs_node_get_application(node, CRS_MAINTENANCE_ID));
    return crs_application_get_user_data(app);
}

CORK_LOCAL int
crs_maintenance_join(struct crs_maintenance *maint,
                     struct crs_node_ref *bootstrap_ref)
{
    struct crs_message  *msg = crs_application_new_message(maint->app);
    clog_debug("[%s] Send join request to %s at %s",
               crs_node_get_address_str(maint->node),
               crs_node_ref_get_id_str(bootstrap_ref),
               crs_node_ref_get_address_str(bootstrap_ref));
    crs_message_encode_uint8(msg, JOIN);
    crs_node_ref_encode(msg, maint->node->ref);
    return crs_node_ref_send
        (bootstrap_ref, maint->node->id, bootstrap_ref->id, msg);
}

CORK_LOCAL int
crs_maintenance_find_joiner(struct crs_maintenance *maint,
                            struct crs_node_ref *dest)
{
    struct crs_message  *msg = crs_application_new_message(maint->app);
    clog_debug("[%s] Route initial message to new node %s at %s",
               crs_node_get_address_str(maint->node),
               crs_node_ref_get_id_str(dest),
               crs_node_ref_get_address_str(dest));
    crs_message_encode_uint8(msg, FIND_JOINER);
    crs_node_ref_encode(msg, dest);
    return crs_application_send_message(maint->app, dest->id, msg);
}

CORK_LOCAL int
crs_maintenance_send_leaf_set(struct crs_maintenance *maint,
                              struct crs_node_ref *dest)
{
    struct crs_message  *msg = crs_application_new_message(maint->app);
    clog_debug("[%s] Send initial leaf set to new node %s at %s",
               crs_node_get_address_str(maint->node),
               crs_node_ref_get_id_str(dest),
               crs_node_ref_get_address_str(dest));
    crs_message_encode_uint8(msg, SEND_LEAF_SET);
    crs_node_ref_encode(msg, maint->node->ref);
    crs_leaf_set_encode(msg, maint->node->leaf_set);
    return crs_node_ref_send(dest, maint->node->id, dest->id, msg);
}

CORK_LOCAL int
crs_maintenance_send_routing_table(struct crs_maintenance *maint,
                                   struct crs_node_ref *dest,
                                   unsigned int row_count)
{
    struct crs_message  *msg = crs_application_new_message(maint->app);
    clog_debug("[%s] Send %u rows of routing table to %s at %s",
               crs_node_get_address_str(maint->node),
               row_count,
               crs_node_ref_get_id_str(dest),
               crs_node_ref_get_address_str(dest));
    crs_message_encode_uint8(msg, SEND_ROUTING_TABLE);
    crs_node_ref_encode(msg, maint->node->ref);
    crs_routing_table_encode(msg, maint->node->routing_table, row_count);
    return crs_node_ref_send(dest, maint->node->id, dest->id, msg);
}

CORK_LOCAL int
crs_maintenance_announce(struct crs_maintenance *maint,
                         struct crs_node_ref *dest)
{
    struct crs_message  *msg = crs_application_new_message(maint->app);
    clog_debug("[%s] Announce presence to %s at %s",
               crs_node_get_address_str(maint->node),
               crs_node_ref_get_id_str(dest),
               crs_node_ref_get_address_str(dest));
    crs_message_encode_uint8(msg, ANNOUNCE);
    crs_node_ref_encode(msg, maint->node->ref);
    return crs_node_ref_send(dest, maint->node->id, dest->id, msg);
}
