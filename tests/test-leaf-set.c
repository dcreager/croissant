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
 * Leaf set
 */

static void
verify_leaf_set(const struct crs_leaf_set *set, const char *expected)
{
    struct cork_buffer  actual = CORK_BUFFER_INIT();
    cork_buffer_set(&actual, "", 0);
    crs_leaf_set_print(&actual, set);
    if (strcmp(actual.buf, expected) != 0) {
        fprintf(stderr, "Expected:\n%s\nGot:\n%s",
                expected, (char *) actual.buf);
        cork_buffer_done(&actual);
        ck_abort_msg("Leaf sets not equal");
    } else {
        cork_buffer_done(&actual);
    }
}


static void
create_test_id(struct crs_id *id, unsigned int value)
{
    id->u128 = cork_u128_from_64(0, value);
}

static void
add_to_set(struct crs_ctx *ctx, struct crs_leaf_set *set, unsigned int value)
{
    struct crs_id  id;
    struct crs_node  *node;
    struct crs_node_ref  *ref;
    create_test_id(&id, value);
    node = crs_node_new(ctx, &id, NULL);
    ref = crs_node_get_ref(node);
    crs_leaf_set_add(set, ref);
}

START_TEST(test_leaf_set_01)
{
    DESCRIBE_TEST;
    struct crs_id  id;
    struct crs_ctx  *ctx;
    struct crs_node  *node;
    struct crs_leaf_set  *set;
    ctx = crs_ctx_new();
    create_test_id(&id, 100);
    node = crs_node_new(ctx, &id, NULL);
    fail_if_error(set = crs_leaf_set_new(node));
    verify_leaf_set(set,
        "[min] 00000000000000000000000000000064\n"
        "[  0] 00000000000000000000000000000064 local:1\n"
        "[max] 00000000000000000000000000000064\n"
    );
    crs_leaf_set_free(set);
    crs_ctx_free(ctx);
    fail_if_error(crs_finalize_tests());
}
END_TEST

START_TEST(test_leaf_set_02)
{
    DESCRIBE_TEST;
    struct crs_id  id;
    struct crs_ctx  *ctx;
    struct crs_node  *node;
    struct crs_leaf_set  *set;
    ctx = crs_ctx_new();
    create_test_id(&id, 100);
    node = crs_node_new(ctx, &id, NULL);
    fail_if_error(set = crs_leaf_set_new(node));
    add_to_set(ctx, set, 99);
    add_to_set(ctx, set, 101);
    verify_leaf_set(set,
        "[min] 00000000000000000000000000000063\n"
        "[- 1] 00000000000000000000000000000063 local:2\n"
        "[  0] 00000000000000000000000000000064 local:1\n"
        "[+ 1] 00000000000000000000000000000065 local:3\n"
        "[max] 00000000000000000000000000000065\n"
    );
    crs_leaf_set_free(set);
    crs_ctx_free(ctx);
    fail_if_error(crs_finalize_tests());
}
END_TEST

START_TEST(test_leaf_set_03)
{
    DESCRIBE_TEST;
    struct crs_id  id;
    struct crs_ctx  *ctx;
    struct crs_node  *node;
    struct crs_leaf_set  *set;
    ctx = crs_ctx_new();
    create_test_id(&id, 100);
    node = crs_node_new(ctx, &id, NULL);
    fail_if_error(set = crs_leaf_set_new(node));
    /* Insert the closest items last, so that we can test bubbling up existing
     * entries. */
    /* below */
    add_to_set(ctx, set, 94);
    add_to_set(ctx, set, 95);
    add_to_set(ctx, set, 96);
    add_to_set(ctx, set, 97);
    add_to_set(ctx, set, 98);
    add_to_set(ctx, set, 99);
    /* above */
    add_to_set(ctx, set, 106);
    add_to_set(ctx, set, 105);
    add_to_set(ctx, set, 104);
    add_to_set(ctx, set, 103);
    add_to_set(ctx, set, 102);
    add_to_set(ctx, set, 101);
    verify_leaf_set(set,
        "[min] 0000000000000000000000000000005e\n"
        "[- 6] 0000000000000000000000000000005e local:2\n"
        "[- 5] 0000000000000000000000000000005f local:3\n"
        "[- 4] 00000000000000000000000000000060 local:4\n"
        "[- 3] 00000000000000000000000000000061 local:5\n"
        "[- 2] 00000000000000000000000000000062 local:6\n"
        "[- 1] 00000000000000000000000000000063 local:7\n"
        "[  0] 00000000000000000000000000000064 local:1\n"
        "[+ 1] 00000000000000000000000000000065 local:13\n"
        "[+ 2] 00000000000000000000000000000066 local:12\n"
        "[+ 3] 00000000000000000000000000000067 local:11\n"
        "[+ 4] 00000000000000000000000000000068 local:10\n"
        "[+ 5] 00000000000000000000000000000069 local:9\n"
        "[+ 6] 0000000000000000000000000000006a local:8\n"
        "[max] 0000000000000000000000000000006a\n"
    );
    crs_leaf_set_free(set);
    crs_ctx_free(ctx);
    fail_if_error(crs_finalize_tests());
}
END_TEST

START_TEST(test_leaf_set_04)
{
    DESCRIBE_TEST;
    unsigned int  i;
    struct crs_id  id;
    struct crs_ctx  *ctx;
    struct crs_node  *node;
    struct crs_leaf_set  *set;
    ctx = crs_ctx_new();
    create_test_id(&id, 100);
    node = crs_node_new(ctx, &id, NULL);
    fail_if_error(set = crs_leaf_set_new(node));
    /* Test inserting into a full set */
    for (i = 100 - CRS_LEAF_SET_SIZE - 3; i < 100; i++) {
        add_to_set(ctx, set, i);
    }
    for (i = 100 + CRS_LEAF_SET_SIZE + 3; --i > 100; ) {
        add_to_set(ctx, set, i);
    }
    verify_leaf_set(set,
        "[min] 00000000000000000000000000000054\n"
        "[-16] 00000000000000000000000000000054 local:5\n"
        "[-15] 00000000000000000000000000000055 local:6\n"
        "[-14] 00000000000000000000000000000056 local:7\n"
        "[-13] 00000000000000000000000000000057 local:8\n"
        "[-12] 00000000000000000000000000000058 local:9\n"
        "[-11] 00000000000000000000000000000059 local:10\n"
        "[-10] 0000000000000000000000000000005a local:11\n"
        "[- 9] 0000000000000000000000000000005b local:12\n"
        "[- 8] 0000000000000000000000000000005c local:13\n"
        "[- 7] 0000000000000000000000000000005d local:14\n"
        "[- 6] 0000000000000000000000000000005e local:15\n"
        "[- 5] 0000000000000000000000000000005f local:16\n"
        "[- 4] 00000000000000000000000000000060 local:17\n"
        "[- 3] 00000000000000000000000000000061 local:18\n"
        "[- 2] 00000000000000000000000000000062 local:19\n"
        "[- 1] 00000000000000000000000000000063 local:20\n"
        "[  0] 00000000000000000000000000000064 local:1\n"
        "[+ 1] 00000000000000000000000000000065 local:38\n"
        "[+ 2] 00000000000000000000000000000066 local:37\n"
        "[+ 3] 00000000000000000000000000000067 local:36\n"
        "[+ 4] 00000000000000000000000000000068 local:35\n"
        "[+ 5] 00000000000000000000000000000069 local:34\n"
        "[+ 6] 0000000000000000000000000000006a local:33\n"
        "[+ 7] 0000000000000000000000000000006b local:32\n"
        "[+ 8] 0000000000000000000000000000006c local:31\n"
        "[+ 9] 0000000000000000000000000000006d local:30\n"
        "[+10] 0000000000000000000000000000006e local:29\n"
        "[+11] 0000000000000000000000000000006f local:28\n"
        "[+12] 00000000000000000000000000000070 local:27\n"
        "[+13] 00000000000000000000000000000071 local:26\n"
        "[+14] 00000000000000000000000000000072 local:25\n"
        "[+15] 00000000000000000000000000000073 local:24\n"
        "[+16] 00000000000000000000000000000074 local:23\n"
        "[max] 00000000000000000000000000000074\n"
    );
    crs_leaf_set_free(set);
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
    Suite  *s = suite_create("leaf-set");

    TCase  *tc_leaf = tcase_create("leaf");
    tcase_add_test(tc_leaf, test_leaf_set_01);
    tcase_add_test(tc_leaf, test_leaf_set_02);
    tcase_add_test(tc_leaf, test_leaf_set_03);
    tcase_add_test(tc_leaf, test_leaf_set_04);
    suite_add_tcase(s, tc_leaf);

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
