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
    struct crs_id  id;
    struct crs_id  id1;
    struct crs_node  *node;
    struct crs_node  *node1;
    struct crs_node_ref  *ref;
    struct crs_routing_table  *table;

    %%{
        machine crs_command;

        hex_digit = digit | 'a'..'f' | 'A'..'F';

        id = hex_digit{32} >{ start = fpc; }
            %{
                cork_buffer_set(&buf, start, fpc - start);
                rii_check(crs_id_init(&id, buf.buf));
            };

        new_node = "new" space+ "node" space+ id
            %{
                rip_check(node = crs_node_new(ctx, &id, NULL));
            };

        add_routing_table_entry =
            space* "add" space+ "routing" space+ "table" space+ "entry"
            space+ (id %{ id1 = id; }) space+ id
            %{
                rip_check(node1 = crs_ctx_require_node(ctx, &id1));
                rip_check(node = crs_ctx_require_node(ctx, &id));

                table = crs_node_get_routing_table(node1);
                ref = crs_node_get_ref(node);
                crs_routing_table_set(table, ref);
            };

        command =
              add_routing_table_entry
            | new_node
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
        return -1;
    }

    cork_buffer_done(&buf);
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
