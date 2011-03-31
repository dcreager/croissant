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


START_TEST(test_get_nybble)
{
    cork_context_t  *ctx = cork_context_new_with_debug_allocator();

    static const char  *SRC1 = "0123456789abcdeffedcba9876543210";
    dunkin_id_t  id;
    dunkin_id_init(ctx, &id, SRC1);

    unsigned int  expected[] =
    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
      15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

    unsigned int  i;
    for (i = 0; i < DUNKIN_ID_NYBBLE_LENGTH; i++) {
        fail_unless(dunkin_id_get_nybble(&id, i) == expected[i],
                    "Unexpected value for nybble %u: "
                    "got 0x%x, expected 0x%x",
                    i, dunkin_id_get_nybble(&id, i), expected[i]);
    }

    cork_context_free(ctx);
}
END_TEST


START_TEST(test_get_msdd)
{
    cork_context_t  *ctx = cork_context_new_with_debug_allocator();

    static const char  *SRC1 = "00000000000000000000000000000000";
    dunkin_id_t  id1;
    dunkin_id_init(ctx, &id1, SRC1);

    char  SRC2[DUNKIN_ID_STRING_LENGTH];
    char  SRC3[DUNKIN_ID_STRING_LENGTH];

    int  expected;
    for (expected = -1; expected < DUNKIN_ID_NYBBLE_LENGTH; expected++) {
        unsigned int  i;
        for (i = 0; i < DUNKIN_ID_STRING_LENGTH-1; i++) {
            SRC2[i] = (i >= expected)? '1': '0';
            SRC3[i] = (i == expected)? '1': '0';
        }
        SRC2[DUNKIN_ID_STRING_LENGTH-1] = '\0';
        SRC3[DUNKIN_ID_STRING_LENGTH-1] = '\0';

        //printf("<%s> <%s>: %d?\n", SRC1, SRC2, expected);
        dunkin_id_t  id2;
        dunkin_id_init(ctx, &id2, SRC2);
        int  actual2 = dunkin_id_get_msdd(&id1, &id2);
        fail_unless(actual2 == expected,
                    "Unexpected MSDD: got %d, expected %d",
                    actual2, expected);

        //printf("<%s> <%s>: %d?\n", SRC1, SRC3, expected);
        dunkin_id_t  id3;
        dunkin_id_init(ctx, &id3, SRC3);
        int  actual3 = dunkin_id_get_msdd(&id1, &id3);
        fail_unless(actual3 == expected,
                    "Unexpected MSDD: got %d, expected %d",
                    actual3, expected);
    }

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
    tcase_add_test(tc_id, test_get_nybble);
    tcase_add_test(tc_id, test_get_msdd);
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
