/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2011-2014, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the COPYING file in this distribution for license details.
 * ----------------------------------------------------------------------
 */

#ifndef TESTS_HELPERS_H
#define TESTS_HELPERS_H

#include <clogger.h>
#include <libcork/core.h>

#if !defined(PRINT_EXPECTED_FAILURES)
#define PRINT_EXPECTED_FAILURES  1
#endif

#if PRINT_EXPECTED_FAILURES
#define print_expected_failure() \
    printf("[expected: %s]\n", cork_error_message());
#else
#define print_expected_failure()  /* do nothing */
#endif


#define DESCRIBE_TEST \
    fprintf(stderr, "--- %s\n", __func__);


#define fail_if_error(call) \
    do { \
        call; \
        if (cork_error_occurred()) { \
            fail("%s", cork_error_message()); \
        } \
    } while (0)

#define fail_unless_error(call, ...) \
    do { \
        call; \
        if (!cork_error_occurred()) { \
            fail(__VA_ARGS__); \
        } else { \
            print_expected_failure(); \
        } \
        cork_error_clear(); \
    } while (0)

#define fail_unless_equal(what, format, expected, actual) \
    (fail_unless((expected) == (actual), \
                 "%s not equal (expected " format \
                 ", got " format ")", \
                 (what), (expected), (actual)))

CORK_ATTR_UNUSED
static void
cork_buffer_print(struct cork_buffer *buf)
{
    size_t  i;
    const uint8_t  *bytes = buf->buf;
    for (i = 0; i < buf->size; i++) {
        if (i == 0) {
            fprintf(stderr, "  ");
        } else {
            if ((i % 16) == 0) {
                fprintf(stderr, "\n  ");
            } else if ((i % 8) == 0) {
                fprintf(stderr, " ");
            }
        }
        fprintf(stderr, " %02x", (unsigned int) bytes[i]);
    }
    fprintf(stderr, "\n");
}

CORK_ATTR_UNUSED
static void
fail_unless_buf_equal(struct cork_buffer *actual, struct cork_buffer *expected,
                      const char *description)
{
    if (CORK_UNLIKELY(!cork_buffer_equal(actual, expected))) {

        fprintf(stderr, "Expected:\n");
        cork_buffer_print(expected);
        fprintf(stderr, "Actual:\n");
        cork_buffer_print(actual);
        fail("Buffers don't match for %s", description);
    }
}


/* Use a custom allocator that debugs every allocation. */

static void
setup_allocator(void)
{
    struct cork_alloc  *debug = cork_debug_alloc_new(cork_allocator);
    cork_set_allocator(debug);
}

static void
initialize_tests(void)
{
    setup_allocator();
    if (clog_setup_logging() != 0) {
        fprintf(stderr, "Warning: %s\n", cork_error_message());
        cork_error_clear();
    }
}


#endif /* TESTS_HELPERS_H */
