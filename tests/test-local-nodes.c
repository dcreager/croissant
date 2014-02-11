/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012-2014, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <stdlib.h>
#include <stdio.h>

#include <check.h>
#include <libcork/core.h>
#include <libcork/ds.h>

#include "croissant.h"
#include "croissant/tests.h"
#include "helpers.h"


/*-----------------------------------------------------------------------
 * Local nodes
 */

START_TEST(test_local_nodes)
{
    DESCRIBE_TEST;
    crs_id  node_id = CRS_ID_ZERO;
    struct crs_ctx  *ctx = crs_ctx_new();
    struct crs_node  *node = crs_node_new(ctx, node_id, NULL);
    const struct crs_node_address  *address = crs_node_get_address(node);
    struct crs_message  *msg;
    struct cork_buffer  actual = CORK_BUFFER_INIT();
    struct cork_buffer  expected = CORK_BUFFER_INIT();
    struct crs_application  *app =
        crs_save_message_application_new(10, &actual);
    struct crs_node_ref  *ref;

    fail_if_error(crs_node_add_application(node, app));

    cork_buffer_set_string(&expected, "local:1");
    fail_if_error(crs_node_address_print(&actual, address));
    fail_unless_buf_equal(&actual, &expected, "node addresses");

    cork_buffer_set(&expected, "\x01\xd3\xdf\xa1\x00\x00\x00\x01", 8);
    msg = crs_node_new_message(node);
    crs_node_address_encode(msg, address);
    crs_message_to_buffer(&actual, msg);
    crs_node_free_message(node, msg);
    fail_unless_buf_equal(&actual, &expected, "encoded node addresses");

    msg = crs_node_new_message(node);
    crs_message_encode_uint32(msg, 10);  /* app ID */
    crs_message_encode_uint32(msg, 15);  /* message length */
    crs_message_encode_bytes(msg, "awesome message", 15);
    cork_buffer_set_string(&expected, "awesome message");
    fail_if_error(ref = crs_node_get_ref(node));
    fail_if_error(crs_node_ref_send(ref, node_id, node_id, msg));
    fail_unless_buf_equal(&actual, &expected, "received message content");

    cork_buffer_done(&actual);
    cork_buffer_done(&expected);
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
    Suite  *s = suite_create("local");

    TCase  *tc_local = tcase_create("local");
    tcase_add_test(tc_local, test_local_nodes);
    suite_add_tcase(s, tc_local);

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
