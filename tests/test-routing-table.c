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
#include <stdio.h>
#include <string.h>

#include <check.h>
#include <libcork/core.h>
#include <libcork/ds.h>

#include "croissant.h"
#include "croissant/tests.h"
#include "helpers.h"


/*-----------------------------------------------------------------------
 * Routing table
 */

static void
verify_routing_table(const struct crs_routing_table *table,
                     const char *expected)
{
    struct cork_buffer  actual = CORK_BUFFER_INIT();
    cork_buffer_set(&actual, "", 0);
    crs_routing_table_print(&actual, table);
    if (strcmp(actual.buf, expected) != 0) {
        fprintf(stderr, "Expected:\n%s\nGot:\n%s",
                expected, (char *) actual.buf);
        cork_buffer_done(&actual);
        ck_abort_msg("Routing tables not equal");
    } else {
        cork_buffer_done(&actual);
    }
}

/* Each ID_XX has one additional prefix digit in common with ID_SELF */
static const char  *ID_SELF = "00000000000000000000000000000000";
static const char  *ID_00   = "123456789abcdef123456789abcdef12";
static const char  *ID_01   = "edcba987654321fedcba987654321fed";

static void
create_test_id(struct crs_id *id, const char *id_template,
               unsigned int common_prefix)
{
    unsigned int  i;
    char  id_str[CRS_ID_STRING_LENGTH];
    ck_assert(common_prefix >= 0 && common_prefix <= CRS_ID_NYBBLE_LENGTH);
    strncpy(id_str, id_template, CRS_ID_STRING_LENGTH);
    for (i = 0; i < common_prefix; i++) {
        id_str[i] = ID_SELF[i];
    }
    crs_id_init(id, id_str);
}

static void
add_prefix_to_table(struct crs_ctx *ctx, struct crs_routing_table *table,
                    const char *id_template, unsigned int common_prefix)
{
    struct crs_id  id;
    struct crs_node  *node;
    struct crs_node_ref  *ref;
    create_test_id(&id, id_template, common_prefix);
    node = crs_node_new(ctx, &id, NULL);
    ref = crs_node_get_ref(node);
    crs_routing_table_set(table, ref);
}

static void
add_prefix_to_table_with_proximity(struct crs_ctx *ctx,
                                   struct crs_routing_table *table,
                                   const char *id_template,
                                   unsigned int common_prefix,
                                   crs_proximity proximity)
{
    struct crs_id  id;
    struct crs_node  *node;
    struct crs_node_ref  *ref;
    create_test_id(&id, id_template, common_prefix);
    node = crs_node_new(ctx, &id, NULL);
    ref = crs_node_get_ref(node);
    crs_node_ref_set_proximity(ref, proximity);
    crs_routing_table_set(table, ref);
}

START_TEST(test_routing_table_01)
{
    DESCRIBE_TEST;
    struct crs_id  id;
    struct crs_ctx  *ctx;
    struct crs_node  *node;
    struct crs_routing_table  *table;
    ctx = crs_ctx_new();
    crs_id_init(&id, ID_SELF);
    node = crs_node_new(ctx, &id, NULL);
    fail_if_error(table = crs_routing_table_new(node));
    verify_routing_table(table, "");
    crs_routing_table_free(table);
    crs_ctx_free(ctx);
    fail_if_error(crs_finalize_tests());
}
END_TEST

START_TEST(test_routing_table_02)
{
    DESCRIBE_TEST;
    struct crs_id  id;
    struct crs_ctx  *ctx;
    struct crs_node  *node;
    struct crs_routing_table  *table;
    ctx = crs_ctx_new();
    crs_id_init(&id, ID_SELF);
    node = crs_node_new(ctx, &id, NULL);
    fail_if_error(table = crs_routing_table_new(node));
    add_prefix_to_table(ctx, table, ID_00, 0);
    verify_routing_table(table,
        "[ 0/1] 123456789abcdef123456789abcdef12 local:2\n"
    );
    crs_routing_table_free(table);
    crs_ctx_free(ctx);
    fail_if_error(crs_finalize_tests());
}
END_TEST

START_TEST(test_routing_table_03)
{
    DESCRIBE_TEST;
    size_t  i;
    struct crs_id  id;
    struct crs_ctx  *ctx;
    struct crs_node  *node;
    struct crs_routing_table  *table;
    ctx = crs_ctx_new();
    crs_id_init(&id, ID_SELF);
    node = crs_node_new(ctx, &id, NULL);
    fail_if_error(table = crs_routing_table_new(node));
    for (i = 0; i < CRS_ROUTING_TABLE_ROW_COUNT; i++) {
        add_prefix_to_table(ctx, table, ID_00, i);
    }
    verify_routing_table(table,
        "[ 0/1] 123456789abcdef123456789abcdef12 local:2\n"
        "[ 1/2] 023456789abcdef123456789abcdef12 local:3\n"
        "[ 2/3] 003456789abcdef123456789abcdef12 local:4\n"
        "[ 3/4] 000456789abcdef123456789abcdef12 local:5\n"
        "[ 4/5] 000056789abcdef123456789abcdef12 local:6\n"
        "[ 5/6] 000006789abcdef123456789abcdef12 local:7\n"
        "[ 6/7] 000000789abcdef123456789abcdef12 local:8\n"
        "[ 7/8] 000000089abcdef123456789abcdef12 local:9\n"
        "[ 8/9] 000000009abcdef123456789abcdef12 local:10\n"
        "[ 9/a] 000000000abcdef123456789abcdef12 local:11\n"
        "[10/b] 0000000000bcdef123456789abcdef12 local:12\n"
        "[11/c] 00000000000cdef123456789abcdef12 local:13\n"
        "[12/d] 000000000000def123456789abcdef12 local:14\n"
        "[13/e] 0000000000000ef123456789abcdef12 local:15\n"
        "[14/f] 00000000000000f123456789abcdef12 local:16\n"
        "[15/1] 000000000000000123456789abcdef12 local:17\n"
        "[16/2] 000000000000000023456789abcdef12 local:18\n"
        "[17/3] 000000000000000003456789abcdef12 local:19\n"
        "[18/4] 000000000000000000456789abcdef12 local:20\n"
        "[19/5] 000000000000000000056789abcdef12 local:21\n"
        "[20/6] 000000000000000000006789abcdef12 local:22\n"
        "[21/7] 000000000000000000000789abcdef12 local:23\n"
        "[22/8] 000000000000000000000089abcdef12 local:24\n"
        "[23/9] 000000000000000000000009abcdef12 local:25\n"
        "[24/a] 000000000000000000000000abcdef12 local:26\n"
        "[25/b] 0000000000000000000000000bcdef12 local:27\n"
        "[26/c] 00000000000000000000000000cdef12 local:28\n"
        "[27/d] 000000000000000000000000000def12 local:29\n"
        "[28/e] 0000000000000000000000000000ef12 local:30\n"
        "[29/f] 00000000000000000000000000000f12 local:31\n"
        "[30/1] 00000000000000000000000000000012 local:32\n"
        "[31/2] 00000000000000000000000000000002 local:33\n"
    );
    crs_routing_table_free(table);
    crs_ctx_free(ctx);
    fail_if_error(crs_finalize_tests());
}
END_TEST

START_TEST(test_routing_table_04)
{
    DESCRIBE_TEST;
    size_t  i;
    struct crs_id  id;
    struct crs_ctx  *ctx;
    struct crs_node  *node;
    struct crs_routing_table  *table;
    ctx = crs_ctx_new();
    crs_id_init(&id, ID_SELF);
    node = crs_node_new(ctx, &id, NULL);
    fail_if_error(table = crs_routing_table_new(node));
    for (i = 0; i < CRS_ROUTING_TABLE_ROW_COUNT; i++) {
        add_prefix_to_table(ctx, table, ID_00, i);
        add_prefix_to_table(ctx, table, ID_01, i);
    }
    verify_routing_table(table,
        "[ 0/1] 123456789abcdef123456789abcdef12 local:2\n"
        "[ 0/e] edcba987654321fedcba987654321fed local:3\n"
        "[ 1/2] 023456789abcdef123456789abcdef12 local:4\n"
        "[ 1/d] 0dcba987654321fedcba987654321fed local:5\n"
        "[ 2/3] 003456789abcdef123456789abcdef12 local:6\n"
        "[ 2/c] 00cba987654321fedcba987654321fed local:7\n"
        "[ 3/4] 000456789abcdef123456789abcdef12 local:8\n"
        "[ 3/b] 000ba987654321fedcba987654321fed local:9\n"
        "[ 4/5] 000056789abcdef123456789abcdef12 local:10\n"
        "[ 4/a] 0000a987654321fedcba987654321fed local:11\n"
        "[ 5/6] 000006789abcdef123456789abcdef12 local:12\n"
        "[ 5/9] 00000987654321fedcba987654321fed local:13\n"
        "[ 6/7] 000000789abcdef123456789abcdef12 local:14\n"
        "[ 6/8] 00000087654321fedcba987654321fed local:15\n"
        "[ 7/7] 00000007654321fedcba987654321fed local:17\n"
        "[ 7/8] 000000089abcdef123456789abcdef12 local:16\n"
        "[ 8/6] 00000000654321fedcba987654321fed local:19\n"
        "[ 8/9] 000000009abcdef123456789abcdef12 local:18\n"
        "[ 9/5] 00000000054321fedcba987654321fed local:21\n"
        "[ 9/a] 000000000abcdef123456789abcdef12 local:20\n"
        "[10/4] 00000000004321fedcba987654321fed local:23\n"
        "[10/b] 0000000000bcdef123456789abcdef12 local:22\n"
        "[11/3] 00000000000321fedcba987654321fed local:25\n"
        "[11/c] 00000000000cdef123456789abcdef12 local:24\n"
        "[12/2] 00000000000021fedcba987654321fed local:27\n"
        "[12/d] 000000000000def123456789abcdef12 local:26\n"
        "[13/1] 00000000000001fedcba987654321fed local:29\n"
        "[13/e] 0000000000000ef123456789abcdef12 local:28\n"
        "[14/f] 00000000000000f123456789abcdef12 local:30\n"
        "[15/1] 000000000000000123456789abcdef12 local:32\n"
        "[15/e] 000000000000000edcba987654321fed local:33\n"
        "[16/2] 000000000000000023456789abcdef12 local:34\n"
        "[16/d] 0000000000000000dcba987654321fed local:35\n"
        "[17/3] 000000000000000003456789abcdef12 local:36\n"
        "[17/c] 00000000000000000cba987654321fed local:37\n"
        "[18/4] 000000000000000000456789abcdef12 local:38\n"
        "[18/b] 000000000000000000ba987654321fed local:39\n"
        "[19/5] 000000000000000000056789abcdef12 local:40\n"
        "[19/a] 0000000000000000000a987654321fed local:41\n"
        "[20/6] 000000000000000000006789abcdef12 local:42\n"
        "[20/9] 00000000000000000000987654321fed local:43\n"
        "[21/7] 000000000000000000000789abcdef12 local:44\n"
        "[21/8] 00000000000000000000087654321fed local:45\n"
        "[22/7] 00000000000000000000007654321fed local:47\n"
        "[22/8] 000000000000000000000089abcdef12 local:46\n"
        "[23/6] 00000000000000000000000654321fed local:49\n"
        "[23/9] 000000000000000000000009abcdef12 local:48\n"
        "[24/5] 00000000000000000000000054321fed local:51\n"
        "[24/a] 000000000000000000000000abcdef12 local:50\n"
        "[25/4] 00000000000000000000000004321fed local:53\n"
        "[25/b] 0000000000000000000000000bcdef12 local:52\n"
        "[26/3] 00000000000000000000000000321fed local:55\n"
        "[26/c] 00000000000000000000000000cdef12 local:54\n"
        "[27/2] 00000000000000000000000000021fed local:57\n"
        "[27/d] 000000000000000000000000000def12 local:56\n"
        "[28/1] 00000000000000000000000000001fed local:59\n"
        "[28/e] 0000000000000000000000000000ef12 local:58\n"
        "[29/f] 00000000000000000000000000000f12 local:60\n"
        "[30/1] 00000000000000000000000000000012 local:62\n"
        "[30/e] 000000000000000000000000000000ed local:63\n"
        "[31/2] 00000000000000000000000000000002 local:64\n"
        "[31/d] 0000000000000000000000000000000d local:65\n"
    );
    crs_routing_table_free(table);
    crs_ctx_free(ctx);
    fail_if_error(crs_finalize_tests());
}
END_TEST


START_TEST(test_routing_table_conflict_01)
{
    DESCRIBE_TEST;
    struct crs_id  id;
    struct crs_ctx  *ctx;
    struct crs_node  *node;
    struct crs_routing_table  *table;
    ctx = crs_ctx_new();
    crs_id_init(&id, ID_SELF);
    node = crs_node_new(ctx, &id, NULL);
    fail_if_error(table = crs_routing_table_new(node));
    add_prefix_to_table_with_proximity(ctx, table, ID_00, 2, 0);
    add_prefix_to_table_with_proximity(ctx, table, ID_00, 2, 1);
    /* The node with the smaller proximity metric should end up in the table */
    verify_routing_table(table,
        "[ 2/3] 003456789abcdef123456789abcdef12 local:2\n"
    );
    crs_routing_table_free(table);
    crs_ctx_free(ctx);
    fail_if_error(crs_finalize_tests());
}
END_TEST

START_TEST(test_routing_table_conflict_02)
{
    DESCRIBE_TEST;
    struct crs_id  id;
    struct crs_ctx  *ctx;
    struct crs_node  *node;
    struct crs_routing_table  *table;
    ctx = crs_ctx_new();
    crs_id_init(&id, ID_SELF);
    node = crs_node_new(ctx, &id, NULL);
    fail_if_error(table = crs_routing_table_new(node));
    add_prefix_to_table_with_proximity(ctx, table, ID_00, 2, 1);
    add_prefix_to_table_with_proximity(ctx, table, ID_00, 2, 0);
    /* The node with the smaller proximity metric should end up in the table */
    verify_routing_table(table,
        "[ 2/3] 003456789abcdef123456789abcdef12 local:3\n"
    );
    crs_routing_table_free(table);
    crs_ctx_free(ctx);
    fail_if_error(crs_finalize_tests());
}
END_TEST


/*-----------------------------------------------------------------------
 * Testing harness
 */

Suite *
test_suite()
{
    Suite  *s = suite_create("routing-table");

    TCase  *tc_routing = tcase_create("routing");
    tcase_add_test(tc_routing, test_routing_table_01);
    tcase_add_test(tc_routing, test_routing_table_02);
    tcase_add_test(tc_routing, test_routing_table_03);
    tcase_add_test(tc_routing, test_routing_table_04);
    tcase_add_test(tc_routing, test_routing_table_conflict_01);
    tcase_add_test(tc_routing, test_routing_table_conflict_02);
    suite_add_tcase(s, tc_routing);

    return s;
}


int
main(int argc, const char **argv)
{
    int  number_failed;
    Suite  *suite = test_suite();
    SRunner  *runner = srunner_create(suite);

    initialize_tests();
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (number_failed == 0)? EXIT_SUCCESS: EXIT_FAILURE;
}
