/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013-2014, RedJack, LLC.
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
#include "croissant/tests.h"

static struct crs_node *
crs_ctx_require_node(struct crs_ctx *ctx, crs_id id)
{
    struct crs_node  *node = crs_ctx_get_node_with_id(ctx, id);
    if (node == NULL) {
        char  id_str[CRS_ID_STRING_LENGTH];
        crs_id_to_raw_string(id_str, id);
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
    const char  *eof = pe;
    const char  *start;

    struct cork_buffer  buf = CORK_BUFFER_INIT();
    struct cork_buffer  message = CORK_BUFFER_INIT();
    struct cork_buffer  output = CORK_BUFFER_INIT();
    struct crs_node  *node;
    crs_id  id1;
    char  id1_str[CRS_ID_STRING_LENGTH];

    %%{
        machine crs_command;

        hex_digit = digit | 'a'..'f' | 'A'..'F';
        id = hex_digit{32}
           >{ start = fpc; } %{ cork_buffer_set(&buf, start, fpc - start); };

        id1 = id %{ rie_check(id1 = crs_id_init(buf.buf)); };

        word = alnum+
             >{ start = fpc; }
             %{ cork_buffer_set(&message, start, fpc - start); };

        new_node = "new" space+ "node" space+ id1
            %{
                struct crs_print_message  *printer;
                fprintf(stderr, "--- new node %s\n",
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(node = crs_node_new(ctx, id1, NULL));
                printer = crs_print_message_new(stderr);
                rii_check(crs_print_message_register(printer, node));
            };

        add_leaf_set_entry =
            "add" space+ "leaf" space+ "set" space+ "entry"
            space+ id1
            %{
                struct crs_leaf_set  *from_set;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                fprintf(stderr, "--- [%s]\n--- add leaf set entry %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(to_node = crs_ctx_require_node(ctx, id1));
                from_set = crs_node_get_leaf_set(node);
                to_ref = crs_node_new_ref(node, crs_node_get_address(to_node));
                crs_leaf_set_add(from_set, to_ref);
            };

        add_routing_table_entry =
            "add" space+ "routing" space+ "table" space+ "entry"
            space+ id1
            %{
                struct crs_routing_table  *from_table;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                fprintf(stderr, "--- [%s]\n--- add routing table entry %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(to_node = crs_ctx_require_node(ctx, id1));
                from_table = crs_node_get_routing_table(node);
                to_ref = crs_node_new_ref(node, crs_node_get_address(to_node));
                crs_routing_table_set(from_table, to_ref);
            };

        print_leaf_set =
            "print" space+ "leaf" space+ "set"
            %{
                struct crs_leaf_set  *set;
                fprintf(stderr, "--- [%s]\n--- print leaf set\n",
                        crs_node_get_id_str(node));
                set = crs_node_get_leaf_set(node);
                cork_buffer_printf
                    (&output, "Leaf set for %s\n", crs_node_get_id_str(node));
                crs_leaf_set_print(&output, set);
                fwrite(output.buf, output.size, 1, stderr);
            };

        print_next_hop =
            "print" space+ "next" space+ "hop" space+ "for"
            space+ id1
            %{
                struct crs_node_ref  *next_hop;
                fprintf(stderr, "--- [%s]\n--- print next hop for %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(next_hop = crs_node_get_next_hop(node, id1));
                fprintf
                    (stderr,
                     "Next hop from %s\n"
                     "           to %s\n"
                     "           is %s\n",
                     crs_node_get_id_str(node),
                     crs_id_to_raw_string(id1_str, id1),
                     (next_hop == CRS_NODE_REF_SELF)? "local delivery":
                         crs_node_ref_get_id_str(next_hop));
            };

        print_routing_table =
            "print" space+ "routing" space+ "table"
            %{
                struct crs_routing_table  *table;
                fprintf(stderr, "--- [%s]\n--- print routing table\n",
                        crs_node_get_id_str(node));
                table = crs_node_get_routing_table(node);
                cork_buffer_printf
                    (&output, "Routing table for %s\n",
                     crs_node_get_id_str(node));
                crs_routing_table_print(&output, table);
                fwrite(output.buf, output.size, 1, stderr);
            };

        send =
            "send" space+ word space+ "to" space+ id1
            %{
                struct crs_print_message  *printer;
                rip_check(printer = crs_print_message_get(node));
                fprintf(stderr, "--- [%s]\n--- send \"%s\" to %s\n",
                        crs_node_get_id_str(node),
                        (char *) message.buf,
                        crs_id_to_raw_string(id1_str, id1));
                rii_check(crs_print_message_send(printer, id1, message.buf));
            };

        node_command =
              add_leaf_set_entry
            | add_routing_table_entry
            | print_leaf_set
            | print_next_hop
            | print_routing_table
            | send
            ;

        node_statement = space* node_command space* ";";
        node_statements = node_statement | ("{" node_statement* space* "}");

        node = "node" space+ id1
               %{ rip_check(node = crs_ctx_require_node(ctx, id1)); }
               space+ node_statements;

        command =
              new_node
            | node
            ;

        main := (space* command space* ";")* space*
                %{
                    fprintf(stderr, "---\n");
                };

        write data noerror nofinal;
        write init;
        write exec;
    }%%

    /* A hack to suppress some unused variable warnings */
    (void) crs_command_en_main;

    if (CORK_UNLIKELY(cs < %%{ write first_final; }%%)) {
        crs_parse_error("Invalid command");
        goto error;
    }

    cork_buffer_done(&buf);
    cork_buffer_done(&message);
    cork_buffer_done(&output);
    return 0;

error:
    cork_buffer_done(&buf);
    cork_buffer_done(&message);
    cork_buffer_done(&output);
    return -1;
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
