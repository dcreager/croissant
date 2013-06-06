
#line 1 "croissant/test.c.rl"
/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013, RedJack, LLC.
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

static struct crs_node *
crs_ctx_require_node(struct crs_ctx *ctx, const struct crs_id *id)
{
    struct crs_node  *node = crs_ctx_get_node_with_id(ctx, id);
    if (node == NULL) {
        char  id_str[CRS_ID_STRING_LENGTH];
        crs_id_to_raw_string(id, id_str);
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
    const char  *start;

    struct cork_buffer  buf = CORK_BUFFER_INIT();
    struct cork_buffer  output = CORK_BUFFER_INIT();
    struct crs_node  *node;
    struct crs_id  id1;

    
#line 50 "croissant/test.c"
static const int crs_command_start = 343;

static const int crs_command_en_main = 343;


#line 56 "croissant/test.c"
	{
	cs = crs_command_start;
	}

#line 61 "croissant/test.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr43:
#line 51 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 53 "croissant/test.c.rl"
	{ rii_check(crs_id_init(&id1, buf.buf)); }
#line 56 "croissant/test.c.rl"
	{
                rip_check(crs_node_new(ctx, &id1, NULL));
            }
	goto st343;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
#line 81 "croissant/test.c"
	switch( (*p) ) {
		case 32: goto st343;
		case 110: goto st1;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st343;
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
#line 51 "croissant/test.c.rl"
	{ start = p; }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 184 "croissant/test.c"
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
#line 51 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 53 "croissant/test.c.rl"
	{ rii_check(crs_id_init(&id1, buf.buf)); }
#line 56 "croissant/test.c.rl"
	{
                rip_check(crs_node_new(ctx, &id1, NULL));
            }
	goto st42;
tr138:
#line 51 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 53 "croissant/test.c.rl"
	{ rii_check(crs_id_init(&id1, buf.buf)); }
#line 63 "croissant/test.c.rl"
	{
                struct crs_leaf_set  *from_set;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                rip_check(to_node = crs_ctx_require_node(ctx, &id1));
                from_set = crs_node_get_leaf_set(node);
                to_ref = crs_node_get_ref(to_node);
                crs_leaf_set_add(from_set, to_ref);
            }
	goto st42;
tr192:
#line 51 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 53 "croissant/test.c.rl"
	{ rii_check(crs_id_init(&id1, buf.buf)); }
#line 76 "croissant/test.c.rl"
	{
                struct crs_routing_table  *from_table;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                rip_check(to_node = crs_ctx_require_node(ctx, &id1));
                from_table = crs_node_get_routing_table(node);
                to_ref = crs_node_get_ref(to_node);
                crs_routing_table_set(from_table, to_ref);
            }
	goto st42;
tr208:
#line 88 "croissant/test.c.rl"
	{
                struct crs_leaf_set  *set;
                set = crs_node_get_leaf_set(node);
                cork_buffer_printf
                    (&output, "Leaf set for %s\n", crs_node_get_id_str(node));
                crs_leaf_set_print(&output, set);
                fwrite(output.buf, output.size, 1, stdout);
            }
	goto st42;
tr222:
#line 99 "croissant/test.c.rl"
	{
                struct crs_routing_table  *table;
                table = crs_node_get_routing_table(node);
                cork_buffer_printf
                    (&output, "Routing table for %s\n",
                     crs_node_get_id_str(node));
                crs_routing_table_print(&output, table);
                fwrite(output.buf, output.size, 1, stdout);
            }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 664 "croissant/test.c"
	switch( (*p) ) {
		case 32: goto st42;
		case 59: goto st343;
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
#line 51 "croissant/test.c.rl"
	{ start = p; }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 721 "croissant/test.c"
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
#line 51 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 53 "croissant/test.c.rl"
	{ rii_check(crs_id_init(&id1, buf.buf)); }
#line 120 "croissant/test.c.rl"
	{ rip_check(node = crs_ctx_require_node(ctx, &id1)); }
	goto st79;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
#line 1142 "croissant/test.c"
	switch( (*p) ) {
		case 32: goto st79;
		case 97: goto st80;
		case 112: goto st184;
		case 123: goto st211;
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
				goto tr105;
		} else if ( (*p) >= 65 )
			goto tr105;
	} else
		goto tr105;
	goto st0;
tr105:
#line 51 "croissant/test.c.rl"
	{ start = p; }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
#line 1325 "croissant/test.c"
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
		case 32: goto tr137;
		case 59: goto tr138;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr137;
	goto st0;
tr137:
#line 51 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 53 "croissant/test.c.rl"
	{ rii_check(crs_id_init(&id1, buf.buf)); }
#line 63 "croissant/test.c.rl"
	{
                struct crs_leaf_set  *from_set;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                rip_check(to_node = crs_ctx_require_node(ctx, &id1));
                from_set = crs_node_get_leaf_set(node);
                to_ref = crs_node_get_ref(to_node);
                crs_leaf_set_add(from_set, to_ref);
            }
	goto st131;
tr191:
#line 51 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 53 "croissant/test.c.rl"
	{ rii_check(crs_id_init(&id1, buf.buf)); }
#line 76 "croissant/test.c.rl"
	{
                struct crs_routing_table  *from_table;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                rip_check(to_node = crs_ctx_require_node(ctx, &id1));
                from_table = crs_node_get_routing_table(node);
                to_ref = crs_node_get_ref(to_node);
                crs_routing_table_set(from_table, to_ref);
            }
	goto st131;
tr207:
#line 88 "croissant/test.c.rl"
	{
                struct crs_leaf_set  *set;
                set = crs_node_get_leaf_set(node);
                cork_buffer_printf
                    (&output, "Leaf set for %s\n", crs_node_get_id_str(node));
                crs_leaf_set_print(&output, set);
                fwrite(output.buf, output.size, 1, stdout);
            }
	goto st131;
tr221:
#line 99 "croissant/test.c.rl"
	{
                struct crs_routing_table  *table;
                table = crs_node_get_routing_table(node);
                cork_buffer_printf
                    (&output, "Routing table for %s\n",
                     crs_node_get_id_str(node));
                crs_routing_table_print(&output, table);
                fwrite(output.buf, output.size, 1, stdout);
            }
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
#line 1795 "croissant/test.c"
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
				goto tr159;
		} else if ( (*p) >= 65 )
			goto tr159;
	} else
		goto tr159;
	goto st0;
tr159:
#line 51 "croissant/test.c.rl"
	{ start = p; }
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
#line 1976 "croissant/test.c"
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
		case 32: goto tr191;
		case 59: goto tr192;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr191;
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
	if ( (*p) == 105 )
		goto st186;
	goto st0;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	if ( (*p) == 110 )
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
	if ( (*p) == 32 )
		goto st189;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st189;
	goto st0;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	switch( (*p) ) {
		case 32: goto st189;
		case 108: goto st190;
		case 114: goto st198;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st189;
	goto st0;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	if ( (*p) == 101 )
		goto st191;
	goto st0;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	if ( (*p) == 97 )
		goto st192;
	goto st0;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	if ( (*p) == 102 )
		goto st193;
	goto st0;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	if ( (*p) == 32 )
		goto st194;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st194;
	goto st0;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	switch( (*p) ) {
		case 32: goto st194;
		case 115: goto st195;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st194;
	goto st0;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	if ( (*p) == 101 )
		goto st196;
	goto st0;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	if ( (*p) == 116 )
		goto st197;
	goto st0;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	switch( (*p) ) {
		case 32: goto tr207;
		case 59: goto tr208;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr207;
	goto st0;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	if ( (*p) == 111 )
		goto st199;
	goto st0;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	if ( (*p) == 117 )
		goto st200;
	goto st0;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	if ( (*p) == 116 )
		goto st201;
	goto st0;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	if ( (*p) == 105 )
		goto st202;
	goto st0;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	if ( (*p) == 110 )
		goto st203;
	goto st0;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	if ( (*p) == 103 )
		goto st204;
	goto st0;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	if ( (*p) == 32 )
		goto st205;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st205;
	goto st0;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	switch( (*p) ) {
		case 32: goto st205;
		case 116: goto st206;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st205;
	goto st0;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	if ( (*p) == 97 )
		goto st207;
	goto st0;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	if ( (*p) == 98 )
		goto st208;
	goto st0;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	if ( (*p) == 108 )
		goto st209;
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
	switch( (*p) ) {
		case 32: goto tr221;
		case 59: goto tr222;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr221;
	goto st0;
tr277:
#line 51 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 53 "croissant/test.c.rl"
	{ rii_check(crs_id_init(&id1, buf.buf)); }
#line 63 "croissant/test.c.rl"
	{
                struct crs_leaf_set  *from_set;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                rip_check(to_node = crs_ctx_require_node(ctx, &id1));
                from_set = crs_node_get_leaf_set(node);
                to_ref = crs_node_get_ref(to_node);
                crs_leaf_set_add(from_set, to_ref);
            }
	goto st211;
tr331:
#line 51 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 53 "croissant/test.c.rl"
	{ rii_check(crs_id_init(&id1, buf.buf)); }
#line 76 "croissant/test.c.rl"
	{
                struct crs_routing_table  *from_table;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                rip_check(to_node = crs_ctx_require_node(ctx, &id1));
                from_table = crs_node_get_routing_table(node);
                to_ref = crs_node_get_ref(to_node);
                crs_routing_table_set(from_table, to_ref);
            }
	goto st211;
tr347:
#line 88 "croissant/test.c.rl"
	{
                struct crs_leaf_set  *set;
                set = crs_node_get_leaf_set(node);
                cork_buffer_printf
                    (&output, "Leaf set for %s\n", crs_node_get_id_str(node));
                crs_leaf_set_print(&output, set);
                fwrite(output.buf, output.size, 1, stdout);
            }
	goto st211;
tr361:
#line 99 "croissant/test.c.rl"
	{
                struct crs_routing_table  *table;
                table = crs_node_get_routing_table(node);
                cork_buffer_printf
                    (&output, "Routing table for %s\n",
                     crs_node_get_id_str(node));
                crs_routing_table_print(&output, table);
                fwrite(output.buf, output.size, 1, stdout);
            }
	goto st211;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
#line 2662 "croissant/test.c"
	switch( (*p) ) {
		case 32: goto st211;
		case 97: goto st212;
		case 112: goto st316;
		case 125: goto st42;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st211;
	goto st0;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	if ( (*p) == 100 )
		goto st213;
	goto st0;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	if ( (*p) == 100 )
		goto st214;
	goto st0;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	if ( (*p) == 32 )
		goto st215;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st215;
	goto st0;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	switch( (*p) ) {
		case 32: goto st215;
		case 108: goto st216;
		case 114: goto st264;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st215;
	goto st0;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	if ( (*p) == 101 )
		goto st217;
	goto st0;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	if ( (*p) == 97 )
		goto st218;
	goto st0;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	if ( (*p) == 102 )
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
	switch( (*p) ) {
		case 32: goto st220;
		case 115: goto st221;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st220;
	goto st0;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	if ( (*p) == 101 )
		goto st222;
	goto st0;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
	if ( (*p) == 116 )
		goto st223;
	goto st0;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	if ( (*p) == 32 )
		goto st224;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st224;
	goto st0;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	switch( (*p) ) {
		case 32: goto st224;
		case 101: goto st225;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st224;
	goto st0;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	if ( (*p) == 110 )
		goto st226;
	goto st0;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
	if ( (*p) == 116 )
		goto st227;
	goto st0;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	if ( (*p) == 114 )
		goto st228;
	goto st0;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	if ( (*p) == 121 )
		goto st229;
	goto st0;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	if ( (*p) == 32 )
		goto st230;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st230;
	goto st0;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	if ( (*p) == 32 )
		goto st230;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st230;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto tr244;
		} else if ( (*p) >= 65 )
			goto tr244;
	} else
		goto tr244;
	goto st0;
tr244:
#line 51 "croissant/test.c.rl"
	{ start = p; }
	goto st231;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
#line 2845 "croissant/test.c"
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
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st253;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st253;
	} else
		goto st253;
	goto st0;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st254;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st254;
	} else
		goto st254;
	goto st0;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st255;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st255;
	} else
		goto st255;
	goto st0;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st256;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st256;
	} else
		goto st256;
	goto st0;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st257;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st257;
	} else
		goto st257;
	goto st0;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st258;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st258;
	} else
		goto st258;
	goto st0;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st259;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st259;
	} else
		goto st259;
	goto st0;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st260;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st260;
	} else
		goto st260;
	goto st0;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st261;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st261;
	} else
		goto st261;
	goto st0;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st262;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st262;
	} else
		goto st262;
	goto st0;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	switch( (*p) ) {
		case 32: goto tr276;
		case 59: goto tr277;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr276;
	goto st0;
tr276:
#line 51 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 53 "croissant/test.c.rl"
	{ rii_check(crs_id_init(&id1, buf.buf)); }
#line 63 "croissant/test.c.rl"
	{
                struct crs_leaf_set  *from_set;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                rip_check(to_node = crs_ctx_require_node(ctx, &id1));
                from_set = crs_node_get_leaf_set(node);
                to_ref = crs_node_get_ref(to_node);
                crs_leaf_set_add(from_set, to_ref);
            }
	goto st263;
tr330:
#line 51 "croissant/test.c.rl"
	{ cork_buffer_set(&buf, start, p - start); }
#line 53 "croissant/test.c.rl"
	{ rii_check(crs_id_init(&id1, buf.buf)); }
#line 76 "croissant/test.c.rl"
	{
                struct crs_routing_table  *from_table;
                struct crs_node  *to_node;
                struct crs_node_ref  *to_ref;
                rip_check(to_node = crs_ctx_require_node(ctx, &id1));
                from_table = crs_node_get_routing_table(node);
                to_ref = crs_node_get_ref(to_node);
                crs_routing_table_set(from_table, to_ref);
            }
	goto st263;
tr346:
#line 88 "croissant/test.c.rl"
	{
                struct crs_leaf_set  *set;
                set = crs_node_get_leaf_set(node);
                cork_buffer_printf
                    (&output, "Leaf set for %s\n", crs_node_get_id_str(node));
                crs_leaf_set_print(&output, set);
                fwrite(output.buf, output.size, 1, stdout);
            }
	goto st263;
tr360:
#line 99 "croissant/test.c.rl"
	{
                struct crs_routing_table  *table;
                table = crs_node_get_routing_table(node);
                cork_buffer_printf
                    (&output, "Routing table for %s\n",
                     crs_node_get_id_str(node));
                crs_routing_table_print(&output, table);
                fwrite(output.buf, output.size, 1, stdout);
            }
	goto st263;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
#line 3315 "croissant/test.c"
	switch( (*p) ) {
		case 32: goto st263;
		case 59: goto st211;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st263;
	goto st0;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	if ( (*p) == 111 )
		goto st265;
	goto st0;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	if ( (*p) == 117 )
		goto st266;
	goto st0;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
	if ( (*p) == 116 )
		goto st267;
	goto st0;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	if ( (*p) == 105 )
		goto st268;
	goto st0;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	if ( (*p) == 110 )
		goto st269;
	goto st0;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	if ( (*p) == 103 )
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
		case 116: goto st272;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st271;
	goto st0;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
	if ( (*p) == 97 )
		goto st273;
	goto st0;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
	if ( (*p) == 98 )
		goto st274;
	goto st0;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
	if ( (*p) == 108 )
		goto st275;
	goto st0;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
	if ( (*p) == 101 )
		goto st276;
	goto st0;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	if ( (*p) == 32 )
		goto st277;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st277;
	goto st0;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	switch( (*p) ) {
		case 32: goto st277;
		case 101: goto st278;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st277;
	goto st0;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
	if ( (*p) == 110 )
		goto st279;
	goto st0;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
	if ( (*p) == 116 )
		goto st280;
	goto st0;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
	if ( (*p) == 114 )
		goto st281;
	goto st0;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
	if ( (*p) == 121 )
		goto st282;
	goto st0;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
	if ( (*p) == 32 )
		goto st283;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st283;
	goto st0;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	if ( (*p) == 32 )
		goto st283;
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st283;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto tr298;
		} else if ( (*p) >= 65 )
			goto tr298;
	} else
		goto tr298;
	goto st0;
tr298:
#line 51 "croissant/test.c.rl"
	{ start = p; }
	goto st284;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
#line 3496 "croissant/test.c"
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
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st312;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st312;
	} else
		goto st312;
	goto st0;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st313;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st313;
	} else
		goto st313;
	goto st0;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st314;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st314;
	} else
		goto st314;
	goto st0;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st315;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st315;
	} else
		goto st315;
	goto st0;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
	switch( (*p) ) {
		case 32: goto tr330;
		case 59: goto tr331;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr330;
	goto st0;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
	if ( (*p) == 114 )
		goto st317;
	goto st0;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	if ( (*p) == 105 )
		goto st318;
	goto st0;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	if ( (*p) == 110 )
		goto st319;
	goto st0;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	if ( (*p) == 116 )
		goto st320;
	goto st0;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
	if ( (*p) == 32 )
		goto st321;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st321;
	goto st0;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
	switch( (*p) ) {
		case 32: goto st321;
		case 108: goto st322;
		case 114: goto st330;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st321;
	goto st0;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
	if ( (*p) == 101 )
		goto st323;
	goto st0;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
	if ( (*p) == 97 )
		goto st324;
	goto st0;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	if ( (*p) == 102 )
		goto st325;
	goto st0;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	if ( (*p) == 32 )
		goto st326;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st326;
	goto st0;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	switch( (*p) ) {
		case 32: goto st326;
		case 115: goto st327;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st326;
	goto st0;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	if ( (*p) == 101 )
		goto st328;
	goto st0;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	if ( (*p) == 116 )
		goto st329;
	goto st0;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	switch( (*p) ) {
		case 32: goto tr346;
		case 59: goto tr347;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr346;
	goto st0;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	if ( (*p) == 111 )
		goto st331;
	goto st0;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
	if ( (*p) == 117 )
		goto st332;
	goto st0;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
	if ( (*p) == 116 )
		goto st333;
	goto st0;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
	if ( (*p) == 105 )
		goto st334;
	goto st0;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
	if ( (*p) == 110 )
		goto st335;
	goto st0;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	if ( (*p) == 103 )
		goto st336;
	goto st0;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	if ( (*p) == 32 )
		goto st337;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st337;
	goto st0;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	switch( (*p) ) {
		case 32: goto st337;
		case 116: goto st338;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st337;
	goto st0;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	if ( (*p) == 97 )
		goto st339;
	goto st0;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	if ( (*p) == 98 )
		goto st340;
	goto st0;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	if ( (*p) == 108 )
		goto st341;
	goto st0;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	if ( (*p) == 101 )
		goto st342;
	goto st0;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
	switch( (*p) ) {
		case 32: goto tr360;
		case 59: goto tr361;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr360;
	goto st0;
	}
	_test_eof343: cs = 343; goto _test_eof; 
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

	_test_eof: {}
	_out: {}
	}

#line 133 "croissant/test.c.rl"


    /* A hack to suppress some unused variable warnings */
    (void) crs_command_en_main;

    if (CORK_UNLIKELY(cs < 
#line 4479 "croissant/test.c"
343
#line 138 "croissant/test.c.rl"
)) {
        crs_parse_error("Invalid command");
        cork_buffer_done(&buf);
        cork_buffer_done(&output);
        return -1;
    }

    cork_buffer_done(&buf);
    cork_buffer_done(&output);
    return 0;
}

static void
execute(int argc, char **argv)
{
    struct crs_ctx  *ctx = crs_ctx_new();
    struct cork_buffer  buf = CORK_BUFFER_INIT();
    struct cork_stream_consumer  *consumer;

    clog_set_default_format("%m");
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
