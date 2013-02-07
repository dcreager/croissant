/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2011-2012, RedJack, LLC.
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
    struct crs_node  *node = crs_node_new(NULL);
    const struct crs_node_address  *address = crs_node_get_address(node);
    struct cork_buffer  actual = CORK_BUFFER_INIT();
    struct cork_buffer  send_buf = CORK_BUFFER_INIT();
    struct cork_buffer  expected = CORK_BUFFER_INIT();
    struct cork_buffer  *received;

    cork_buffer_set_string(&expected, "local:1");
    fail_if_error(crs_node_address_print(address, &actual));
    fail_unless(cork_buffer_equal(&actual, &expected),
                "Node address doesn't match");

    cork_buffer_set_string(&send_buf, "awesome message");
    cork_buffer_set_string(&expected, "awesome message");

    fail_if(crs_node_has_local_messages(node),
            "Node should start off without messages");
    fail_unless_error(crs_node_peek_local_message(node),
                      "Shouldn't be able to peek nonexisting message");
    fail_unless_error(crs_node_pop_local_message(node),
                      "Shouldn't be able to pop nonexisting message");

    fail_if_error(crs_node_send_message(address, send_buf.buf, send_buf.size));
    fail_unless(crs_node_has_local_messages(node),
                "Node should contain messages after send_message");

    fail_if_error(received = crs_node_peek_local_message(node));
    fail_unless(cork_buffer_equal(received, &expected),
                "Received message contents doesn't match");
    fail_if_error(crs_node_pop_local_message(node));

    fail_if(crs_node_has_local_messages(node),
            "Node shouldn't have messages after pop_message");

    cork_buffer_done(&actual);
    cork_buffer_done(&send_buf);
    cork_buffer_done(&expected);
    crs_node_address_free(address);
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

    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (number_failed == 0)? EXIT_SUCCESS: EXIT_FAILURE;
}
