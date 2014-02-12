
#line 1 "croissant/test.c.rl"
/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013-2014, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <stdlib.h>

#include <clogger.h>
#include <libcork/core.h>
#include <libcork/cli.h>
#include <libcork/ds.h>
#include <libcork/helpers/errors.h>

#include "croissant.h"
#include "croissant/tests.h"

static struct crs_node *
crs_ctx_require_node(struct crs_ctx *ctx, crs_id id)
{
    struct crs_node  *node = crs_ctx_get_node_with_id(ctx, id);
    if (node == NULL) {
        char  id_str[CRS_ID_STRING_LENGTH];
        crs_id_to_raw_string(id_str, id);
        crs_parse_error("No node %s", id_str);
    }
    return node;
}

static int
crs_parse_command(struct crs_ctx *ctx, const char *command)
{
    int  cs;
    const char  *p = command;
    const char  *pe = strchr(command, '\0');
    const char  *eof = pe;
    const char  *start;

    struct cork_buffer  buf = CORK_BUFFER_INIT();
    struct cork_buffer  message = CORK_BUFFER_INIT();
    struct cork_buffer  output = CORK_BUFFER_INIT();
    struct crs_node  *node;
    crs_id  id1;
    char  id1_str[CRS_ID_STRING_LENGTH];

    
#line 54 "croissant/test.c"
static const int crs_command_start = 655;

static const int crs_command_en_main = 655;


#line 60 "croissant/test.c"
	{
	cs = crs_command_start;
	}

#line 65 "croissant/test.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr43:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 64 "croissant/test.c.rl"
	{
                struct crs_print_message  *printer;
                fprintf(stderr, "--- new node %s\n",
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(node = crs_node_new(ctx, id1, NULL));
                printer = crs_print_message_new(stderr);
                rii_check(crs_print_message_register(printer, node));
            }
	goto st655;
st655:
	if ( ++p == pe )
		goto _test_eof655;
case 655:
#line 90 "croissant/test.c"
	switch( (*p) ) {
		case 32: goto st655;
		case 110: goto st1;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st655;
	goto st0;
st0:
cs = 0;
	goto _out;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	switch( (*p) ) {
		case 101: goto st2;
		case 111: goto st43;
	}
	goto st0;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 119 )
		goto st3;
	goto st0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) == 32 )
		goto st4;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st4;
	goto st0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	switch( (*p) ) {
		case 32: goto st4;
		case 110: goto st5;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st4;
	goto st0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 111 )
		goto st6;
	goto st0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 100 )
		goto st7;
	goto st0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	if ( (*p) == 101 )
		goto st8;
	goto st0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( (*p) == 32 )
		goto st9;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st9;
	goto st0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( (*p) == 32 )
		goto st9;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st9;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto tr10;
		} else if ( (*p) >= 65 )
			goto tr10;
	} else
		goto tr10;
	goto st0;
tr10:
#line 55 "croissant/test.c.rl"
	{ start = p; }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 193 "croissant/test.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st11;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st11;
	} else
		goto st11;
	goto st0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st12;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st12;
	} else
		goto st12;
	goto st0;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st13;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st13;
	} else
		goto st13;
	goto st0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st14;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st14;
	} else
		goto st14;
	goto st0;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st15;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st15;
	} else
		goto st15;
	goto st0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st16;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st16;
	} else
		goto st16;
	goto st0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st17;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st17;
	} else
		goto st17;
	goto st0;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st18;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st18;
	} else
		goto st18;
	goto st0;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st19;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st19;
	} else
		goto st19;
	goto st0;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st20;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st20;
	} else
		goto st20;
	goto st0;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st21;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st21;
	} else
		goto st21;
	goto st0;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st22;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st22;
	} else
		goto st22;
	goto st0;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st23;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st23;
	} else
		goto st23;
	goto st0;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st24;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st24;
	} else
		goto st24;
	goto st0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st25;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st25;
	} else
		goto st25;
	goto st0;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st26;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st26;
	} else
		goto st26;
	goto st0;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st27;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st27;
	} else
		goto st27;
	goto st0;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st28;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st28;
	} else
		goto st28;
	goto st0;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st29;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st29;
	} else
		goto st29;
	goto st0;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st30;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st30;
	} else
		goto st30;
	goto st0;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st31;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st31;
	} else
		goto st31;
	goto st0;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st32;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st32;
	} else
		goto st32;
	goto st0;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st33;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st33;
	} else
		goto st33;
	goto st0;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st34;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st34;
	} else
		goto st34;
	goto st0;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st35;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st35;
	} else
		goto st35;
	goto st0;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st36;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st36;
	} else
		goto st36;
	goto st0;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st37;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st37;
	} else
		goto st37;
	goto st0;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st38;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st38;
	} else
		goto st38;
	goto st0;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st39;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st39;
	} else
		goto st39;
	goto st0;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st40;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st40;
	} else
		goto st40;
	goto st0;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st41;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st41;
	} else
		goto st41;
	goto st0;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	switch( (*p) ) {
		case 32: goto tr42;
		case 59: goto tr43;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr42;
	goto st0;
tr42:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 64 "croissant/test.c.rl"
	{
                struct crs_print_message  *printer;
                fprintf(stderr, "--- new node %s\n",
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(node = crs_node_new(ctx, id1, NULL));
                printer = crs_print_message_new(stderr);
                rii_check(crs_print_message_register(printer, node));
            }
	goto st42;
tr141:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 76 "croissant/test.c.rl"
	{
                struct crs_leaf_set  *from_set;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                fprintf(stderr, "--- [%s]\n--- add leaf set entry %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(to_node = crs_ctx_require_node(ctx, id1));
                from_set = crs_node_get_leaf_set(node);
                to_ref = crs_node_new_ref(node, crs_node_get_address(to_node));
                crs_leaf_set_add(from_set, to_ref);
            }
	goto st42;
tr195:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 92 "croissant/test.c.rl"
	{
                struct crs_routing_table  *from_table;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                fprintf(stderr, "--- [%s]\n--- add routing table entry %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(to_node = crs_ctx_require_node(ctx, id1));
                from_table = crs_node_get_routing_table(node);
                to_ref = crs_node_new_ref(node, crs_node_get_address(to_node));
                crs_routing_table_set(from_table, to_ref);
            }
	goto st42;
tr216:
#line 107 "croissant/test.c.rl"
	{
                fprintf(stderr, "--- [%s]\n--- create empty network\n",
                        crs_node_get_id_str(node));
                rii_check(crs_node_bootstrap(node, NULL));
            }
	goto st42;
tr266:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 115 "croissant/test.c.rl"
	{
                struct crs_node  *bootstrap_node;
                const struct crs_node_address  *bootstrap_address;
                fprintf(stderr, "--- [%s]\n--- join network via %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(bootstrap_node = crs_ctx_require_node(ctx, id1));
                bootstrap_address = crs_node_get_address(bootstrap_node);
                rii_check(crs_node_bootstrap(node, bootstrap_address));
            }
	goto st42;
tr283:
#line 128 "croissant/test.c.rl"
	{
                struct crs_leaf_set  *set;
                fprintf(stderr, "--- [%s]\n--- print leaf set\n",
                        crs_node_get_id_str(node));
                set = crs_node_get_leaf_set(node);
                cork_buffer_printf
                    (&output, "Leaf set for %s\n", crs_node_get_id_str(node));
                crs_leaf_set_print(&output, set);
                fwrite(output.buf, output.size, 1, stderr);
            }
	goto st42;
tr329:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 142 "croissant/test.c.rl"
	{
                struct crs_node_ref  *next_hop;
                fprintf(stderr, "--- [%s]\n--- print next hop for %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(next_hop = crs_node_get_next_hop(node, id1));
                fprintf
                    (stderr,
                     "Next hop from %s\n"
                     "           to %s\n"
                     "           is %s\n",
                     crs_node_get_id_str(node),
                     crs_id_to_raw_string(id1_str, id1),
                     (next_hop == CRS_NODE_REF_SELF)? "local delivery":
                         crs_node_ref_get_id_str(next_hop));
            }
	goto st42;
tr343:
#line 161 "croissant/test.c.rl"
	{
                struct crs_routing_table  *table;
                fprintf(stderr, "--- [%s]\n--- print routing table\n",
                        crs_node_get_id_str(node));
                table = crs_node_get_routing_table(node);
                cork_buffer_printf
                    (&output, "Routing table for %s\n",
                     crs_node_get_id_str(node));
                crs_routing_table_print(&output, table);
                fwrite(output.buf, output.size, 1, stderr);
            }
	goto st42;
tr388:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 175 "croissant/test.c.rl"
	{
                struct crs_print_message  *printer;
                rip_check(printer = crs_print_message_get(node));
                fprintf(stderr, "--- [%s]\n--- send \"%s\" to %s\n",
                        crs_node_get_id_str(node),
                        (char *) message.buf,
                        crs_id_to_raw_string(id1_str, id1));
                rii_check(crs_print_message_send(printer, id1, message.buf));
            }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 752 "croissant/test.c"
	switch( (*p) ) {
		case 32: goto st42;
		case 59: goto st655;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st42;
	goto st0;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	if ( (*p) == 100 )
		goto st44;
	goto st0;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	if ( (*p) == 101 )
		goto st45;
	goto st0;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	if ( (*p) == 32 )
		goto st46;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st46;
	goto st0;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	if ( (*p) == 32 )
		goto st46;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st46;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto tr49;
		} else if ( (*p) >= 65 )
			goto tr49;
	} else
		goto tr49;
	goto st0;
tr49:
#line 55 "croissant/test.c.rl"
	{ start = p; }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 809 "croissant/test.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st48;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st48;
	} else
		goto st48;
	goto st0;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st49;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st49;
	} else
		goto st49;
	goto st0;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st50;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st50;
	} else
		goto st50;
	goto st0;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st51;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st51;
	} else
		goto st51;
	goto st0;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st52;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st52;
	} else
		goto st52;
	goto st0;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st53;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st53;
	} else
		goto st53;
	goto st0;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st54;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st54;
	} else
		goto st54;
	goto st0;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st55;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st55;
	} else
		goto st55;
	goto st0;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st56;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st56;
	} else
		goto st56;
	goto st0;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st57;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st57;
	} else
		goto st57;
	goto st0;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st58;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st58;
	} else
		goto st58;
	goto st0;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st59;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st59;
	} else
		goto st59;
	goto st0;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st60;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st60;
	} else
		goto st60;
	goto st0;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st61;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st61;
	} else
		goto st61;
	goto st0;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st62;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st62;
	} else
		goto st62;
	goto st0;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st63;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st63;
	} else
		goto st63;
	goto st0;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st64;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st64;
	} else
		goto st64;
	goto st0;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st65;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st65;
	} else
		goto st65;
	goto st0;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st66;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st66;
	} else
		goto st66;
	goto st0;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st67;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st67;
	} else
		goto st67;
	goto st0;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st68;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st68;
	} else
		goto st68;
	goto st0;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st69;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st69;
	} else
		goto st69;
	goto st0;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st70;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st70;
	} else
		goto st70;
	goto st0;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st71;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st71;
	} else
		goto st71;
	goto st0;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st72;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st72;
	} else
		goto st72;
	goto st0;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st73;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st73;
	} else
		goto st73;
	goto st0;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st74;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st74;
	} else
		goto st74;
	goto st0;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st75;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st75;
	} else
		goto st75;
	goto st0;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st76;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st76;
	} else
		goto st76;
	goto st0;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st77;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st77;
	} else
		goto st77;
	goto st0;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st78;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st78;
	} else
		goto st78;
	goto st0;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	if ( (*p) == 32 )
		goto tr81;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr81;
	goto st0;
tr81:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 200 "croissant/test.c.rl"
	{ rip_check(node = crs_ctx_require_node(ctx, id1)); }
	goto st79;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
#line 1230 "croissant/test.c"
	switch( (*p) ) {
		case 32: goto st79;
		case 97: goto st80;
		case 99: goto st184;
		case 106: goto st204;
		case 112: goto st253;
		case 115: goto st325;
		case 123: goto st367;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st79;
	goto st0;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	if ( (*p) == 100 )
		goto st81;
	goto st0;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	if ( (*p) == 100 )
		goto st82;
	goto st0;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	if ( (*p) == 32 )
		goto st83;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st83;
	goto st0;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	switch( (*p) ) {
		case 32: goto st83;
		case 108: goto st84;
		case 114: goto st132;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st83;
	goto st0;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	if ( (*p) == 101 )
		goto st85;
	goto st0;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	if ( (*p) == 97 )
		goto st86;
	goto st0;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( (*p) == 102 )
		goto st87;
	goto st0;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) == 32 )
		goto st88;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st88;
	goto st0;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	switch( (*p) ) {
		case 32: goto st88;
		case 115: goto st89;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st88;
	goto st0;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	if ( (*p) == 101 )
		goto st90;
	goto st0;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	if ( (*p) == 116 )
		goto st91;
	goto st0;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	if ( (*p) == 32 )
		goto st92;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st92;
	goto st0;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 32: goto st92;
		case 101: goto st93;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st92;
	goto st0;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	if ( (*p) == 110 )
		goto st94;
	goto st0;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	if ( (*p) == 116 )
		goto st95;
	goto st0;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	if ( (*p) == 114 )
		goto st96;
	goto st0;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	if ( (*p) == 121 )
		goto st97;
	goto st0;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	if ( (*p) == 32 )
		goto st98;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st98;
	goto st0;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	if ( (*p) == 32 )
		goto st98;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st98;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto tr108;
		} else if ( (*p) >= 65 )
			goto tr108;
	} else
		goto tr108;
	goto st0;
tr108:
#line 55 "croissant/test.c.rl"
	{ start = p; }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
#line 1416 "croissant/test.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st100;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st100;
	} else
		goto st100;
	goto st0;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st101;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st101;
	} else
		goto st101;
	goto st0;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st102;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st102;
	} else
		goto st102;
	goto st0;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st103;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st103;
	} else
		goto st103;
	goto st0;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st104;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st104;
	} else
		goto st104;
	goto st0;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st105;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st105;
	} else
		goto st105;
	goto st0;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st106;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st106;
	} else
		goto st106;
	goto st0;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st107;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st107;
	} else
		goto st107;
	goto st0;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st108;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st108;
	} else
		goto st108;
	goto st0;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st109;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st109;
	} else
		goto st109;
	goto st0;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st110;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st110;
	} else
		goto st110;
	goto st0;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st111;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st111;
	} else
		goto st111;
	goto st0;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st112;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st112;
	} else
		goto st112;
	goto st0;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st113;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st113;
	} else
		goto st113;
	goto st0;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st114;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st114;
	} else
		goto st114;
	goto st0;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st115;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st115;
	} else
		goto st115;
	goto st0;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st116;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st116;
	} else
		goto st116;
	goto st0;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st117;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st117;
	} else
		goto st117;
	goto st0;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st118;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st118;
	} else
		goto st118;
	goto st0;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st119;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st119;
	} else
		goto st119;
	goto st0;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st120;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st120;
	} else
		goto st120;
	goto st0;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st121;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st121;
	} else
		goto st121;
	goto st0;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st122;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st122;
	} else
		goto st122;
	goto st0;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st123;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st123;
	} else
		goto st123;
	goto st0;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st124;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st124;
	} else
		goto st124;
	goto st0;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st125;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st125;
	} else
		goto st125;
	goto st0;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st126;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st126;
	} else
		goto st126;
	goto st0;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st127;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st127;
	} else
		goto st127;
	goto st0;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st128;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st128;
	} else
		goto st128;
	goto st0;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st129;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st129;
	} else
		goto st129;
	goto st0;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st130;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st130;
	} else
		goto st130;
	goto st0;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	switch( (*p) ) {
		case 32: goto tr140;
		case 59: goto tr141;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr140;
	goto st0;
tr140:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 76 "croissant/test.c.rl"
	{
                struct crs_leaf_set  *from_set;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                fprintf(stderr, "--- [%s]\n--- add leaf set entry %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(to_node = crs_ctx_require_node(ctx, id1));
                from_set = crs_node_get_leaf_set(node);
                to_ref = crs_node_new_ref(node, crs_node_get_address(to_node));
                crs_leaf_set_add(from_set, to_ref);
            }
	goto st131;
tr194:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 92 "croissant/test.c.rl"
	{
                struct crs_routing_table  *from_table;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                fprintf(stderr, "--- [%s]\n--- add routing table entry %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(to_node = crs_ctx_require_node(ctx, id1));
                from_table = crs_node_get_routing_table(node);
                to_ref = crs_node_new_ref(node, crs_node_get_address(to_node));
                crs_routing_table_set(from_table, to_ref);
            }
	goto st131;
tr215:
#line 107 "croissant/test.c.rl"
	{
                fprintf(stderr, "--- [%s]\n--- create empty network\n",
                        crs_node_get_id_str(node));
                rii_check(crs_node_bootstrap(node, NULL));
            }
	goto st131;
tr265:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 115 "croissant/test.c.rl"
	{
                struct crs_node  *bootstrap_node;
                const struct crs_node_address  *bootstrap_address;
                fprintf(stderr, "--- [%s]\n--- join network via %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(bootstrap_node = crs_ctx_require_node(ctx, id1));
                bootstrap_address = crs_node_get_address(bootstrap_node);
                rii_check(crs_node_bootstrap(node, bootstrap_address));
            }
	goto st131;
tr282:
#line 128 "croissant/test.c.rl"
	{
                struct crs_leaf_set  *set;
                fprintf(stderr, "--- [%s]\n--- print leaf set\n",
                        crs_node_get_id_str(node));
                set = crs_node_get_leaf_set(node);
                cork_buffer_printf
                    (&output, "Leaf set for %s\n", crs_node_get_id_str(node));
                crs_leaf_set_print(&output, set);
                fwrite(output.buf, output.size, 1, stderr);
            }
	goto st131;
tr328:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 142 "croissant/test.c.rl"
	{
                struct crs_node_ref  *next_hop;
                fprintf(stderr, "--- [%s]\n--- print next hop for %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(next_hop = crs_node_get_next_hop(node, id1));
                fprintf
                    (stderr,
                     "Next hop from %s\n"
                     "           to %s\n"
                     "           is %s\n",
                     crs_node_get_id_str(node),
                     crs_id_to_raw_string(id1_str, id1),
                     (next_hop == CRS_NODE_REF_SELF)? "local delivery":
                         crs_node_ref_get_id_str(next_hop));
            }
	goto st131;
tr342:
#line 161 "croissant/test.c.rl"
	{
                struct crs_routing_table  *table;
                fprintf(stderr, "--- [%s]\n--- print routing table\n",
                        crs_node_get_id_str(node));
                table = crs_node_get_routing_table(node);
                cork_buffer_printf
                    (&output, "Routing table for %s\n",
                     crs_node_get_id_str(node));
                crs_routing_table_print(&output, table);
                fwrite(output.buf, output.size, 1, stderr);
            }
	goto st131;
tr387:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 175 "croissant/test.c.rl"
	{
                struct crs_print_message  *printer;
                rip_check(printer = crs_print_message_get(node));
                fprintf(stderr, "--- [%s]\n--- send \"%s\" to %s\n",
                        crs_node_get_id_str(node),
                        (char *) message.buf,
                        crs_id_to_raw_string(id1_str, id1));
                rii_check(crs_print_message_send(printer, id1, message.buf));
            }
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
#line 1960 "croissant/test.c"
	switch( (*p) ) {
		case 32: goto st131;
		case 59: goto st42;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st131;
	goto st0;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	if ( (*p) == 111 )
		goto st133;
	goto st0;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	if ( (*p) == 117 )
		goto st134;
	goto st0;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	if ( (*p) == 116 )
		goto st135;
	goto st0;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	if ( (*p) == 105 )
		goto st136;
	goto st0;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	if ( (*p) == 110 )
		goto st137;
	goto st0;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	if ( (*p) == 103 )
		goto st138;
	goto st0;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( (*p) == 32 )
		goto st139;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st139;
	goto st0;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	switch( (*p) ) {
		case 32: goto st139;
		case 116: goto st140;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st139;
	goto st0;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	if ( (*p) == 97 )
		goto st141;
	goto st0;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	if ( (*p) == 98 )
		goto st142;
	goto st0;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	if ( (*p) == 108 )
		goto st143;
	goto st0;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 101 )
		goto st144;
	goto st0;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 32 )
		goto st145;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st145;
	goto st0;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	switch( (*p) ) {
		case 32: goto st145;
		case 101: goto st146;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st145;
	goto st0;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	if ( (*p) == 110 )
		goto st147;
	goto st0;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	if ( (*p) == 116 )
		goto st148;
	goto st0;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	if ( (*p) == 114 )
		goto st149;
	goto st0;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	if ( (*p) == 121 )
		goto st150;
	goto st0;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	if ( (*p) == 32 )
		goto st151;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st151;
	goto st0;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	if ( (*p) == 32 )
		goto st151;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st151;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto tr162;
		} else if ( (*p) >= 65 )
			goto tr162;
	} else
		goto tr162;
	goto st0;
tr162:
#line 55 "croissant/test.c.rl"
	{ start = p; }
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
#line 2141 "croissant/test.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st153;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st153;
	} else
		goto st153;
	goto st0;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st154;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st154;
	} else
		goto st154;
	goto st0;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st155;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st155;
	} else
		goto st155;
	goto st0;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st156;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st156;
	} else
		goto st156;
	goto st0;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st157;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st157;
	} else
		goto st157;
	goto st0;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st158;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st158;
	} else
		goto st158;
	goto st0;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st159;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st159;
	} else
		goto st159;
	goto st0;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st160;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st160;
	} else
		goto st160;
	goto st0;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st161;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st161;
	} else
		goto st161;
	goto st0;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st162;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st162;
	} else
		goto st162;
	goto st0;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st163;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st163;
	} else
		goto st163;
	goto st0;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st164;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st164;
	} else
		goto st164;
	goto st0;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st165;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st165;
	} else
		goto st165;
	goto st0;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st166;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st166;
	} else
		goto st166;
	goto st0;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st167;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st167;
	} else
		goto st167;
	goto st0;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st168;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st168;
	} else
		goto st168;
	goto st0;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st169;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st169;
	} else
		goto st169;
	goto st0;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st170;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st170;
	} else
		goto st170;
	goto st0;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st171;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st171;
	} else
		goto st171;
	goto st0;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st172;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st172;
	} else
		goto st172;
	goto st0;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st173;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st173;
	} else
		goto st173;
	goto st0;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st174;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st174;
	} else
		goto st174;
	goto st0;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st175;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st175;
	} else
		goto st175;
	goto st0;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st176;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st176;
	} else
		goto st176;
	goto st0;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st177;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st177;
	} else
		goto st177;
	goto st0;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st178;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st178;
	} else
		goto st178;
	goto st0;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st179;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st179;
	} else
		goto st179;
	goto st0;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st180;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st180;
	} else
		goto st180;
	goto st0;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st181;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st181;
	} else
		goto st181;
	goto st0;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st182;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st182;
	} else
		goto st182;
	goto st0;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st183;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st183;
	} else
		goto st183;
	goto st0;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	switch( (*p) ) {
		case 32: goto tr194;
		case 59: goto tr195;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr194;
	goto st0;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	if ( (*p) == 114 )
		goto st185;
	goto st0;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
	if ( (*p) == 101 )
		goto st186;
	goto st0;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	if ( (*p) == 97 )
		goto st187;
	goto st0;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	if ( (*p) == 116 )
		goto st188;
	goto st0;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	if ( (*p) == 101 )
		goto st189;
	goto st0;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	if ( (*p) == 32 )
		goto st190;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st190;
	goto st0;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	switch( (*p) ) {
		case 32: goto st190;
		case 101: goto st191;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st190;
	goto st0;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	if ( (*p) == 109 )
		goto st192;
	goto st0;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	if ( (*p) == 112 )
		goto st193;
	goto st0;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	if ( (*p) == 116 )
		goto st194;
	goto st0;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	if ( (*p) == 121 )
		goto st195;
	goto st0;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	if ( (*p) == 32 )
		goto st196;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st196;
	goto st0;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	switch( (*p) ) {
		case 32: goto st196;
		case 110: goto st197;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st196;
	goto st0;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	if ( (*p) == 101 )
		goto st198;
	goto st0;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	if ( (*p) == 116 )
		goto st199;
	goto st0;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	if ( (*p) == 119 )
		goto st200;
	goto st0;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	if ( (*p) == 111 )
		goto st201;
	goto st0;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	if ( (*p) == 114 )
		goto st202;
	goto st0;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	if ( (*p) == 107 )
		goto st203;
	goto st0;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	switch( (*p) ) {
		case 32: goto tr215;
		case 59: goto tr216;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr215;
	goto st0;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	if ( (*p) == 111 )
		goto st205;
	goto st0;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	if ( (*p) == 105 )
		goto st206;
	goto st0;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	if ( (*p) == 110 )
		goto st207;
	goto st0;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	if ( (*p) == 32 )
		goto st208;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st208;
	goto st0;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	switch( (*p) ) {
		case 32: goto st208;
		case 110: goto st209;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st208;
	goto st0;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	if ( (*p) == 101 )
		goto st210;
	goto st0;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	if ( (*p) == 116 )
		goto st211;
	goto st0;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	if ( (*p) == 119 )
		goto st212;
	goto st0;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	if ( (*p) == 111 )
		goto st213;
	goto st0;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	if ( (*p) == 114 )
		goto st214;
	goto st0;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	if ( (*p) == 107 )
		goto st215;
	goto st0;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	if ( (*p) == 32 )
		goto st216;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st216;
	goto st0;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	switch( (*p) ) {
		case 32: goto st216;
		case 118: goto st217;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st216;
	goto st0;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	if ( (*p) == 105 )
		goto st218;
	goto st0;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	if ( (*p) == 97 )
		goto st219;
	goto st0;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	if ( (*p) == 32 )
		goto st220;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st220;
	goto st0;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	if ( (*p) == 32 )
		goto st220;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st220;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto tr233;
		} else if ( (*p) >= 65 )
			goto tr233;
	} else
		goto tr233;
	goto st0;
tr233:
#line 55 "croissant/test.c.rl"
	{ start = p; }
	goto st221;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
#line 2860 "croissant/test.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st222;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st222;
	} else
		goto st222;
	goto st0;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st223;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st223;
	} else
		goto st223;
	goto st0;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st224;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st224;
	} else
		goto st224;
	goto st0;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st225;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st225;
	} else
		goto st225;
	goto st0;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st226;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st226;
	} else
		goto st226;
	goto st0;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st227;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st227;
	} else
		goto st227;
	goto st0;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st228;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st228;
	} else
		goto st228;
	goto st0;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st229;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st229;
	} else
		goto st229;
	goto st0;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st230;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st230;
	} else
		goto st230;
	goto st0;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st231;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st231;
	} else
		goto st231;
	goto st0;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st232;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st232;
	} else
		goto st232;
	goto st0;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st233;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st233;
	} else
		goto st233;
	goto st0;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st234;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st234;
	} else
		goto st234;
	goto st0;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st235;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st235;
	} else
		goto st235;
	goto st0;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st236;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st236;
	} else
		goto st236;
	goto st0;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st237;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st237;
	} else
		goto st237;
	goto st0;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st238;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st238;
	} else
		goto st238;
	goto st0;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st239;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st239;
	} else
		goto st239;
	goto st0;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st240;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st240;
	} else
		goto st240;
	goto st0;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st241;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st241;
	} else
		goto st241;
	goto st0;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st242;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st242;
	} else
		goto st242;
	goto st0;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st243;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st243;
	} else
		goto st243;
	goto st0;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st244;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st244;
	} else
		goto st244;
	goto st0;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st245;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st245;
	} else
		goto st245;
	goto st0;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st246;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st246;
	} else
		goto st246;
	goto st0;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st247;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st247;
	} else
		goto st247;
	goto st0;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st248;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st248;
	} else
		goto st248;
	goto st0;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st249;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st249;
	} else
		goto st249;
	goto st0;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st250;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st250;
	} else
		goto st250;
	goto st0;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st251;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st251;
	} else
		goto st251;
	goto st0;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st252;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st252;
	} else
		goto st252;
	goto st0;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
	switch( (*p) ) {
		case 32: goto tr265;
		case 59: goto tr266;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr265;
	goto st0;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	if ( (*p) == 114 )
		goto st254;
	goto st0;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
	if ( (*p) == 105 )
		goto st255;
	goto st0;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
	if ( (*p) == 110 )
		goto st256;
	goto st0;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	if ( (*p) == 116 )
		goto st257;
	goto st0;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	if ( (*p) == 32 )
		goto st258;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st258;
	goto st0;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	switch( (*p) ) {
		case 32: goto st258;
		case 108: goto st259;
		case 110: goto st267;
		case 114: goto st312;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st258;
	goto st0;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
	if ( (*p) == 101 )
		goto st260;
	goto st0;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
	if ( (*p) == 97 )
		goto st261;
	goto st0;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
	if ( (*p) == 102 )
		goto st262;
	goto st0;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	if ( (*p) == 32 )
		goto st263;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st263;
	goto st0;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
	switch( (*p) ) {
		case 32: goto st263;
		case 115: goto st264;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st263;
	goto st0;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	if ( (*p) == 101 )
		goto st265;
	goto st0;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	if ( (*p) == 116 )
		goto st266;
	goto st0;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
	switch( (*p) ) {
		case 32: goto tr282;
		case 59: goto tr283;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr282;
	goto st0;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	if ( (*p) == 101 )
		goto st268;
	goto st0;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	if ( (*p) == 120 )
		goto st269;
	goto st0;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	if ( (*p) == 116 )
		goto st270;
	goto st0;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	if ( (*p) == 32 )
		goto st271;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st271;
	goto st0;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
	switch( (*p) ) {
		case 32: goto st271;
		case 104: goto st272;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st271;
	goto st0;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
	if ( (*p) == 111 )
		goto st273;
	goto st0;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
	if ( (*p) == 112 )
		goto st274;
	goto st0;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
	if ( (*p) == 32 )
		goto st275;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st275;
	goto st0;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
	switch( (*p) ) {
		case 32: goto st275;
		case 102: goto st276;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st275;
	goto st0;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	if ( (*p) == 111 )
		goto st277;
	goto st0;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	if ( (*p) == 114 )
		goto st278;
	goto st0;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
	if ( (*p) == 32 )
		goto st279;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st279;
	goto st0;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
	if ( (*p) == 32 )
		goto st279;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st279;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto tr296;
		} else if ( (*p) >= 65 )
			goto tr296;
	} else
		goto tr296;
	goto st0;
tr296:
#line 55 "croissant/test.c.rl"
	{ start = p; }
	goto st280;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
#line 3511 "croissant/test.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st281;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st281;
	} else
		goto st281;
	goto st0;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st282;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st282;
	} else
		goto st282;
	goto st0;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st283;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st283;
	} else
		goto st283;
	goto st0;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st284;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st284;
	} else
		goto st284;
	goto st0;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st285;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st285;
	} else
		goto st285;
	goto st0;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st286;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st286;
	} else
		goto st286;
	goto st0;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st287;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st287;
	} else
		goto st287;
	goto st0;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st288;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st288;
	} else
		goto st288;
	goto st0;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st289;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st289;
	} else
		goto st289;
	goto st0;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st290;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st290;
	} else
		goto st290;
	goto st0;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st291;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st291;
	} else
		goto st291;
	goto st0;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st292;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st292;
	} else
		goto st292;
	goto st0;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st293;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st293;
	} else
		goto st293;
	goto st0;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st294;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st294;
	} else
		goto st294;
	goto st0;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st295;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st295;
	} else
		goto st295;
	goto st0;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st296;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st296;
	} else
		goto st296;
	goto st0;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st297;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st297;
	} else
		goto st297;
	goto st0;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st298;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st298;
	} else
		goto st298;
	goto st0;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st299;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st299;
	} else
		goto st299;
	goto st0;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st300;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st300;
	} else
		goto st300;
	goto st0;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st301;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st301;
	} else
		goto st301;
	goto st0;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st302;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st302;
	} else
		goto st302;
	goto st0;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st303;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st303;
	} else
		goto st303;
	goto st0;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st304;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st304;
	} else
		goto st304;
	goto st0;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st305;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st305;
	} else
		goto st305;
	goto st0;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st306;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st306;
	} else
		goto st306;
	goto st0;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st307;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st307;
	} else
		goto st307;
	goto st0;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st308;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st308;
	} else
		goto st308;
	goto st0;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st309;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st309;
	} else
		goto st309;
	goto st0;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st310;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st310;
	} else
		goto st310;
	goto st0;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st311;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st311;
	} else
		goto st311;
	goto st0;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
	switch( (*p) ) {
		case 32: goto tr328;
		case 59: goto tr329;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr328;
	goto st0;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
	if ( (*p) == 111 )
		goto st313;
	goto st0;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
	if ( (*p) == 117 )
		goto st314;
	goto st0;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
	if ( (*p) == 116 )
		goto st315;
	goto st0;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
	if ( (*p) == 105 )
		goto st316;
	goto st0;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
	if ( (*p) == 110 )
		goto st317;
	goto st0;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	if ( (*p) == 103 )
		goto st318;
	goto st0;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	if ( (*p) == 32 )
		goto st319;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st319;
	goto st0;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	switch( (*p) ) {
		case 32: goto st319;
		case 116: goto st320;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st319;
	goto st0;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
	if ( (*p) == 97 )
		goto st321;
	goto st0;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
	if ( (*p) == 98 )
		goto st322;
	goto st0;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
	if ( (*p) == 108 )
		goto st323;
	goto st0;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
	if ( (*p) == 101 )
		goto st324;
	goto st0;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	switch( (*p) ) {
		case 32: goto tr342;
		case 59: goto tr343;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr342;
	goto st0;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	if ( (*p) == 101 )
		goto st326;
	goto st0;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	if ( (*p) == 110 )
		goto st327;
	goto st0;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	if ( (*p) == 100 )
		goto st328;
	goto st0;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	if ( (*p) == 32 )
		goto st329;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st329;
	goto st0;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	if ( (*p) == 32 )
		goto st329;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st329;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr348;
		} else if ( (*p) >= 65 )
			goto tr348;
	} else
		goto tr348;
	goto st0;
tr348:
#line 60 "croissant/test.c.rl"
	{ start = p; }
	goto st330;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
#line 4079 "croissant/test.c"
	if ( (*p) == 32 )
		goto tr349;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr349;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st330;
		} else if ( (*p) >= 65 )
			goto st330;
	} else
		goto st330;
	goto st0;
tr349:
#line 61 "croissant/test.c.rl"
	{ cork_buffer_set(&message, start, p - start); }
	goto st331;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
#line 4102 "croissant/test.c"
	switch( (*p) ) {
		case 32: goto st331;
		case 116: goto st332;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st331;
	goto st0;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
	if ( (*p) == 111 )
		goto st333;
	goto st0;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
	if ( (*p) == 32 )
		goto st334;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st334;
	goto st0;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
	if ( (*p) == 32 )
		goto st334;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st334;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto tr355;
		} else if ( (*p) >= 65 )
			goto tr355;
	} else
		goto tr355;
	goto st0;
tr355:
#line 55 "croissant/test.c.rl"
	{ start = p; }
	goto st335;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
#line 4152 "croissant/test.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st336;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st336;
	} else
		goto st336;
	goto st0;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st337;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st337;
	} else
		goto st337;
	goto st0;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st338;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st338;
	} else
		goto st338;
	goto st0;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st339;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st339;
	} else
		goto st339;
	goto st0;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st340;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st340;
	} else
		goto st340;
	goto st0;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st341;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st341;
	} else
		goto st341;
	goto st0;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st342;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st342;
	} else
		goto st342;
	goto st0;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st343;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st343;
	} else
		goto st343;
	goto st0;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st344;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st344;
	} else
		goto st344;
	goto st0;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st345;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st345;
	} else
		goto st345;
	goto st0;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st346;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st346;
	} else
		goto st346;
	goto st0;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st347;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st347;
	} else
		goto st347;
	goto st0;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st348;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st348;
	} else
		goto st348;
	goto st0;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st349;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st349;
	} else
		goto st349;
	goto st0;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st350;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st350;
	} else
		goto st350;
	goto st0;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st351;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st351;
	} else
		goto st351;
	goto st0;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st352;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st352;
	} else
		goto st352;
	goto st0;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st353;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st353;
	} else
		goto st353;
	goto st0;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st354;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st354;
	} else
		goto st354;
	goto st0;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st355;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st355;
	} else
		goto st355;
	goto st0;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st356;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st356;
	} else
		goto st356;
	goto st0;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st357;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st357;
	} else
		goto st357;
	goto st0;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st358;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st358;
	} else
		goto st358;
	goto st0;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st359;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st359;
	} else
		goto st359;
	goto st0;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st360;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st360;
	} else
		goto st360;
	goto st0;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st361;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st361;
	} else
		goto st361;
	goto st0;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st362;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st362;
	} else
		goto st362;
	goto st0;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st363;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st363;
	} else
		goto st363;
	goto st0;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st364;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st364;
	} else
		goto st364;
	goto st0;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st365;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st365;
	} else
		goto st365;
	goto st0;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st366;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st366;
	} else
		goto st366;
	goto st0;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
	switch( (*p) ) {
		case 32: goto tr387;
		case 59: goto tr388;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr387;
	goto st0;
tr446:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 76 "croissant/test.c.rl"
	{
                struct crs_leaf_set  *from_set;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                fprintf(stderr, "--- [%s]\n--- add leaf set entry %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(to_node = crs_ctx_require_node(ctx, id1));
                from_set = crs_node_get_leaf_set(node);
                to_ref = crs_node_new_ref(node, crs_node_get_address(to_node));
                crs_leaf_set_add(from_set, to_ref);
            }
	goto st367;
tr500:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 92 "croissant/test.c.rl"
	{
                struct crs_routing_table  *from_table;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                fprintf(stderr, "--- [%s]\n--- add routing table entry %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(to_node = crs_ctx_require_node(ctx, id1));
                from_table = crs_node_get_routing_table(node);
                to_ref = crs_node_new_ref(node, crs_node_get_address(to_node));
                crs_routing_table_set(from_table, to_ref);
            }
	goto st367;
tr521:
#line 107 "croissant/test.c.rl"
	{
                fprintf(stderr, "--- [%s]\n--- create empty network\n",
                        crs_node_get_id_str(node));
                rii_check(crs_node_bootstrap(node, NULL));
            }
	goto st367;
tr571:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 115 "croissant/test.c.rl"
	{
                struct crs_node  *bootstrap_node;
                const struct crs_node_address  *bootstrap_address;
                fprintf(stderr, "--- [%s]\n--- join network via %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(bootstrap_node = crs_ctx_require_node(ctx, id1));
                bootstrap_address = crs_node_get_address(bootstrap_node);
                rii_check(crs_node_bootstrap(node, bootstrap_address));
            }
	goto st367;
tr588:
#line 128 "croissant/test.c.rl"
	{
                struct crs_leaf_set  *set;
                fprintf(stderr, "--- [%s]\n--- print leaf set\n",
                        crs_node_get_id_str(node));
                set = crs_node_get_leaf_set(node);
                cork_buffer_printf
                    (&output, "Leaf set for %s\n", crs_node_get_id_str(node));
                crs_leaf_set_print(&output, set);
                fwrite(output.buf, output.size, 1, stderr);
            }
	goto st367;
tr634:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 142 "croissant/test.c.rl"
	{
                struct crs_node_ref  *next_hop;
                fprintf(stderr, "--- [%s]\n--- print next hop for %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(next_hop = crs_node_get_next_hop(node, id1));
                fprintf
                    (stderr,
                     "Next hop from %s\n"
                     "           to %s\n"
                     "           is %s\n",
                     crs_node_get_id_str(node),
                     crs_id_to_raw_string(id1_str, id1),
                     (next_hop == CRS_NODE_REF_SELF)? "local delivery":
                         crs_node_ref_get_id_str(next_hop));
            }
	goto st367;
tr648:
#line 161 "croissant/test.c.rl"
	{
                struct crs_routing_table  *table;
                fprintf(stderr, "--- [%s]\n--- print routing table\n",
                        crs_node_get_id_str(node));
                table = crs_node_get_routing_table(node);
                cork_buffer_printf
                    (&output, "Routing table for %s\n",
                     crs_node_get_id_str(node));
                crs_routing_table_print(&output, table);
                fwrite(output.buf, output.size, 1, stderr);
            }
	goto st367;
tr693:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 175 "croissant/test.c.rl"
	{
                struct crs_print_message  *printer;
                rip_check(printer = crs_print_message_get(node));
                fprintf(stderr, "--- [%s]\n--- send \"%s\" to %s\n",
                        crs_node_get_id_str(node),
                        (char *) message.buf,
                        crs_id_to_raw_string(id1_str, id1));
                rii_check(crs_print_message_send(printer, id1, message.buf));
            }
	goto st367;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
#line 4696 "croissant/test.c"
	switch( (*p) ) {
		case 32: goto st367;
		case 97: goto st368;
		case 99: goto st472;
		case 106: goto st492;
		case 112: goto st541;
		case 115: goto st613;
		case 125: goto st42;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st367;
	goto st0;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
	if ( (*p) == 100 )
		goto st369;
	goto st0;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
	if ( (*p) == 100 )
		goto st370;
	goto st0;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
	if ( (*p) == 32 )
		goto st371;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st371;
	goto st0;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
	switch( (*p) ) {
		case 32: goto st371;
		case 108: goto st372;
		case 114: goto st420;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st371;
	goto st0;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
	if ( (*p) == 101 )
		goto st373;
	goto st0;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
	if ( (*p) == 97 )
		goto st374;
	goto st0;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
	if ( (*p) == 102 )
		goto st375;
	goto st0;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
	if ( (*p) == 32 )
		goto st376;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st376;
	goto st0;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
	switch( (*p) ) {
		case 32: goto st376;
		case 115: goto st377;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st376;
	goto st0;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
	if ( (*p) == 101 )
		goto st378;
	goto st0;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
	if ( (*p) == 116 )
		goto st379;
	goto st0;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
	if ( (*p) == 32 )
		goto st380;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st380;
	goto st0;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
	switch( (*p) ) {
		case 32: goto st380;
		case 101: goto st381;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st380;
	goto st0;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	if ( (*p) == 110 )
		goto st382;
	goto st0;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
	if ( (*p) == 116 )
		goto st383;
	goto st0;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
	if ( (*p) == 114 )
		goto st384;
	goto st0;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
	if ( (*p) == 121 )
		goto st385;
	goto st0;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
	if ( (*p) == 32 )
		goto st386;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st386;
	goto st0;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
	if ( (*p) == 32 )
		goto st386;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st386;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto tr413;
		} else if ( (*p) >= 65 )
			goto tr413;
	} else
		goto tr413;
	goto st0;
tr413:
#line 55 "croissant/test.c.rl"
	{ start = p; }
	goto st387;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
#line 4882 "croissant/test.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st388;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st388;
	} else
		goto st388;
	goto st0;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st389;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st389;
	} else
		goto st389;
	goto st0;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st390;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st390;
	} else
		goto st390;
	goto st0;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st391;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st391;
	} else
		goto st391;
	goto st0;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st392;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st392;
	} else
		goto st392;
	goto st0;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st393;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st393;
	} else
		goto st393;
	goto st0;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st394;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st394;
	} else
		goto st394;
	goto st0;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st395;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st395;
	} else
		goto st395;
	goto st0;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st396;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st396;
	} else
		goto st396;
	goto st0;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st397;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st397;
	} else
		goto st397;
	goto st0;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st398;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st398;
	} else
		goto st398;
	goto st0;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st399;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st399;
	} else
		goto st399;
	goto st0;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st400;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st400;
	} else
		goto st400;
	goto st0;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st401;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st401;
	} else
		goto st401;
	goto st0;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st402;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st402;
	} else
		goto st402;
	goto st0;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st403;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st403;
	} else
		goto st403;
	goto st0;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st404;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st404;
	} else
		goto st404;
	goto st0;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st405;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st405;
	} else
		goto st405;
	goto st0;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st406;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st406;
	} else
		goto st406;
	goto st0;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st407;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st407;
	} else
		goto st407;
	goto st0;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st408;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st408;
	} else
		goto st408;
	goto st0;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st409;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st409;
	} else
		goto st409;
	goto st0;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st410;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st410;
	} else
		goto st410;
	goto st0;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st411;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st411;
	} else
		goto st411;
	goto st0;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st412;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st412;
	} else
		goto st412;
	goto st0;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st413;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st413;
	} else
		goto st413;
	goto st0;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st414;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st414;
	} else
		goto st414;
	goto st0;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st415;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st415;
	} else
		goto st415;
	goto st0;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st416;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st416;
	} else
		goto st416;
	goto st0;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st417;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st417;
	} else
		goto st417;
	goto st0;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st418;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st418;
	} else
		goto st418;
	goto st0;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
	switch( (*p) ) {
		case 32: goto tr445;
		case 59: goto tr446;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr445;
	goto st0;
tr445:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 76 "croissant/test.c.rl"
	{
                struct crs_leaf_set  *from_set;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                fprintf(stderr, "--- [%s]\n--- add leaf set entry %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(to_node = crs_ctx_require_node(ctx, id1));
                from_set = crs_node_get_leaf_set(node);
                to_ref = crs_node_new_ref(node, crs_node_get_address(to_node));
                crs_leaf_set_add(from_set, to_ref);
            }
	goto st419;
tr499:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 92 "croissant/test.c.rl"
	{
                struct crs_routing_table  *from_table;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                fprintf(stderr, "--- [%s]\n--- add routing table entry %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(to_node = crs_ctx_require_node(ctx, id1));
                from_table = crs_node_get_routing_table(node);
                to_ref = crs_node_new_ref(node, crs_node_get_address(to_node));
                crs_routing_table_set(from_table, to_ref);
            }
	goto st419;
tr520:
#line 107 "croissant/test.c.rl"
	{
                fprintf(stderr, "--- [%s]\n--- create empty network\n",
                        crs_node_get_id_str(node));
                rii_check(crs_node_bootstrap(node, NULL));
            }
	goto st419;
tr570:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 115 "croissant/test.c.rl"
	{
                struct crs_node  *bootstrap_node;
                const struct crs_node_address  *bootstrap_address;
                fprintf(stderr, "--- [%s]\n--- join network via %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(bootstrap_node = crs_ctx_require_node(ctx, id1));
                bootstrap_address = crs_node_get_address(bootstrap_node);
                rii_check(crs_node_bootstrap(node, bootstrap_address));
            }
	goto st419;
tr587:
#line 128 "croissant/test.c.rl"
	{
                struct crs_leaf_set  *set;
                fprintf(stderr, "--- [%s]\n--- print leaf set\n",
                        crs_node_get_id_str(node));
                set = crs_node_get_leaf_set(node);
                cork_buffer_printf
                    (&output, "Leaf set for %s\n", crs_node_get_id_str(node));
                crs_leaf_set_print(&output, set);
                fwrite(output.buf, output.size, 1, stderr);
            }
	goto st419;
tr633:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 142 "croissant/test.c.rl"
	{
                struct crs_node_ref  *next_hop;
                fprintf(stderr, "--- [%s]\n--- print next hop for %s\n",
                        crs_node_get_id_str(node),
                        crs_id_to_raw_string(id1_str, id1));
                rip_check(next_hop = crs_node_get_next_hop(node, id1));
                fprintf
                    (stderr,
                     "Next hop from %s\n"
                     "           to %s\n"
                     "           is %s\n",
                     crs_node_get_id_str(node),
                     crs_id_to_raw_string(id1_str, id1),
                     (next_hop == CRS_NODE_REF_SELF)? "local delivery":
                         crs_node_ref_get_id_str(next_hop));
            }
	goto st419;
tr647:
#line 161 "croissant/test.c.rl"
	{
                struct crs_routing_table  *table;
                fprintf(stderr, "--- [%s]\n--- print routing table\n",
                        crs_node_get_id_str(node));
                table = crs_node_get_routing_table(node);
                cork_buffer_printf
                    (&output, "Routing table for %s\n",
                     crs_node_get_id_str(node));
                crs_routing_table_print(&output, table);
                fwrite(output.buf, output.size, 1, stderr);
            }
	goto st419;
tr692:
#line 55 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 57 "croissant/test.c.rl"
	{ rie_check(id1 = crs_id_init(buf.buf)); }
#line 175 "croissant/test.c.rl"
	{
                struct crs_print_message  *printer;
                rip_check(printer = crs_print_message_get(node));
                fprintf(stderr, "--- [%s]\n--- send \"%s\" to %s\n",
                        crs_node_get_id_str(node),
                        (char *) message.buf,
                        crs_id_to_raw_string(id1_str, id1));
                rii_check(crs_print_message_send(printer, id1, message.buf));
            }
	goto st419;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
#line 5426 "croissant/test.c"
	switch( (*p) ) {
		case 32: goto st419;
		case 59: goto st367;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st419;
	goto st0;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
	if ( (*p) == 111 )
		goto st421;
	goto st0;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
	if ( (*p) == 117 )
		goto st422;
	goto st0;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
	if ( (*p) == 116 )
		goto st423;
	goto st0;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
	if ( (*p) == 105 )
		goto st424;
	goto st0;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
	if ( (*p) == 110 )
		goto st425;
	goto st0;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
	if ( (*p) == 103 )
		goto st426;
	goto st0;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
	if ( (*p) == 32 )
		goto st427;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st427;
	goto st0;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
	switch( (*p) ) {
		case 32: goto st427;
		case 116: goto st428;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st427;
	goto st0;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
	if ( (*p) == 97 )
		goto st429;
	goto st0;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
	if ( (*p) == 98 )
		goto st430;
	goto st0;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
	if ( (*p) == 108 )
		goto st431;
	goto st0;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
	if ( (*p) == 101 )
		goto st432;
	goto st0;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
	if ( (*p) == 32 )
		goto st433;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st433;
	goto st0;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
	switch( (*p) ) {
		case 32: goto st433;
		case 101: goto st434;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st433;
	goto st0;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
	if ( (*p) == 110 )
		goto st435;
	goto st0;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
	if ( (*p) == 116 )
		goto st436;
	goto st0;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
	if ( (*p) == 114 )
		goto st437;
	goto st0;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
	if ( (*p) == 121 )
		goto st438;
	goto st0;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
	if ( (*p) == 32 )
		goto st439;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st439;
	goto st0;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
	if ( (*p) == 32 )
		goto st439;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st439;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto tr467;
		} else if ( (*p) >= 65 )
			goto tr467;
	} else
		goto tr467;
	goto st0;
tr467:
#line 55 "croissant/test.c.rl"
	{ start = p; }
	goto st440;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
#line 5607 "croissant/test.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st441;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st441;
	} else
		goto st441;
	goto st0;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st442;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st442;
	} else
		goto st442;
	goto st0;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st443;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st443;
	} else
		goto st443;
	goto st0;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st444;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st444;
	} else
		goto st444;
	goto st0;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st445;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st445;
	} else
		goto st445;
	goto st0;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st446;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st446;
	} else
		goto st446;
	goto st0;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st447;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st447;
	} else
		goto st447;
	goto st0;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st448;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st448;
	} else
		goto st448;
	goto st0;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st449;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st449;
	} else
		goto st449;
	goto st0;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st450;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st450;
	} else
		goto st450;
	goto st0;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st451;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st451;
	} else
		goto st451;
	goto st0;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st452;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st452;
	} else
		goto st452;
	goto st0;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st453;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st453;
	} else
		goto st453;
	goto st0;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st454;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st454;
	} else
		goto st454;
	goto st0;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st455;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st455;
	} else
		goto st455;
	goto st0;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st456;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st456;
	} else
		goto st456;
	goto st0;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st457;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st457;
	} else
		goto st457;
	goto st0;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st458;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st458;
	} else
		goto st458;
	goto st0;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st459;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st459;
	} else
		goto st459;
	goto st0;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st460;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st460;
	} else
		goto st460;
	goto st0;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st461;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st461;
	} else
		goto st461;
	goto st0;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st462;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st462;
	} else
		goto st462;
	goto st0;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st463;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st463;
	} else
		goto st463;
	goto st0;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st464;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st464;
	} else
		goto st464;
	goto st0;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st465;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st465;
	} else
		goto st465;
	goto st0;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st466;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st466;
	} else
		goto st466;
	goto st0;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st467;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st467;
	} else
		goto st467;
	goto st0;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st468;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st468;
	} else
		goto st468;
	goto st0;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st469;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st469;
	} else
		goto st469;
	goto st0;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st470;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st470;
	} else
		goto st470;
	goto st0;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st471;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st471;
	} else
		goto st471;
	goto st0;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
	switch( (*p) ) {
		case 32: goto tr499;
		case 59: goto tr500;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr499;
	goto st0;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
	if ( (*p) == 114 )
		goto st473;
	goto st0;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
	if ( (*p) == 101 )
		goto st474;
	goto st0;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
	if ( (*p) == 97 )
		goto st475;
	goto st0;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
	if ( (*p) == 116 )
		goto st476;
	goto st0;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
	if ( (*p) == 101 )
		goto st477;
	goto st0;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
	if ( (*p) == 32 )
		goto st478;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st478;
	goto st0;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
	switch( (*p) ) {
		case 32: goto st478;
		case 101: goto st479;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st478;
	goto st0;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
	if ( (*p) == 109 )
		goto st480;
	goto st0;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
	if ( (*p) == 112 )
		goto st481;
	goto st0;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
	if ( (*p) == 116 )
		goto st482;
	goto st0;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
	if ( (*p) == 121 )
		goto st483;
	goto st0;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
	if ( (*p) == 32 )
		goto st484;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st484;
	goto st0;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
	switch( (*p) ) {
		case 32: goto st484;
		case 110: goto st485;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st484;
	goto st0;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
	if ( (*p) == 101 )
		goto st486;
	goto st0;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
	if ( (*p) == 116 )
		goto st487;
	goto st0;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
	if ( (*p) == 119 )
		goto st488;
	goto st0;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
	if ( (*p) == 111 )
		goto st489;
	goto st0;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
	if ( (*p) == 114 )
		goto st490;
	goto st0;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
	if ( (*p) == 107 )
		goto st491;
	goto st0;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
	switch( (*p) ) {
		case 32: goto tr520;
		case 59: goto tr521;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr520;
	goto st0;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
	if ( (*p) == 111 )
		goto st493;
	goto st0;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
	if ( (*p) == 105 )
		goto st494;
	goto st0;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
	if ( (*p) == 110 )
		goto st495;
	goto st0;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
	if ( (*p) == 32 )
		goto st496;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st496;
	goto st0;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
	switch( (*p) ) {
		case 32: goto st496;
		case 110: goto st497;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st496;
	goto st0;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
	if ( (*p) == 101 )
		goto st498;
	goto st0;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
	if ( (*p) == 116 )
		goto st499;
	goto st0;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
	if ( (*p) == 119 )
		goto st500;
	goto st0;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
	if ( (*p) == 111 )
		goto st501;
	goto st0;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
	if ( (*p) == 114 )
		goto st502;
	goto st0;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
	if ( (*p) == 107 )
		goto st503;
	goto st0;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
	if ( (*p) == 32 )
		goto st504;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st504;
	goto st0;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
	switch( (*p) ) {
		case 32: goto st504;
		case 118: goto st505;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st504;
	goto st0;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
	if ( (*p) == 105 )
		goto st506;
	goto st0;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
	if ( (*p) == 97 )
		goto st507;
	goto st0;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
	if ( (*p) == 32 )
		goto st508;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st508;
	goto st0;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
	if ( (*p) == 32 )
		goto st508;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st508;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto tr538;
		} else if ( (*p) >= 65 )
			goto tr538;
	} else
		goto tr538;
	goto st0;
tr538:
#line 55 "croissant/test.c.rl"
	{ start = p; }
	goto st509;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
#line 6326 "croissant/test.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st510;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st510;
	} else
		goto st510;
	goto st0;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st511;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st511;
	} else
		goto st511;
	goto st0;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st512;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st512;
	} else
		goto st512;
	goto st0;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st513;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st513;
	} else
		goto st513;
	goto st0;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st514;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st514;
	} else
		goto st514;
	goto st0;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st515;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st515;
	} else
		goto st515;
	goto st0;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st516;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st516;
	} else
		goto st516;
	goto st0;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st517;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st517;
	} else
		goto st517;
	goto st0;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st518;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st518;
	} else
		goto st518;
	goto st0;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st519;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st519;
	} else
		goto st519;
	goto st0;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st520;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st520;
	} else
		goto st520;
	goto st0;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st521;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st521;
	} else
		goto st521;
	goto st0;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st522;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st522;
	} else
		goto st522;
	goto st0;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st523;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st523;
	} else
		goto st523;
	goto st0;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st524;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st524;
	} else
		goto st524;
	goto st0;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st525;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st525;
	} else
		goto st525;
	goto st0;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st526;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st526;
	} else
		goto st526;
	goto st0;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st527;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st527;
	} else
		goto st527;
	goto st0;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st528;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st528;
	} else
		goto st528;
	goto st0;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st529;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st529;
	} else
		goto st529;
	goto st0;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st530;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st530;
	} else
		goto st530;
	goto st0;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st531;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st531;
	} else
		goto st531;
	goto st0;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st532;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st532;
	} else
		goto st532;
	goto st0;
st532:
	if ( ++p == pe )
		goto _test_eof532;
case 532:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st533;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st533;
	} else
		goto st533;
	goto st0;
st533:
	if ( ++p == pe )
		goto _test_eof533;
case 533:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st534;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st534;
	} else
		goto st534;
	goto st0;
st534:
	if ( ++p == pe )
		goto _test_eof534;
case 534:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st535;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st535;
	} else
		goto st535;
	goto st0;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st536;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st536;
	} else
		goto st536;
	goto st0;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st537;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st537;
	} else
		goto st537;
	goto st0;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st538;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st538;
	} else
		goto st538;
	goto st0;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st539;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st539;
	} else
		goto st539;
	goto st0;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st540;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st540;
	} else
		goto st540;
	goto st0;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
	switch( (*p) ) {
		case 32: goto tr570;
		case 59: goto tr571;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr570;
	goto st0;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
	if ( (*p) == 114 )
		goto st542;
	goto st0;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
	if ( (*p) == 105 )
		goto st543;
	goto st0;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
	if ( (*p) == 110 )
		goto st544;
	goto st0;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
	if ( (*p) == 116 )
		goto st545;
	goto st0;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
	if ( (*p) == 32 )
		goto st546;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st546;
	goto st0;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
	switch( (*p) ) {
		case 32: goto st546;
		case 108: goto st547;
		case 110: goto st555;
		case 114: goto st600;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st546;
	goto st0;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
	if ( (*p) == 101 )
		goto st548;
	goto st0;
st548:
	if ( ++p == pe )
		goto _test_eof548;
case 548:
	if ( (*p) == 97 )
		goto st549;
	goto st0;
st549:
	if ( ++p == pe )
		goto _test_eof549;
case 549:
	if ( (*p) == 102 )
		goto st550;
	goto st0;
st550:
	if ( ++p == pe )
		goto _test_eof550;
case 550:
	if ( (*p) == 32 )
		goto st551;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st551;
	goto st0;
st551:
	if ( ++p == pe )
		goto _test_eof551;
case 551:
	switch( (*p) ) {
		case 32: goto st551;
		case 115: goto st552;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st551;
	goto st0;
st552:
	if ( ++p == pe )
		goto _test_eof552;
case 552:
	if ( (*p) == 101 )
		goto st553;
	goto st0;
st553:
	if ( ++p == pe )
		goto _test_eof553;
case 553:
	if ( (*p) == 116 )
		goto st554;
	goto st0;
st554:
	if ( ++p == pe )
		goto _test_eof554;
case 554:
	switch( (*p) ) {
		case 32: goto tr587;
		case 59: goto tr588;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr587;
	goto st0;
st555:
	if ( ++p == pe )
		goto _test_eof555;
case 555:
	if ( (*p) == 101 )
		goto st556;
	goto st0;
st556:
	if ( ++p == pe )
		goto _test_eof556;
case 556:
	if ( (*p) == 120 )
		goto st557;
	goto st0;
st557:
	if ( ++p == pe )
		goto _test_eof557;
case 557:
	if ( (*p) == 116 )
		goto st558;
	goto st0;
st558:
	if ( ++p == pe )
		goto _test_eof558;
case 558:
	if ( (*p) == 32 )
		goto st559;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st559;
	goto st0;
st559:
	if ( ++p == pe )
		goto _test_eof559;
case 559:
	switch( (*p) ) {
		case 32: goto st559;
		case 104: goto st560;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st559;
	goto st0;
st560:
	if ( ++p == pe )
		goto _test_eof560;
case 560:
	if ( (*p) == 111 )
		goto st561;
	goto st0;
st561:
	if ( ++p == pe )
		goto _test_eof561;
case 561:
	if ( (*p) == 112 )
		goto st562;
	goto st0;
st562:
	if ( ++p == pe )
		goto _test_eof562;
case 562:
	if ( (*p) == 32 )
		goto st563;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st563;
	goto st0;
st563:
	if ( ++p == pe )
		goto _test_eof563;
case 563:
	switch( (*p) ) {
		case 32: goto st563;
		case 102: goto st564;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st563;
	goto st0;
st564:
	if ( ++p == pe )
		goto _test_eof564;
case 564:
	if ( (*p) == 111 )
		goto st565;
	goto st0;
st565:
	if ( ++p == pe )
		goto _test_eof565;
case 565:
	if ( (*p) == 114 )
		goto st566;
	goto st0;
st566:
	if ( ++p == pe )
		goto _test_eof566;
case 566:
	if ( (*p) == 32 )
		goto st567;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st567;
	goto st0;
st567:
	if ( ++p == pe )
		goto _test_eof567;
case 567:
	if ( (*p) == 32 )
		goto st567;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st567;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto tr601;
		} else if ( (*p) >= 65 )
			goto tr601;
	} else
		goto tr601;
	goto st0;
tr601:
#line 55 "croissant/test.c.rl"
	{ start = p; }
	goto st568;
st568:
	if ( ++p == pe )
		goto _test_eof568;
case 568:
#line 6977 "croissant/test.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st569;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st569;
	} else
		goto st569;
	goto st0;
st569:
	if ( ++p == pe )
		goto _test_eof569;
case 569:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st570;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st570;
	} else
		goto st570;
	goto st0;
st570:
	if ( ++p == pe )
		goto _test_eof570;
case 570:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st571;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st571;
	} else
		goto st571;
	goto st0;
st571:
	if ( ++p == pe )
		goto _test_eof571;
case 571:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st572;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st572;
	} else
		goto st572;
	goto st0;
st572:
	if ( ++p == pe )
		goto _test_eof572;
case 572:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st573;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st573;
	} else
		goto st573;
	goto st0;
st573:
	if ( ++p == pe )
		goto _test_eof573;
case 573:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st574;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st574;
	} else
		goto st574;
	goto st0;
st574:
	if ( ++p == pe )
		goto _test_eof574;
case 574:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st575;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st575;
	} else
		goto st575;
	goto st0;
st575:
	if ( ++p == pe )
		goto _test_eof575;
case 575:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st576;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st576;
	} else
		goto st576;
	goto st0;
st576:
	if ( ++p == pe )
		goto _test_eof576;
case 576:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st577;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st577;
	} else
		goto st577;
	goto st0;
st577:
	if ( ++p == pe )
		goto _test_eof577;
case 577:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st578;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st578;
	} else
		goto st578;
	goto st0;
st578:
	if ( ++p == pe )
		goto _test_eof578;
case 578:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st579;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st579;
	} else
		goto st579;
	goto st0;
st579:
	if ( ++p == pe )
		goto _test_eof579;
case 579:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st580;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st580;
	} else
		goto st580;
	goto st0;
st580:
	if ( ++p == pe )
		goto _test_eof580;
case 580:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st581;
	} else
		goto st581;
	goto st0;
st581:
	if ( ++p == pe )
		goto _test_eof581;
case 581:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st582;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st582;
	} else
		goto st582;
	goto st0;
st582:
	if ( ++p == pe )
		goto _test_eof582;
case 582:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st583;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st583;
	} else
		goto st583;
	goto st0;
st583:
	if ( ++p == pe )
		goto _test_eof583;
case 583:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st584;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st584;
	} else
		goto st584;
	goto st0;
st584:
	if ( ++p == pe )
		goto _test_eof584;
case 584:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st585;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st585;
	} else
		goto st585;
	goto st0;
st585:
	if ( ++p == pe )
		goto _test_eof585;
case 585:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st586;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st586;
	} else
		goto st586;
	goto st0;
st586:
	if ( ++p == pe )
		goto _test_eof586;
case 586:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st587;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st587;
	} else
		goto st587;
	goto st0;
st587:
	if ( ++p == pe )
		goto _test_eof587;
case 587:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st588;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st588;
	} else
		goto st588;
	goto st0;
st588:
	if ( ++p == pe )
		goto _test_eof588;
case 588:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st589;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st589;
	} else
		goto st589;
	goto st0;
st589:
	if ( ++p == pe )
		goto _test_eof589;
case 589:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st590;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st590;
	} else
		goto st590;
	goto st0;
st590:
	if ( ++p == pe )
		goto _test_eof590;
case 590:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st591;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st591;
	} else
		goto st591;
	goto st0;
st591:
	if ( ++p == pe )
		goto _test_eof591;
case 591:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st592;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st592;
	} else
		goto st592;
	goto st0;
st592:
	if ( ++p == pe )
		goto _test_eof592;
case 592:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st593;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st593;
	} else
		goto st593;
	goto st0;
st593:
	if ( ++p == pe )
		goto _test_eof593;
case 593:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st594;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st594;
	} else
		goto st594;
	goto st0;
st594:
	if ( ++p == pe )
		goto _test_eof594;
case 594:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st595;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st595;
	} else
		goto st595;
	goto st0;
st595:
	if ( ++p == pe )
		goto _test_eof595;
case 595:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st596;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st596;
	} else
		goto st596;
	goto st0;
st596:
	if ( ++p == pe )
		goto _test_eof596;
case 596:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st597;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st597;
	} else
		goto st597;
	goto st0;
st597:
	if ( ++p == pe )
		goto _test_eof597;
case 597:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st598;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st598;
	} else
		goto st598;
	goto st0;
st598:
	if ( ++p == pe )
		goto _test_eof598;
case 598:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st599;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st599;
	} else
		goto st599;
	goto st0;
st599:
	if ( ++p == pe )
		goto _test_eof599;
case 599:
	switch( (*p) ) {
		case 32: goto tr633;
		case 59: goto tr634;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr633;
	goto st0;
st600:
	if ( ++p == pe )
		goto _test_eof600;
case 600:
	if ( (*p) == 111 )
		goto st601;
	goto st0;
st601:
	if ( ++p == pe )
		goto _test_eof601;
case 601:
	if ( (*p) == 117 )
		goto st602;
	goto st0;
st602:
	if ( ++p == pe )
		goto _test_eof602;
case 602:
	if ( (*p) == 116 )
		goto st603;
	goto st0;
st603:
	if ( ++p == pe )
		goto _test_eof603;
case 603:
	if ( (*p) == 105 )
		goto st604;
	goto st0;
st604:
	if ( ++p == pe )
		goto _test_eof604;
case 604:
	if ( (*p) == 110 )
		goto st605;
	goto st0;
st605:
	if ( ++p == pe )
		goto _test_eof605;
case 605:
	if ( (*p) == 103 )
		goto st606;
	goto st0;
st606:
	if ( ++p == pe )
		goto _test_eof606;
case 606:
	if ( (*p) == 32 )
		goto st607;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st607;
	goto st0;
st607:
	if ( ++p == pe )
		goto _test_eof607;
case 607:
	switch( (*p) ) {
		case 32: goto st607;
		case 116: goto st608;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st607;
	goto st0;
st608:
	if ( ++p == pe )
		goto _test_eof608;
case 608:
	if ( (*p) == 97 )
		goto st609;
	goto st0;
st609:
	if ( ++p == pe )
		goto _test_eof609;
case 609:
	if ( (*p) == 98 )
		goto st610;
	goto st0;
st610:
	if ( ++p == pe )
		goto _test_eof610;
case 610:
	if ( (*p) == 108 )
		goto st611;
	goto st0;
st611:
	if ( ++p == pe )
		goto _test_eof611;
case 611:
	if ( (*p) == 101 )
		goto st612;
	goto st0;
st612:
	if ( ++p == pe )
		goto _test_eof612;
case 612:
	switch( (*p) ) {
		case 32: goto tr647;
		case 59: goto tr648;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr647;
	goto st0;
st613:
	if ( ++p == pe )
		goto _test_eof613;
case 613:
	if ( (*p) == 101 )
		goto st614;
	goto st0;
st614:
	if ( ++p == pe )
		goto _test_eof614;
case 614:
	if ( (*p) == 110 )
		goto st615;
	goto st0;
st615:
	if ( ++p == pe )
		goto _test_eof615;
case 615:
	if ( (*p) == 100 )
		goto st616;
	goto st0;
st616:
	if ( ++p == pe )
		goto _test_eof616;
case 616:
	if ( (*p) == 32 )
		goto st617;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st617;
	goto st0;
st617:
	if ( ++p == pe )
		goto _test_eof617;
case 617:
	if ( (*p) == 32 )
		goto st617;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st617;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr653;
		} else if ( (*p) >= 65 )
			goto tr653;
	} else
		goto tr653;
	goto st0;
tr653:
#line 60 "croissant/test.c.rl"
	{ start = p; }
	goto st618;
st618:
	if ( ++p == pe )
		goto _test_eof618;
case 618:
#line 7545 "croissant/test.c"
	if ( (*p) == 32 )
		goto tr654;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr654;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st618;
		} else if ( (*p) >= 65 )
			goto st618;
	} else
		goto st618;
	goto st0;
tr654:
#line 61 "croissant/test.c.rl"
	{ cork_buffer_set(&message, start, p - start); }
	goto st619;
st619:
	if ( ++p == pe )
		goto _test_eof619;
case 619:
#line 7568 "croissant/test.c"
	switch( (*p) ) {
		case 32: goto st619;
		case 116: goto st620;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st619;
	goto st0;
st620:
	if ( ++p == pe )
		goto _test_eof620;
case 620:
	if ( (*p) == 111 )
		goto st621;
	goto st0;
st621:
	if ( ++p == pe )
		goto _test_eof621;
case 621:
	if ( (*p) == 32 )
		goto st622;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st622;
	goto st0;
st622:
	if ( ++p == pe )
		goto _test_eof622;
case 622:
	if ( (*p) == 32 )
		goto st622;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st622;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto tr660;
		} else if ( (*p) >= 65 )
			goto tr660;
	} else
		goto tr660;
	goto st0;
tr660:
#line 55 "croissant/test.c.rl"
	{ start = p; }
	goto st623;
st623:
	if ( ++p == pe )
		goto _test_eof623;
case 623:
#line 7618 "croissant/test.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st624;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st624;
	} else
		goto st624;
	goto st0;
st624:
	if ( ++p == pe )
		goto _test_eof624;
case 624:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st625;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st625;
	} else
		goto st625;
	goto st0;
st625:
	if ( ++p == pe )
		goto _test_eof625;
case 625:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st626;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st626;
	} else
		goto st626;
	goto st0;
st626:
	if ( ++p == pe )
		goto _test_eof626;
case 626:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st627;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st627;
	} else
		goto st627;
	goto st0;
st627:
	if ( ++p == pe )
		goto _test_eof627;
case 627:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st628;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st628;
	} else
		goto st628;
	goto st0;
st628:
	if ( ++p == pe )
		goto _test_eof628;
case 628:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st629;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st629;
	} else
		goto st629;
	goto st0;
st629:
	if ( ++p == pe )
		goto _test_eof629;
case 629:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st630;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st630;
	} else
		goto st630;
	goto st0;
st630:
	if ( ++p == pe )
		goto _test_eof630;
case 630:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st631;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st631;
	} else
		goto st631;
	goto st0;
st631:
	if ( ++p == pe )
		goto _test_eof631;
case 631:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st632;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st632;
	} else
		goto st632;
	goto st0;
st632:
	if ( ++p == pe )
		goto _test_eof632;
case 632:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st633;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st633;
	} else
		goto st633;
	goto st0;
st633:
	if ( ++p == pe )
		goto _test_eof633;
case 633:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st634;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st634;
	} else
		goto st634;
	goto st0;
st634:
	if ( ++p == pe )
		goto _test_eof634;
case 634:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st635;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st635;
	} else
		goto st635;
	goto st0;
st635:
	if ( ++p == pe )
		goto _test_eof635;
case 635:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st636;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st636;
	} else
		goto st636;
	goto st0;
st636:
	if ( ++p == pe )
		goto _test_eof636;
case 636:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st637;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st637;
	} else
		goto st637;
	goto st0;
st637:
	if ( ++p == pe )
		goto _test_eof637;
case 637:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st638;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st638;
	} else
		goto st638;
	goto st0;
st638:
	if ( ++p == pe )
		goto _test_eof638;
case 638:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st639;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st639;
	} else
		goto st639;
	goto st0;
st639:
	if ( ++p == pe )
		goto _test_eof639;
case 639:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st640;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st640;
	} else
		goto st640;
	goto st0;
st640:
	if ( ++p == pe )
		goto _test_eof640;
case 640:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st641;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st641;
	} else
		goto st641;
	goto st0;
st641:
	if ( ++p == pe )
		goto _test_eof641;
case 641:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st642;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st642;
	} else
		goto st642;
	goto st0;
st642:
	if ( ++p == pe )
		goto _test_eof642;
case 642:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st643;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st643;
	} else
		goto st643;
	goto st0;
st643:
	if ( ++p == pe )
		goto _test_eof643;
case 643:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st644;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st644;
	} else
		goto st644;
	goto st0;
st644:
	if ( ++p == pe )
		goto _test_eof644;
case 644:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st645;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st645;
	} else
		goto st645;
	goto st0;
st645:
	if ( ++p == pe )
		goto _test_eof645;
case 645:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st646;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st646;
	} else
		goto st646;
	goto st0;
st646:
	if ( ++p == pe )
		goto _test_eof646;
case 646:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st647;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st647;
	} else
		goto st647;
	goto st0;
st647:
	if ( ++p == pe )
		goto _test_eof647;
case 647:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st648;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st648;
	} else
		goto st648;
	goto st0;
st648:
	if ( ++p == pe )
		goto _test_eof648;
case 648:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st649;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st649;
	} else
		goto st649;
	goto st0;
st649:
	if ( ++p == pe )
		goto _test_eof649;
case 649:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st650;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st650;
	} else
		goto st650;
	goto st0;
st650:
	if ( ++p == pe )
		goto _test_eof650;
case 650:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st651;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st651;
	} else
		goto st651;
	goto st0;
st651:
	if ( ++p == pe )
		goto _test_eof651;
case 651:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st652;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st652;
	} else
		goto st652;
	goto st0;
st652:
	if ( ++p == pe )
		goto _test_eof652;
case 652:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st653;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st653;
	} else
		goto st653;
	goto st0;
st653:
	if ( ++p == pe )
		goto _test_eof653;
case 653:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st654;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st654;
	} else
		goto st654;
	goto st0;
st654:
	if ( ++p == pe )
		goto _test_eof654;
case 654:
	switch( (*p) ) {
		case 32: goto tr692;
		case 59: goto tr693;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr692;
	goto st0;
	}
	_test_eof655: cs = 655; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof150: cs = 150; goto _test_eof; 
	_test_eof151: cs = 151; goto _test_eof; 
	_test_eof152: cs = 152; goto _test_eof; 
	_test_eof153: cs = 153; goto _test_eof; 
	_test_eof154: cs = 154; goto _test_eof; 
	_test_eof155: cs = 155; goto _test_eof; 
	_test_eof156: cs = 156; goto _test_eof; 
	_test_eof157: cs = 157; goto _test_eof; 
	_test_eof158: cs = 158; goto _test_eof; 
	_test_eof159: cs = 159; goto _test_eof; 
	_test_eof160: cs = 160; goto _test_eof; 
	_test_eof161: cs = 161; goto _test_eof; 
	_test_eof162: cs = 162; goto _test_eof; 
	_test_eof163: cs = 163; goto _test_eof; 
	_test_eof164: cs = 164; goto _test_eof; 
	_test_eof165: cs = 165; goto _test_eof; 
	_test_eof166: cs = 166; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof170: cs = 170; goto _test_eof; 
	_test_eof171: cs = 171; goto _test_eof; 
	_test_eof172: cs = 172; goto _test_eof; 
	_test_eof173: cs = 173; goto _test_eof; 
	_test_eof174: cs = 174; goto _test_eof; 
	_test_eof175: cs = 175; goto _test_eof; 
	_test_eof176: cs = 176; goto _test_eof; 
	_test_eof177: cs = 177; goto _test_eof; 
	_test_eof178: cs = 178; goto _test_eof; 
	_test_eof179: cs = 179; goto _test_eof; 
	_test_eof180: cs = 180; goto _test_eof; 
	_test_eof181: cs = 181; goto _test_eof; 
	_test_eof182: cs = 182; goto _test_eof; 
	_test_eof183: cs = 183; goto _test_eof; 
	_test_eof184: cs = 184; goto _test_eof; 
	_test_eof185: cs = 185; goto _test_eof; 
	_test_eof186: cs = 186; goto _test_eof; 
	_test_eof187: cs = 187; goto _test_eof; 
	_test_eof188: cs = 188; goto _test_eof; 
	_test_eof189: cs = 189; goto _test_eof; 
	_test_eof190: cs = 190; goto _test_eof; 
	_test_eof191: cs = 191; goto _test_eof; 
	_test_eof192: cs = 192; goto _test_eof; 
	_test_eof193: cs = 193; goto _test_eof; 
	_test_eof194: cs = 194; goto _test_eof; 
	_test_eof195: cs = 195; goto _test_eof; 
	_test_eof196: cs = 196; goto _test_eof; 
	_test_eof197: cs = 197; goto _test_eof; 
	_test_eof198: cs = 198; goto _test_eof; 
	_test_eof199: cs = 199; goto _test_eof; 
	_test_eof200: cs = 200; goto _test_eof; 
	_test_eof201: cs = 201; goto _test_eof; 
	_test_eof202: cs = 202; goto _test_eof; 
	_test_eof203: cs = 203; goto _test_eof; 
	_test_eof204: cs = 204; goto _test_eof; 
	_test_eof205: cs = 205; goto _test_eof; 
	_test_eof206: cs = 206; goto _test_eof; 
	_test_eof207: cs = 207; goto _test_eof; 
	_test_eof208: cs = 208; goto _test_eof; 
	_test_eof209: cs = 209; goto _test_eof; 
	_test_eof210: cs = 210; goto _test_eof; 
	_test_eof211: cs = 211; goto _test_eof; 
	_test_eof212: cs = 212; goto _test_eof; 
	_test_eof213: cs = 213; goto _test_eof; 
	_test_eof214: cs = 214; goto _test_eof; 
	_test_eof215: cs = 215; goto _test_eof; 
	_test_eof216: cs = 216; goto _test_eof; 
	_test_eof217: cs = 217; goto _test_eof; 
	_test_eof218: cs = 218; goto _test_eof; 
	_test_eof219: cs = 219; goto _test_eof; 
	_test_eof220: cs = 220; goto _test_eof; 
	_test_eof221: cs = 221; goto _test_eof; 
	_test_eof222: cs = 222; goto _test_eof; 
	_test_eof223: cs = 223; goto _test_eof; 
	_test_eof224: cs = 224; goto _test_eof; 
	_test_eof225: cs = 225; goto _test_eof; 
	_test_eof226: cs = 226; goto _test_eof; 
	_test_eof227: cs = 227; goto _test_eof; 
	_test_eof228: cs = 228; goto _test_eof; 
	_test_eof229: cs = 229; goto _test_eof; 
	_test_eof230: cs = 230; goto _test_eof; 
	_test_eof231: cs = 231; goto _test_eof; 
	_test_eof232: cs = 232; goto _test_eof; 
	_test_eof233: cs = 233; goto _test_eof; 
	_test_eof234: cs = 234; goto _test_eof; 
	_test_eof235: cs = 235; goto _test_eof; 
	_test_eof236: cs = 236; goto _test_eof; 
	_test_eof237: cs = 237; goto _test_eof; 
	_test_eof238: cs = 238; goto _test_eof; 
	_test_eof239: cs = 239; goto _test_eof; 
	_test_eof240: cs = 240; goto _test_eof; 
	_test_eof241: cs = 241; goto _test_eof; 
	_test_eof242: cs = 242; goto _test_eof; 
	_test_eof243: cs = 243; goto _test_eof; 
	_test_eof244: cs = 244; goto _test_eof; 
	_test_eof245: cs = 245; goto _test_eof; 
	_test_eof246: cs = 246; goto _test_eof; 
	_test_eof247: cs = 247; goto _test_eof; 
	_test_eof248: cs = 248; goto _test_eof; 
	_test_eof249: cs = 249; goto _test_eof; 
	_test_eof250: cs = 250; goto _test_eof; 
	_test_eof251: cs = 251; goto _test_eof; 
	_test_eof252: cs = 252; goto _test_eof; 
	_test_eof253: cs = 253; goto _test_eof; 
	_test_eof254: cs = 254; goto _test_eof; 
	_test_eof255: cs = 255; goto _test_eof; 
	_test_eof256: cs = 256; goto _test_eof; 
	_test_eof257: cs = 257; goto _test_eof; 
	_test_eof258: cs = 258; goto _test_eof; 
	_test_eof259: cs = 259; goto _test_eof; 
	_test_eof260: cs = 260; goto _test_eof; 
	_test_eof261: cs = 261; goto _test_eof; 
	_test_eof262: cs = 262; goto _test_eof; 
	_test_eof263: cs = 263; goto _test_eof; 
	_test_eof264: cs = 264; goto _test_eof; 
	_test_eof265: cs = 265; goto _test_eof; 
	_test_eof266: cs = 266; goto _test_eof; 
	_test_eof267: cs = 267; goto _test_eof; 
	_test_eof268: cs = 268; goto _test_eof; 
	_test_eof269: cs = 269; goto _test_eof; 
	_test_eof270: cs = 270; goto _test_eof; 
	_test_eof271: cs = 271; goto _test_eof; 
	_test_eof272: cs = 272; goto _test_eof; 
	_test_eof273: cs = 273; goto _test_eof; 
	_test_eof274: cs = 274; goto _test_eof; 
	_test_eof275: cs = 275; goto _test_eof; 
	_test_eof276: cs = 276; goto _test_eof; 
	_test_eof277: cs = 277; goto _test_eof; 
	_test_eof278: cs = 278; goto _test_eof; 
	_test_eof279: cs = 279; goto _test_eof; 
	_test_eof280: cs = 280; goto _test_eof; 
	_test_eof281: cs = 281; goto _test_eof; 
	_test_eof282: cs = 282; goto _test_eof; 
	_test_eof283: cs = 283; goto _test_eof; 
	_test_eof284: cs = 284; goto _test_eof; 
	_test_eof285: cs = 285; goto _test_eof; 
	_test_eof286: cs = 286; goto _test_eof; 
	_test_eof287: cs = 287; goto _test_eof; 
	_test_eof288: cs = 288; goto _test_eof; 
	_test_eof289: cs = 289; goto _test_eof; 
	_test_eof290: cs = 290; goto _test_eof; 
	_test_eof291: cs = 291; goto _test_eof; 
	_test_eof292: cs = 292; goto _test_eof; 
	_test_eof293: cs = 293; goto _test_eof; 
	_test_eof294: cs = 294; goto _test_eof; 
	_test_eof295: cs = 295; goto _test_eof; 
	_test_eof296: cs = 296; goto _test_eof; 
	_test_eof297: cs = 297; goto _test_eof; 
	_test_eof298: cs = 298; goto _test_eof; 
	_test_eof299: cs = 299; goto _test_eof; 
	_test_eof300: cs = 300; goto _test_eof; 
	_test_eof301: cs = 301; goto _test_eof; 
	_test_eof302: cs = 302; goto _test_eof; 
	_test_eof303: cs = 303; goto _test_eof; 
	_test_eof304: cs = 304; goto _test_eof; 
	_test_eof305: cs = 305; goto _test_eof; 
	_test_eof306: cs = 306; goto _test_eof; 
	_test_eof307: cs = 307; goto _test_eof; 
	_test_eof308: cs = 308; goto _test_eof; 
	_test_eof309: cs = 309; goto _test_eof; 
	_test_eof310: cs = 310; goto _test_eof; 
	_test_eof311: cs = 311; goto _test_eof; 
	_test_eof312: cs = 312; goto _test_eof; 
	_test_eof313: cs = 313; goto _test_eof; 
	_test_eof314: cs = 314; goto _test_eof; 
	_test_eof315: cs = 315; goto _test_eof; 
	_test_eof316: cs = 316; goto _test_eof; 
	_test_eof317: cs = 317; goto _test_eof; 
	_test_eof318: cs = 318; goto _test_eof; 
	_test_eof319: cs = 319; goto _test_eof; 
	_test_eof320: cs = 320; goto _test_eof; 
	_test_eof321: cs = 321; goto _test_eof; 
	_test_eof322: cs = 322; goto _test_eof; 
	_test_eof323: cs = 323; goto _test_eof; 
	_test_eof324: cs = 324; goto _test_eof; 
	_test_eof325: cs = 325; goto _test_eof; 
	_test_eof326: cs = 326; goto _test_eof; 
	_test_eof327: cs = 327; goto _test_eof; 
	_test_eof328: cs = 328; goto _test_eof; 
	_test_eof329: cs = 329; goto _test_eof; 
	_test_eof330: cs = 330; goto _test_eof; 
	_test_eof331: cs = 331; goto _test_eof; 
	_test_eof332: cs = 332; goto _test_eof; 
	_test_eof333: cs = 333; goto _test_eof; 
	_test_eof334: cs = 334; goto _test_eof; 
	_test_eof335: cs = 335; goto _test_eof; 
	_test_eof336: cs = 336; goto _test_eof; 
	_test_eof337: cs = 337; goto _test_eof; 
	_test_eof338: cs = 338; goto _test_eof; 
	_test_eof339: cs = 339; goto _test_eof; 
	_test_eof340: cs = 340; goto _test_eof; 
	_test_eof341: cs = 341; goto _test_eof; 
	_test_eof342: cs = 342; goto _test_eof; 
	_test_eof343: cs = 343; goto _test_eof; 
	_test_eof344: cs = 344; goto _test_eof; 
	_test_eof345: cs = 345; goto _test_eof; 
	_test_eof346: cs = 346; goto _test_eof; 
	_test_eof347: cs = 347; goto _test_eof; 
	_test_eof348: cs = 348; goto _test_eof; 
	_test_eof349: cs = 349; goto _test_eof; 
	_test_eof350: cs = 350; goto _test_eof; 
	_test_eof351: cs = 351; goto _test_eof; 
	_test_eof352: cs = 352; goto _test_eof; 
	_test_eof353: cs = 353; goto _test_eof; 
	_test_eof354: cs = 354; goto _test_eof; 
	_test_eof355: cs = 355; goto _test_eof; 
	_test_eof356: cs = 356; goto _test_eof; 
	_test_eof357: cs = 357; goto _test_eof; 
	_test_eof358: cs = 358; goto _test_eof; 
	_test_eof359: cs = 359; goto _test_eof; 
	_test_eof360: cs = 360; goto _test_eof; 
	_test_eof361: cs = 361; goto _test_eof; 
	_test_eof362: cs = 362; goto _test_eof; 
	_test_eof363: cs = 363; goto _test_eof; 
	_test_eof364: cs = 364; goto _test_eof; 
	_test_eof365: cs = 365; goto _test_eof; 
	_test_eof366: cs = 366; goto _test_eof; 
	_test_eof367: cs = 367; goto _test_eof; 
	_test_eof368: cs = 368; goto _test_eof; 
	_test_eof369: cs = 369; goto _test_eof; 
	_test_eof370: cs = 370; goto _test_eof; 
	_test_eof371: cs = 371; goto _test_eof; 
	_test_eof372: cs = 372; goto _test_eof; 
	_test_eof373: cs = 373; goto _test_eof; 
	_test_eof374: cs = 374; goto _test_eof; 
	_test_eof375: cs = 375; goto _test_eof; 
	_test_eof376: cs = 376; goto _test_eof; 
	_test_eof377: cs = 377; goto _test_eof; 
	_test_eof378: cs = 378; goto _test_eof; 
	_test_eof379: cs = 379; goto _test_eof; 
	_test_eof380: cs = 380; goto _test_eof; 
	_test_eof381: cs = 381; goto _test_eof; 
	_test_eof382: cs = 382; goto _test_eof; 
	_test_eof383: cs = 383; goto _test_eof; 
	_test_eof384: cs = 384; goto _test_eof; 
	_test_eof385: cs = 385; goto _test_eof; 
	_test_eof386: cs = 386; goto _test_eof; 
	_test_eof387: cs = 387; goto _test_eof; 
	_test_eof388: cs = 388; goto _test_eof; 
	_test_eof389: cs = 389; goto _test_eof; 
	_test_eof390: cs = 390; goto _test_eof; 
	_test_eof391: cs = 391; goto _test_eof; 
	_test_eof392: cs = 392; goto _test_eof; 
	_test_eof393: cs = 393; goto _test_eof; 
	_test_eof394: cs = 394; goto _test_eof; 
	_test_eof395: cs = 395; goto _test_eof; 
	_test_eof396: cs = 396; goto _test_eof; 
	_test_eof397: cs = 397; goto _test_eof; 
	_test_eof398: cs = 398; goto _test_eof; 
	_test_eof399: cs = 399; goto _test_eof; 
	_test_eof400: cs = 400; goto _test_eof; 
	_test_eof401: cs = 401; goto _test_eof; 
	_test_eof402: cs = 402; goto _test_eof; 
	_test_eof403: cs = 403; goto _test_eof; 
	_test_eof404: cs = 404; goto _test_eof; 
	_test_eof405: cs = 405; goto _test_eof; 
	_test_eof406: cs = 406; goto _test_eof; 
	_test_eof407: cs = 407; goto _test_eof; 
	_test_eof408: cs = 408; goto _test_eof; 
	_test_eof409: cs = 409; goto _test_eof; 
	_test_eof410: cs = 410; goto _test_eof; 
	_test_eof411: cs = 411; goto _test_eof; 
	_test_eof412: cs = 412; goto _test_eof; 
	_test_eof413: cs = 413; goto _test_eof; 
	_test_eof414: cs = 414; goto _test_eof; 
	_test_eof415: cs = 415; goto _test_eof; 
	_test_eof416: cs = 416; goto _test_eof; 
	_test_eof417: cs = 417; goto _test_eof; 
	_test_eof418: cs = 418; goto _test_eof; 
	_test_eof419: cs = 419; goto _test_eof; 
	_test_eof420: cs = 420; goto _test_eof; 
	_test_eof421: cs = 421; goto _test_eof; 
	_test_eof422: cs = 422; goto _test_eof; 
	_test_eof423: cs = 423; goto _test_eof; 
	_test_eof424: cs = 424; goto _test_eof; 
	_test_eof425: cs = 425; goto _test_eof; 
	_test_eof426: cs = 426; goto _test_eof; 
	_test_eof427: cs = 427; goto _test_eof; 
	_test_eof428: cs = 428; goto _test_eof; 
	_test_eof429: cs = 429; goto _test_eof; 
	_test_eof430: cs = 430; goto _test_eof; 
	_test_eof431: cs = 431; goto _test_eof; 
	_test_eof432: cs = 432; goto _test_eof; 
	_test_eof433: cs = 433; goto _test_eof; 
	_test_eof434: cs = 434; goto _test_eof; 
	_test_eof435: cs = 435; goto _test_eof; 
	_test_eof436: cs = 436; goto _test_eof; 
	_test_eof437: cs = 437; goto _test_eof; 
	_test_eof438: cs = 438; goto _test_eof; 
	_test_eof439: cs = 439; goto _test_eof; 
	_test_eof440: cs = 440; goto _test_eof; 
	_test_eof441: cs = 441; goto _test_eof; 
	_test_eof442: cs = 442; goto _test_eof; 
	_test_eof443: cs = 443; goto _test_eof; 
	_test_eof444: cs = 444; goto _test_eof; 
	_test_eof445: cs = 445; goto _test_eof; 
	_test_eof446: cs = 446; goto _test_eof; 
	_test_eof447: cs = 447; goto _test_eof; 
	_test_eof448: cs = 448; goto _test_eof; 
	_test_eof449: cs = 449; goto _test_eof; 
	_test_eof450: cs = 450; goto _test_eof; 
	_test_eof451: cs = 451; goto _test_eof; 
	_test_eof452: cs = 452; goto _test_eof; 
	_test_eof453: cs = 453; goto _test_eof; 
	_test_eof454: cs = 454; goto _test_eof; 
	_test_eof455: cs = 455; goto _test_eof; 
	_test_eof456: cs = 456; goto _test_eof; 
	_test_eof457: cs = 457; goto _test_eof; 
	_test_eof458: cs = 458; goto _test_eof; 
	_test_eof459: cs = 459; goto _test_eof; 
	_test_eof460: cs = 460; goto _test_eof; 
	_test_eof461: cs = 461; goto _test_eof; 
	_test_eof462: cs = 462; goto _test_eof; 
	_test_eof463: cs = 463; goto _test_eof; 
	_test_eof464: cs = 464; goto _test_eof; 
	_test_eof465: cs = 465; goto _test_eof; 
	_test_eof466: cs = 466; goto _test_eof; 
	_test_eof467: cs = 467; goto _test_eof; 
	_test_eof468: cs = 468; goto _test_eof; 
	_test_eof469: cs = 469; goto _test_eof; 
	_test_eof470: cs = 470; goto _test_eof; 
	_test_eof471: cs = 471; goto _test_eof; 
	_test_eof472: cs = 472; goto _test_eof; 
	_test_eof473: cs = 473; goto _test_eof; 
	_test_eof474: cs = 474; goto _test_eof; 
	_test_eof475: cs = 475; goto _test_eof; 
	_test_eof476: cs = 476; goto _test_eof; 
	_test_eof477: cs = 477; goto _test_eof; 
	_test_eof478: cs = 478; goto _test_eof; 
	_test_eof479: cs = 479; goto _test_eof; 
	_test_eof480: cs = 480; goto _test_eof; 
	_test_eof481: cs = 481; goto _test_eof; 
	_test_eof482: cs = 482; goto _test_eof; 
	_test_eof483: cs = 483; goto _test_eof; 
	_test_eof484: cs = 484; goto _test_eof; 
	_test_eof485: cs = 485; goto _test_eof; 
	_test_eof486: cs = 486; goto _test_eof; 
	_test_eof487: cs = 487; goto _test_eof; 
	_test_eof488: cs = 488; goto _test_eof; 
	_test_eof489: cs = 489; goto _test_eof; 
	_test_eof490: cs = 490; goto _test_eof; 
	_test_eof491: cs = 491; goto _test_eof; 
	_test_eof492: cs = 492; goto _test_eof; 
	_test_eof493: cs = 493; goto _test_eof; 
	_test_eof494: cs = 494; goto _test_eof; 
	_test_eof495: cs = 495; goto _test_eof; 
	_test_eof496: cs = 496; goto _test_eof; 
	_test_eof497: cs = 497; goto _test_eof; 
	_test_eof498: cs = 498; goto _test_eof; 
	_test_eof499: cs = 499; goto _test_eof; 
	_test_eof500: cs = 500; goto _test_eof; 
	_test_eof501: cs = 501; goto _test_eof; 
	_test_eof502: cs = 502; goto _test_eof; 
	_test_eof503: cs = 503; goto _test_eof; 
	_test_eof504: cs = 504; goto _test_eof; 
	_test_eof505: cs = 505; goto _test_eof; 
	_test_eof506: cs = 506; goto _test_eof; 
	_test_eof507: cs = 507; goto _test_eof; 
	_test_eof508: cs = 508; goto _test_eof; 
	_test_eof509: cs = 509; goto _test_eof; 
	_test_eof510: cs = 510; goto _test_eof; 
	_test_eof511: cs = 511; goto _test_eof; 
	_test_eof512: cs = 512; goto _test_eof; 
	_test_eof513: cs = 513; goto _test_eof; 
	_test_eof514: cs = 514; goto _test_eof; 
	_test_eof515: cs = 515; goto _test_eof; 
	_test_eof516: cs = 516; goto _test_eof; 
	_test_eof517: cs = 517; goto _test_eof; 
	_test_eof518: cs = 518; goto _test_eof; 
	_test_eof519: cs = 519; goto _test_eof; 
	_test_eof520: cs = 520; goto _test_eof; 
	_test_eof521: cs = 521; goto _test_eof; 
	_test_eof522: cs = 522; goto _test_eof; 
	_test_eof523: cs = 523; goto _test_eof; 
	_test_eof524: cs = 524; goto _test_eof; 
	_test_eof525: cs = 525; goto _test_eof; 
	_test_eof526: cs = 526; goto _test_eof; 
	_test_eof527: cs = 527; goto _test_eof; 
	_test_eof528: cs = 528; goto _test_eof; 
	_test_eof529: cs = 529; goto _test_eof; 
	_test_eof530: cs = 530; goto _test_eof; 
	_test_eof531: cs = 531; goto _test_eof; 
	_test_eof532: cs = 532; goto _test_eof; 
	_test_eof533: cs = 533; goto _test_eof; 
	_test_eof534: cs = 534; goto _test_eof; 
	_test_eof535: cs = 535; goto _test_eof; 
	_test_eof536: cs = 536; goto _test_eof; 
	_test_eof537: cs = 537; goto _test_eof; 
	_test_eof538: cs = 538; goto _test_eof; 
	_test_eof539: cs = 539; goto _test_eof; 
	_test_eof540: cs = 540; goto _test_eof; 
	_test_eof541: cs = 541; goto _test_eof; 
	_test_eof542: cs = 542; goto _test_eof; 
	_test_eof543: cs = 543; goto _test_eof; 
	_test_eof544: cs = 544; goto _test_eof; 
	_test_eof545: cs = 545; goto _test_eof; 
	_test_eof546: cs = 546; goto _test_eof; 
	_test_eof547: cs = 547; goto _test_eof; 
	_test_eof548: cs = 548; goto _test_eof; 
	_test_eof549: cs = 549; goto _test_eof; 
	_test_eof550: cs = 550; goto _test_eof; 
	_test_eof551: cs = 551; goto _test_eof; 
	_test_eof552: cs = 552; goto _test_eof; 
	_test_eof553: cs = 553; goto _test_eof; 
	_test_eof554: cs = 554; goto _test_eof; 
	_test_eof555: cs = 555; goto _test_eof; 
	_test_eof556: cs = 556; goto _test_eof; 
	_test_eof557: cs = 557; goto _test_eof; 
	_test_eof558: cs = 558; goto _test_eof; 
	_test_eof559: cs = 559; goto _test_eof; 
	_test_eof560: cs = 560; goto _test_eof; 
	_test_eof561: cs = 561; goto _test_eof; 
	_test_eof562: cs = 562; goto _test_eof; 
	_test_eof563: cs = 563; goto _test_eof; 
	_test_eof564: cs = 564; goto _test_eof; 
	_test_eof565: cs = 565; goto _test_eof; 
	_test_eof566: cs = 566; goto _test_eof; 
	_test_eof567: cs = 567; goto _test_eof; 
	_test_eof568: cs = 568; goto _test_eof; 
	_test_eof569: cs = 569; goto _test_eof; 
	_test_eof570: cs = 570; goto _test_eof; 
	_test_eof571: cs = 571; goto _test_eof; 
	_test_eof572: cs = 572; goto _test_eof; 
	_test_eof573: cs = 573; goto _test_eof; 
	_test_eof574: cs = 574; goto _test_eof; 
	_test_eof575: cs = 575; goto _test_eof; 
	_test_eof576: cs = 576; goto _test_eof; 
	_test_eof577: cs = 577; goto _test_eof; 
	_test_eof578: cs = 578; goto _test_eof; 
	_test_eof579: cs = 579; goto _test_eof; 
	_test_eof580: cs = 580; goto _test_eof; 
	_test_eof581: cs = 581; goto _test_eof; 
	_test_eof582: cs = 582; goto _test_eof; 
	_test_eof583: cs = 583; goto _test_eof; 
	_test_eof584: cs = 584; goto _test_eof; 
	_test_eof585: cs = 585; goto _test_eof; 
	_test_eof586: cs = 586; goto _test_eof; 
	_test_eof587: cs = 587; goto _test_eof; 
	_test_eof588: cs = 588; goto _test_eof; 
	_test_eof589: cs = 589; goto _test_eof; 
	_test_eof590: cs = 590; goto _test_eof; 
	_test_eof591: cs = 591; goto _test_eof; 
	_test_eof592: cs = 592; goto _test_eof; 
	_test_eof593: cs = 593; goto _test_eof; 
	_test_eof594: cs = 594; goto _test_eof; 
	_test_eof595: cs = 595; goto _test_eof; 
	_test_eof596: cs = 596; goto _test_eof; 
	_test_eof597: cs = 597; goto _test_eof; 
	_test_eof598: cs = 598; goto _test_eof; 
	_test_eof599: cs = 599; goto _test_eof; 
	_test_eof600: cs = 600; goto _test_eof; 
	_test_eof601: cs = 601; goto _test_eof; 
	_test_eof602: cs = 602; goto _test_eof; 
	_test_eof603: cs = 603; goto _test_eof; 
	_test_eof604: cs = 604; goto _test_eof; 
	_test_eof605: cs = 605; goto _test_eof; 
	_test_eof606: cs = 606; goto _test_eof; 
	_test_eof607: cs = 607; goto _test_eof; 
	_test_eof608: cs = 608; goto _test_eof; 
	_test_eof609: cs = 609; goto _test_eof; 
	_test_eof610: cs = 610; goto _test_eof; 
	_test_eof611: cs = 611; goto _test_eof; 
	_test_eof612: cs = 612; goto _test_eof; 
	_test_eof613: cs = 613; goto _test_eof; 
	_test_eof614: cs = 614; goto _test_eof; 
	_test_eof615: cs = 615; goto _test_eof; 
	_test_eof616: cs = 616; goto _test_eof; 
	_test_eof617: cs = 617; goto _test_eof; 
	_test_eof618: cs = 618; goto _test_eof; 
	_test_eof619: cs = 619; goto _test_eof; 
	_test_eof620: cs = 620; goto _test_eof; 
	_test_eof621: cs = 621; goto _test_eof; 
	_test_eof622: cs = 622; goto _test_eof; 
	_test_eof623: cs = 623; goto _test_eof; 
	_test_eof624: cs = 624; goto _test_eof; 
	_test_eof625: cs = 625; goto _test_eof; 
	_test_eof626: cs = 626; goto _test_eof; 
	_test_eof627: cs = 627; goto _test_eof; 
	_test_eof628: cs = 628; goto _test_eof; 
	_test_eof629: cs = 629; goto _test_eof; 
	_test_eof630: cs = 630; goto _test_eof; 
	_test_eof631: cs = 631; goto _test_eof; 
	_test_eof632: cs = 632; goto _test_eof; 
	_test_eof633: cs = 633; goto _test_eof; 
	_test_eof634: cs = 634; goto _test_eof; 
	_test_eof635: cs = 635; goto _test_eof; 
	_test_eof636: cs = 636; goto _test_eof; 
	_test_eof637: cs = 637; goto _test_eof; 
	_test_eof638: cs = 638; goto _test_eof; 
	_test_eof639: cs = 639; goto _test_eof; 
	_test_eof640: cs = 640; goto _test_eof; 
	_test_eof641: cs = 641; goto _test_eof; 
	_test_eof642: cs = 642; goto _test_eof; 
	_test_eof643: cs = 643; goto _test_eof; 
	_test_eof644: cs = 644; goto _test_eof; 
	_test_eof645: cs = 645; goto _test_eof; 
	_test_eof646: cs = 646; goto _test_eof; 
	_test_eof647: cs = 647; goto _test_eof; 
	_test_eof648: cs = 648; goto _test_eof; 
	_test_eof649: cs = 649; goto _test_eof; 
	_test_eof650: cs = 650; goto _test_eof; 
	_test_eof651: cs = 651; goto _test_eof; 
	_test_eof652: cs = 652; goto _test_eof; 
	_test_eof653: cs = 653; goto _test_eof; 
	_test_eof654: cs = 654; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 655: 
#line 209 "croissant/test.c.rl"
	{
                    fprintf(stderr, "---\n");
                }
	break;
#line 8696 "croissant/test.c"
	}
	}

	_out: {}
	}

#line 216 "croissant/test.c.rl"


    /* A hack to suppress some unused variable warnings */
    (void) crs_command_en_main;

    if (CORK_UNLIKELY(cs < 
#line 8710 "croissant/test.c"
655
#line 221 "croissant/test.c.rl"
)) {
        crs_parse_error("Invalid command");
        goto error;
    }

    cork_buffer_done(&buf);
    cork_buffer_done(&message);
    cork_buffer_done(&output);
    return 0;

error:
    cork_buffer_done(&buf);
    cork_buffer_done(&message);
    cork_buffer_done(&output);
    return -1;
}

static void
execute(int argc, char **argv)
{
    struct crs_ctx  *ctx = crs_ctx_new();
    struct cork_buffer  buf = CORK_BUFFER_INIT();
    struct cork_stream_consumer  *consumer;

    clog_set_default_format("#!{address}{[%v] }%m");
    if (clog_setup_logging() != 0) {
        fprintf(stderr, "%s\n", cork_error_message());
        exit(EXIT_FAILURE);
    }

    cork_buffer_set(&buf, "", 0);
    consumer = cork_buffer_to_stream_consumer(&buf);
    if (cork_consume_file(consumer, stdin) != 0) {
        fprintf(stderr, "%s\n", cork_error_message());
        cork_stream_consumer_free(consumer);
        cork_buffer_done(&buf);
        crs_ctx_free(ctx);
        exit(EXIT_FAILURE);
    }

    if (crs_parse_command(ctx, buf.buf) != 0) {
        fprintf(stderr, "%s\n", cork_error_message());
        cork_stream_consumer_free(consumer);
        cork_buffer_done(&buf);
        crs_ctx_free(ctx);
        exit(EXIT_FAILURE);
    }

    cork_stream_consumer_free(consumer);
    cork_buffer_done(&buf);
    crs_ctx_free(ctx);
}

#define SHORT_DESC \
    "Test a Pastry network"

#define USAGE_SUFFIX \
    ""

#define HELP_TEXT \
    ""

struct cork_command  croissant_test =
    cork_leaf_command("test", SHORT_DESC, USAGE_SUFFIX, HELP_TEXT,
                      NULL, execute);
