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

#include "croissant/local.h"
#include "croissant/node.h"
#include "helpers.h"


/*-----------------------------------------------------------------------
 * Local nodes
 */

START_TEST(test_local_nodes)
{
    DESCRIBE_TEST;
    struct crs_local_node_ctx  *ctx = crs_local_node_ctx_new();
    struct crs_local_node  *node = crs_local_node_ctx_add_node(ctx, "test");
    struct crs_node_ref  *ref = crs_local_node_get_ref(node);
    struct cork_buffer  address = CORK_BUFFER_INIT();
    struct cork_buffer  send_buf = CORK_BUFFER_INIT();
    struct cork_buffer  expected = CORK_BUFFER_INIT();
    struct cork_buffer  *received;

    cork_buffer_set_string(&expected, "local:0");
    fail_if_error(crs_node_ref_print_address(ref, &address));
    fail_unless(cork_buffer_equal(&address, &expected),
                "Node address doesn't match");

    cork_buffer_set_string(&send_buf, "awesome message");
    cork_buffer_set_string(&expected, "awesome message");

    fail_if(crs_local_node_has_messages(node),
            "Node should start off without messages");
    fail_unless_error(crs_local_node_peek_message(node),
                      "Shouldn't be able to peek nonexisting message");
    fail_unless_error(crs_local_node_pop_message(node),
                      "Shouldn't be able to pop nonexisting message");

    fail_if_error(crs_node_ref_send_message(ref, &send_buf));
    fail_unless(crs_local_node_has_messages(node),
                "Node should contain messages after send_message");

    fail_if_error(received = crs_local_node_peek_message(node));
    fail_unless(cork_buffer_equal(received, &expected),
                "Received message contents doesn't match");
    fail_if_error(crs_local_node_pop_message(node));

    fail_if(crs_local_node_has_messages(node),
            "Node shouldn't have messages after pop_message");

    cork_buffer_done(&address);
    cork_buffer_done(&send_buf);
    cork_buffer_done(&expected);
    crs_node_ref_free(ref);
    crs_local_node_ctx_free(ctx);
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
