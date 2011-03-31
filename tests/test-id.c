/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2011, RedJack, LLC.
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

#include "dunkin/id.h"


/*-----------------------------------------------------------------------
 * Pastry identifiers
 */

START_TEST(test_id)
{
    cork_context_t  *ctx = cork_context_new_with_debug_allocator();

    dunkin_id_t  expected =
    {{ 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
       0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f }};

    dunkin_id_t  actual;
    static const char  *SRC1 = "000102030405060708090a0b0c0d0e0f";
    //static const char  *SRC2 = "000102030405060708090A0B0C0D0E0F";

    char  str[DUNKIN_ID_STRING_LENGTH];

    fail_unless(dunkin_id_init(ctx, &actual, SRC1),
                "Cannot parse first identifier");
    fail_unless(dunkin_id_equals(&actual, &expected),
                "Identifiers not equal");
    dunkin_id_to_raw_string(ctx, &actual, str);
    fail_unless(strcmp(str, SRC1) == 0,
                "String representations not equal");

    cork_context_free(ctx);
}
END_TEST


/*-----------------------------------------------------------------------
 * Testing harness
 */

Suite *
test_suite()
{
    Suite  *s = suite_create("id");

    TCase  *tc_id = tcase_create("id");
    tcase_add_test(tc_id, test_id);
    suite_add_tcase(s, tc_id);

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