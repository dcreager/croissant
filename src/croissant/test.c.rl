/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <stdlib.h>

#include <clogger.h>
#include <libcork/core.h>
#include <libcork/cli.h>
#include <libcork/ds.h>
#include <libcork/helpers/errors.h>

#include "croissant.h"

static struct crs_node *
crs_ctx_require_node(struct crs_ctx *ctx, const struct crs_id *id)
{
    struct crs_node  *node = crs_ctx_get_node_with_id(ctx, id);
    if (node == NULL) {
        char  id_str[CRS_ID_STRING_LENGTH];
        crs_id_to_raw_string(id, id_str);
        crs_parse_error("No node %s", id_str);
    }
    return node;
}

static int
crs_parse_command(struct crs_ctx *ctx, const char *command)
{
    int  cs;
    const char  *p = command;
    const char  *pe = strchr(command, '\0');
    const char  *start;

    struct cork_buffer  buf = CORK_BUFFER_INIT();
    struct cork_buffer  output = CORK_BUFFER_INIT();
    struct crs_node  *node;
    struct crs_id  id1;

    %%{
        machine crs_command;

        hex_digit = digit | 'a'..'f' | 'A'..'F';
        id = hex_digit{32}
           >{ start = fpc; } %{ cork_buffer_set(&buf, start, fpc - start); };

        id1 = id %{ rii_check(crs_id_init(&id1, buf.buf)); };

        new_node = "new" space+ "node" space+ id1
            %{
                rip_check(crs_node_new(ctx, &id1, NULL));
            };

        add_leaf_set_entry =
            "add" space+ "leaf" space+ "set" space+ "entry"
            space+ id1
            %{
                struct crs_leaf_set  *from_set;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                rip_check(to_node = crs_ctx_require_node(ctx, &id1));
                from_set = crs_node_get_leaf_set(node);
                to_ref = crs_node_get_ref(to_node);
                crs_leaf_set_add(from_set, to_ref);
            };

        add_routing_table_entry =
            "add" space+ "routing" space+ "table" space+ "entry"
            space+ id1
            %{
                struct crs_routing_table  *from_table;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                rip_check(to_node = crs_ctx_require_node(ctx, &id1));
                from_table = crs_node_get_routing_table(node);
                to_ref = crs_node_get_ref(to_node);
                crs_routing_table_set(from_table, to_ref);
            };

        print_leaf_set =
            "print" space+ "leaf" space+ "set"
            %{
                struct crs_leaf_set  *set;
                set = crs_node_get_leaf_set(node);
                cork_buffer_printf
                    (&output, "Leaf set for %s\n", crs_node_get_id_str(node));
                crs_leaf_set_print(&output, set);
                fwrite(output.buf, output.size, 1, stdout);
            };

        print_next_hop =
            "print" space+ "next" space+ "hop" space+ "for"
            space+ id1
            %{
                struct crs_node_ref  *next_hop;
                rip_check(next_hop = crs_node_get_next_hop(node, &id1));
                cork_buffer_printf
                    (&output,
                     "Next hop from %s\n"
                     "           to ",
                     crs_node_get_id_str(node));
                crs_id_print(&output, &id1);
                cork_buffer_append_printf
                    (&output,
                     "\n"
                     "           is %s\n",
                     (next_hop == CRS_NODE_REF_SELF)? "local delivery":
                         crs_node_ref_get_id_str(next_hop));
                fwrite(output.buf, output.size, 1, stdout);
            };

        print_routing_table =
            "print" space+ "routing" space+ "table"
            %{
                struct crs_routing_table  *table;
                table = crs_node_get_routing_table(node);
                cork_buffer_printf
                    (&output, "Routing table for %s\n",
                     crs_node_get_id_str(node));
                crs_routing_table_print(&output, table);
                fwrite(output.buf, output.size, 1, stdout);
            };

        node_command =
              add_leaf_set_entry
            | add_routing_table_entry
            | print_leaf_set
            | print_next_hop
            | print_routing_table
            ;

        node_statement = space* node_command space* ";";
        node_statements = node_statement | ("{" node_statement* space* "}");

        node = "node" space+ id1
               %{ rip_check(node = crs_ctx_require_node(ctx, &id1)); }
               space+ node_statements;

        command =
              new_node
            | node
            ;

        main := (space* command space* ";")* space*;

        write data noerror nofinal;
        write init;
        write exec;
    }%%

    /* A hack to suppress some unused variable warnings */
    (void) crs_command_en_main;

    if (CORK_UNLIKELY(cs < %%{ write first_final; }%%)) {
        crs_parse_error("Invalid command");
        cork_buffer_done(&buf);
        cork_buffer_done(&output);
        return -1;
    }

    cork_buffer_done(&buf);
    cork_buffer_done(&output);
    return 0;
}

static void
execute(int argc, char **argv)
{
    struct crs_ctx  *ctx = crs_ctx_new();
    struct cork_buffer  buf = CORK_BUFFER_INIT();
    struct cork_stream_consumer  *consumer;

    clog_set_default_format("%m");
    if (clog_setup_logging() != 0) {
        fprintf(stderr, "%s\n", cork_error_message());
        exit(EXIT_FAILURE);
    }

    cork_buffer_set(&buf, "", 0);
    consumer = cork_buffer_to_stream_consumer(&buf);
    if (cork_consume_file(consumer, stdin) != 0) {
        fprintf(stderr, "%s\n", cork_error_message());
        cork_stream_consumer_free(consumer);
        cork_buffer_done(&buf);
        crs_ctx_free(ctx);
        exit(EXIT_FAILURE);
    }

    if (crs_parse_command(ctx, buf.buf) != 0) {
        fprintf(stderr, "%s\n", cork_error_message());
        cork_stream_consumer_free(consumer);
        cork_buffer_done(&buf);
        crs_ctx_free(ctx);
        exit(EXIT_FAILURE);
    }

    cork_stream_consumer_free(consumer);
    cork_buffer_done(&buf);
    crs_ctx_free(ctx);
}

#define SHORT_DESC \
    "Test a Pastry network"

#define USAGE_SUFFIX \
    ""

#define HELP_TEXT \
    ""

struct cork_command  croissant_test =
    cork_leaf_command("test", SHORT_DESC, USAGE_SUFFIX, HELP_TEXT,
                      NULL, execute);
