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

#include "croissant.h"
#include "helpers.h"


/*-----------------------------------------------------------------------
 * Pastry identifiers
 */

START_TEST(test_id)
{
    DESCRIBE_TEST;
    struct crs_id  expected =
    { cork_u128_from_32(0x00010203, 0x04050607, 0x08090a0b, 0x0c0d0e0f) };

    struct crs_id  actual;
    static const char  *SRC1 = "000102030405060708090a0b0c0d0e0f";
    static const char  *SRC2 = "000102030405060708090A0B0C0D0E0F";

    /* too short */
    static const char  *BAD_SRC1 = "000102030405060708090a0b0";
    /* illegal character */
    static const char  *BAD_SRC2 = "000102030405060x08090A0B0C0D0E0F";

    char  str[CRS_ID_STRING_LENGTH];

    fail_if_error(crs_id_init(&actual, SRC1));
    fail_unless(crs_id_equals(&actual, &expected),
                "Identifiers not equal");
    crs_id_to_raw_string(&actual, str);
    fail_unless(strcmp(str, SRC1) == 0,
                "String representations not equal\nExpected %s\nGot      %s",
                SRC1, str);

    fail_if_error(crs_id_init(&actual, SRC2));
    fail_unless(crs_id_equals(&actual, &expected),
                "Identifiers not equal");
    crs_id_to_raw_string(&actual, str);
    fail_unless(strcmp(str, SRC1) == 0,
                "String representations not equal\nExpected %s\nGot      %s",
                SRC1, str);

    fail_unless_error(crs_id_init(&actual, BAD_SRC1),
                      "Expected parse error");
    fail_unless_error(crs_id_init(&actual, BAD_SRC2),
                      "Expected parse error");
}
END_TEST


START_TEST(test_get_nybble)
{
    DESCRIBE_TEST;
    static const char  *SRC1 = "0123456789abcdef01233210fedcba98";
    struct crs_id  id;
    fail_if_error(crs_id_init(&id, SRC1));

    char  str[CRS_ID_STRING_LENGTH];
    crs_id_to_raw_string(&id, str);

    unsigned int  expected[] =
    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
      0, 1, 2, 3, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8 };

    unsigned int  i;
    for (i = 0; i < CRS_ID_NYBBLE_LENGTH; i++) {
        fail_unless(crs_id_get_nybble(&id, i) == expected[i],
                    "Unexpected value for nybble %u: "
                    "got 0x%x, expected 0x%x",
                    i, crs_id_get_nybble(&id, i), expected[i]);
    }
}
END_TEST


START_TEST(test_get_msdd)
{
    DESCRIBE_TEST;
    static const char  *SRC1 = "00000000000000000000000000000000";
    struct crs_id  id1;
    fail_if_error(crs_id_init(&id1, SRC1));

    char  SRC2[CRS_ID_STRING_LENGTH];
    char  SRC3[CRS_ID_STRING_LENGTH];

    int  expected;
    for (expected = -1; expected < CRS_ID_NYBBLE_LENGTH; expected++) {
        unsigned int  i;
        for (i = 0; i < CRS_ID_STRING_LENGTH-1; i++) {
            SRC2[i] = (i >= expected)? '1': '0';
            SRC3[i] = (i == expected)? '1': '0';
        }
        SRC2[CRS_ID_STRING_LENGTH-1] = '\0';
        SRC3[CRS_ID_STRING_LENGTH-1] = '\0';

        //printf("<%s> <%s>: %d?\n", SRC1, SRC2, expected);
        struct crs_id  id2;
        fail_if_error(crs_id_init(&id2, SRC2));
        int  actual2 = crs_id_get_msdd(&id1, &id2);
        fail_unless(actual2 == expected,
                    "Unexpected MSDD: got %d, expected %d",
                    actual2, expected);

        //printf("<%s> <%s>: %d?\n", SRC1, SRC3, expected);
        struct crs_id  id3;
        fail_if_error(crs_id_init(&id3, SRC3));
        int  actual3 = crs_id_get_msdd(&id1, &id3);
        fail_unless(actual3 == expected,
                    "Unexpected MSDD: got %d, expected %d",
                    actual3, expected);
    }
}
END_TEST


static void
test_one_cw(const char *a_str, const char *b_str, bool expected)
{
    bool  actual;
    struct crs_id  a;
    struct crs_id  b;
    fail_if_error(crs_id_init(&a, a_str));
    fail_if_error(crs_id_init(&b, b_str));
    actual = crs_id_is_cw(a, b);
    fail_unless(actual == expected,
                "%s should %sbe clockwise of %s",
                a_str, expected? "": "not ", b_str);
}

static void
test_one_ccw(const char *a_str, const char *b_str, bool expected)
{
    bool  actual;
    struct crs_id  a;
    struct crs_id  b;
    fail_if_error(crs_id_init(&a, a_str));
    fail_if_error(crs_id_init(&b, b_str));
    actual = crs_id_is_ccw(a, b);
    fail_unless(actual == expected,
                "%s should %sbe counter-clockwise of %s",
                a_str, expected? "": "not ", b_str);
}

struct compare_test {
    const char  *minus2;
    const char  *minus1;
    const char  *base;
    const char  *plus1;
    const char  *plus2;

    const char  *dual_minus2;
    const char  *dual_minus1;
    const char  *dual;
    const char  *dual_plus1;
    const char  *dual_plus2;
};

static void
test_one_compare(struct compare_test *compare)
{
    test_one_cw(compare->base, compare->minus2,      true);
    test_one_cw(compare->base, compare->minus1,      true);
    test_one_cw(compare->base, compare->base,        true);
    test_one_cw(compare->base, compare->plus1,       false);
    test_one_cw(compare->base, compare->plus2,       false);
    test_one_cw(compare->base, compare->dual_minus2, false);
    test_one_cw(compare->base, compare->dual_minus1, false);
    test_one_cw(compare->base, compare->dual,        false);
    test_one_cw(compare->base, compare->dual_plus1,  true);
    test_one_cw(compare->base, compare->dual_plus2,  true);

    test_one_ccw(compare->base, compare->minus2,      false);
    test_one_ccw(compare->base, compare->minus1,      false);
    test_one_ccw(compare->base, compare->base,        false);
    test_one_ccw(compare->base, compare->plus1,       true);
    test_one_ccw(compare->base, compare->plus2,       true);
    test_one_ccw(compare->base, compare->dual_minus2, true);
    test_one_ccw(compare->base, compare->dual_minus1, true);
    test_one_ccw(compare->base, compare->dual,        true);
    test_one_ccw(compare->base, compare->dual_plus1,  false);
    test_one_ccw(compare->base, compare->dual_plus2,  false);
}

#define test_compare(id) \
static struct compare_test  TEST_##id; \
\
START_TEST(test_compare_##id) \
{ \
    DESCRIBE_TEST; \
    test_one_compare(&TEST_##id); \
} \
END_TEST \
\
static struct compare_test  TEST_##id =


test_compare(id_00) {
    /* base */
    "fffffffffffffffffffffffffffffffe",
    "ffffffffffffffffffffffffffffffff",
    "00000000000000000000000000000000",
    "00000000000000000000000000000001",
    "00000000000000000000000000000002",
    /* dual */
    "7ffffffffffffffffffffffffffffffe",
    "7fffffffffffffffffffffffffffffff",
    "80000000000000000000000000000000",
    "80000000000000000000000000000001",
    "80000000000000000000000000000002"
};

test_compare(id_08) {
    /* base */
    "00000000000000007ffffffffffffffe",
    "00000000000000007fffffffffffffff",
    "00000000000000008000000000000000",
    "00000000000000008000000000000001",
    "00000000000000008000000000000002",
    /* dual */
    "80000000000000007ffffffffffffffe",
    "80000000000000007fffffffffffffff",
    "80000000000000008000000000000000",
    "80000000000000008000000000000001",
    "80000000000000008000000000000002"
};

test_compare(id_80) {
    /* base */
    "7ffffffffffffffffffffffffffffffe",
    "7fffffffffffffffffffffffffffffff",
    "80000000000000000000000000000000",
    "80000000000000000000000000000001",
    "80000000000000000000000000000002",
    /* dual */
    "fffffffffffffffffffffffffffffffe",
    "ffffffffffffffffffffffffffffffff",
    "00000000000000000000000000000000",
    "00000000000000000000000000000001",
    "00000000000000000000000000000002"
};


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
    tcase_add_test(tc_id, test_compare_id_00);
    tcase_add_test(tc_id, test_compare_id_08);
    tcase_add_test(tc_id, test_compare_id_80);
    suite_add_tcase(s, tc_id);

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
