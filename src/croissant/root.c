/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the COPYING file in this distribution for license details.
 * ----------------------------------------------------------------------
 */

#include <libcork/cli.h>
#include <libcork/core.h>

extern struct cork_command  croissant_test;

static struct cork_command  *subcommands[] = {
    &croissant_test,
    NULL
};

static struct cork_command  root =
    cork_command_set("croissant", NULL, NULL, subcommands);

int
main(int argc, char **argv)
{
    return cork_command_main(&root, argc, argv);
}
