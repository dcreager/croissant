/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012-2013, RedJack, LLC.
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
    struct crs_node  *node = crs_test_node_new(NULL, NULL);
    const struct crs_node_address  *address = crs_node_get_address(node);
    struct cork_buffer  actual = CORK_BUFFER_INIT();
    struct cork_buffer  send_buf = CORK_BUFFER_INIT();
    struct cork_buffer  expected = CORK_BUFFER_INIT();
    struct crs_application  *app =
        crs_save_message_application_new(10, &actual);
    struct crs_node_ref  *ref;

    fail_if_error(crs_node_add_application(node, app));

    cork_buffer_set_string(&expected, "local:1");
    fail_if_error(crs_node_address_print(&actual, address));
    fail_unless_buf_equal(&actual, &expected, "node addresses");

    cork_buffer_set(&expected, "\x01\xd3\xdf\xa1\x00\x00\x00\x01", 8);
    cork_buffer_clear(&actual);
    fail_if_error(crs_node_address_encode(address, &actual));
    fail_unless_buf_equal(&actual, &expected, "encoded node addresses");

    cork_buffer_set(&send_buf, "\x00\x00\x00\x0a", 4);
    cork_buffer_append_string(&send_buf, "awesome message");
    cork_buffer_set_string(&expected, "awesome message");
    fail_if_error(ref = crs_node_get_ref(node));
    fail_if_error(crs_node_ref_send(ref, node, send_buf.buf, send_buf.size));
    fail_unless_buf_equal(&actual, &expected, "received message content");

    cork_buffer_done(&actual);
    cork_buffer_done(&send_buf);
    cork_buffer_done(&expected);
    crs_node_free(node);
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
