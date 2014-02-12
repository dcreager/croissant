Some tests of creating and joining overlay networks.

  $ CLOG=DEBUG croissant test <<EOF
  > new node 0123456789abcdef0123456789abcdef;
  > new node 000000000000000000000000000000ff;
  > new node 00000000000000000000000000000100;
  > new node 00000000000000000000000000000101;
  > node 0123456789abcdef0123456789abcdef {
  >     create empty network;
  > };
  > node 000000000000000000000000000000ff {
  >     join network via 0123456789abcdef0123456789abcdef;
  > };
  > node 00000000000000000000000000000100 {
  >     join network via 0123456789abcdef0123456789abcdef;
  > };
  > node 00000000000000000000000000000101 {
  >     join network via 000000000000000000000000000000ff;
  > };
  > node 0123456789abcdef0123456789abcdef {
  >     print routing table;
  >     print leaf set;
  > };
  > node 000000000000000000000000000000ff {
  >     print routing table;
  >     print leaf set;
  > };
  > node 00000000000000000000000000000100 {
  >     print routing table;
  >     print leaf set;
  > };
  > node 00000000000000000000000000000101 {
  >     print routing table;
  >     print leaf set;
  > };
  > EOF
  --- new node 0123456789abcdef0123456789abcdef
  [local:1] New node 0123456789abcdef0123456789abcdef
  [local:1] New routing table
  [local:1] New leaf set
  --- new node 000000000000000000000000000000ff
  [local:2] New node 000000000000000000000000000000ff
  [local:2] New routing table
  [local:2] New leaf set
  --- new node 00000000000000000000000000000100
  [local:3] New node 00000000000000000000000000000100
  [local:3] New routing table
  [local:3] New leaf set
  --- new node 00000000000000000000000000000101
  [local:4] New node 00000000000000000000000000000101
  [local:4] New routing table
  [local:4] New leaf set
  --- [0123456789abcdef0123456789abcdef]
  --- create empty network
  --- [000000000000000000000000000000ff]
  --- join network via 0123456789abcdef0123456789abcdef
  Send join request to 0123456789abcdef0123456789abcdef at local:1
  {local} Send message to local:1
  [local:1] Next hop is self (leaf set)
  [local:1] Deliver message to application "crs_maintenance"
  [local:1] {maint} Received join request from 000000000000000000000000000000ff at local:2
  [local:1] Route initial message to new node 000000000000000000000000000000ff at local:2
  [local:1] Send message to 000000000000000000000000000000ff
  [local:1] Next hop is self (last resort)
  [local:1] Deliver message to application "crs_maintenance"
  [local:1] {maint} Received join reply from 0123456789abcdef0123456789abcdef for 000000000000000000000000000000ff at local:2
  [local:1] Send 2 rows of routing table to 000000000000000000000000000000ff at local:2
  [local:1] {local} Send message to local:2
  [local:2] Next hop is self (leaf set)
  [local:2] Deliver message to application "crs_maintenance"
  [local:2] {maint} Received partial routing table from 0123456789abcdef0123456789abcdef at local:1
  [local:2] (rtable) [ 1/1] 0123456789abcdef0123456789abcdef (new entry)
  [local:2] (rtable) Decode 0 routing table entries from message
  [local:2] Send initial leaf set to new node 000000000000000000000000000000ff at local:2
  [local:2] {local} Send message to local:2
  [local:2] Next hop is self (leaf set)
  [local:2] Deliver message to application "crs_maintenance"
  [local:2] {maint} Received initial leaf set from 0123456789abcdef0123456789abcdef at local:1
  [local:2] (leafset) [+ 1] Add 0123456789abcdef0123456789abcdef
  [local:2] (leafset) Decode 0 leaf set entries from message
  [local:2] Announce presence to 0123456789abcdef0123456789abcdef at local:1
  [local:2] {local} Send message to local:1
  [local:1] Next hop is self (leaf set)
  [local:1] Deliver message to application "crs_maintenance"
  [local:1] {maint} Received presence announcement from 000000000000000000000000000000ff at local:2
  [local:1] (leafset) [- 1] Add 000000000000000000000000000000ff
  [local:1] (rtable) [ 1/0] 000000000000000000000000000000ff (new entry)
  --- [00000000000000000000000000000100]
  --- join network via 0123456789abcdef0123456789abcdef
  [local:1] Send join request to 0123456789abcdef0123456789abcdef at local:1
  [local:1] {local} Send message to local:1
  [local:1] Next hop is self (leaf set)
  [local:1] Deliver message to application "crs_maintenance"
  [local:1] {maint} Received join request from 00000000000000000000000000000100 at local:3
  [local:1] Route initial message to new node 00000000000000000000000000000100 at local:3
  [local:1] Send message to 00000000000000000000000000000100
  [local:1] Next hop is 000000000000000000000000000000ff (leaf set)
  [local:1] {maint} Intercept join reply from 0123456789abcdef0123456789abcdef for 00000000000000000000000000000100 at local:3
  [local:1] Send 2 rows of routing table to 00000000000000000000000000000100 at local:3
  [local:1] {local} Send message to local:3
  [local:3] Next hop is self (leaf set)
  [local:3] Deliver message to application "crs_maintenance"
  [local:3] {maint} Received partial routing table from 0123456789abcdef0123456789abcdef at local:1
  [local:3] (rtable) [ 1/1] 0123456789abcdef0123456789abcdef (new entry)
  [local:3] (rtable) Decode 1 routing table entries from message
  [local:3] (rtable) [29/0] 000000000000000000000000000000ff (new entry)
  [local:3] Forward via local:2
  [local:3] {local} Send message to local:2
  [local:2] Next hop is self (leaf set)
  [local:2] Deliver message to application "crs_maintenance"
  [local:2] {maint} Received join reply from 0123456789abcdef0123456789abcdef for 00000000000000000000000000000100 at local:3
  [local:2] Send 30 rows of routing table to 00000000000000000000000000000100 at local:3
  [local:2] {local} Send message to local:3
  [local:3] Next hop is self (leaf set)
  [local:3] Deliver message to application "crs_maintenance"
  [local:3] {maint} Received partial routing table from 000000000000000000000000000000ff at local:2
  [local:3] (rtable) [29/0] 000000000000000000000000000000ff (duplicate)
  [local:3] (rtable) Decode 1 routing table entries from message
  [local:3] (rtable) [ 1/1] 0123456789abcdef0123456789abcdef (duplicate)
  [local:3] Send initial leaf set to new node 00000000000000000000000000000100 at local:3
  [local:3] {local} Send message to local:3
  [local:3] Next hop is self (leaf set)
  [local:3] Deliver message to application "crs_maintenance"
  [local:3] {maint} Received initial leaf set from 000000000000000000000000000000ff at local:2
  [local:3] (leafset) [- 1] Add 000000000000000000000000000000ff
  [local:3] (leafset) Decode 1 leaf set entries from message
  [local:3] (leafset) [+ 1] Add 0123456789abcdef0123456789abcdef
  [local:3] Announce presence to 000000000000000000000000000000ff at local:2
  [local:3] {local} Send message to local:2
  [local:2] Next hop is self (leaf set)
  [local:2] Deliver message to application "crs_maintenance"
  [local:2] {maint} Received presence announcement from 00000000000000000000000000000100 at local:3
  [local:2] (leafset) [+ 1] Found spot for 00000000000000000000000000000100
  [local:2] (leafset) [+ 2] Bubble up 0123456789abcdef0123456789abcdef
  [local:2] (leafset) [+ 1] Add 00000000000000000000000000000100
  [local:2] (rtable) [29/1] 00000000000000000000000000000100 (new entry)
  [local:2] Announce presence to 0123456789abcdef0123456789abcdef at local:1
  [local:2] {local} Send message to local:1
  [local:1] Next hop is self (leaf set)
  [local:1] Deliver message to application "crs_maintenance"
  [local:1] {maint} Received presence announcement from 00000000000000000000000000000100 at local:3
  [local:1] (leafset) [- 1] Found spot for 00000000000000000000000000000100
  [local:1] (leafset) [- 2] Bubble down 000000000000000000000000000000ff
  [local:1] (leafset) [- 1] Add 00000000000000000000000000000100
  [local:1] (rtable) [ 1/0] 000000000000000000000000000000ff (closer than 00000000000000000000000000000100)
  --- [00000000000000000000000000000101]
  --- join network via 000000000000000000000000000000ff
  [local:1] Send join request to 000000000000000000000000000000ff at local:2
  [local:1] {local} Send message to local:2
  [local:2] Next hop is self (leaf set)
  [local:2] Deliver message to application "crs_maintenance"
  [local:2] {maint} Received join request from 00000000000000000000000000000101 at local:4
  [local:2] Route initial message to new node 00000000000000000000000000000101 at local:4
  [local:2] Send message to 00000000000000000000000000000101
  [local:2] Next hop is 00000000000000000000000000000100 (leaf set)
  [local:2] {maint} Intercept join reply from 000000000000000000000000000000ff for 00000000000000000000000000000101 at local:4
  [local:2] Send 30 rows of routing table to 00000000000000000000000000000101 at local:4
  [local:2] {local} Send message to local:4
  [local:4] Next hop is self (leaf set)
  [local:4] Deliver message to application "crs_maintenance"
  [local:4] {maint} Received partial routing table from 000000000000000000000000000000ff at local:2
  [local:4] (rtable) [29/0] 000000000000000000000000000000ff (new entry)
  [local:4] (rtable) Decode 2 routing table entries from message
  [local:4] (rtable) [ 1/1] 0123456789abcdef0123456789abcdef (new entry)
  [local:4] (rtable) [31/0] 00000000000000000000000000000100 (new entry)
  [local:4] Forward via local:3
  [local:4] {local} Send message to local:3
  [local:3] Next hop is self (leaf set)
  [local:3] Deliver message to application "crs_maintenance"
  [local:3] {maint} Received join reply from 000000000000000000000000000000ff for 00000000000000000000000000000101 at local:4
  [local:3] Send 32 rows of routing table to 00000000000000000000000000000101 at local:4
  [local:3] {local} Send message to local:4
  [local:4] Next hop is self (leaf set)
  [local:4] Deliver message to application "crs_maintenance"
  [local:4] {maint} Received partial routing table from 00000000000000000000000000000100 at local:3
  [local:4] (rtable) [31/0] 00000000000000000000000000000100 (duplicate)
  [local:4] (rtable) Decode 2 routing table entries from message
  [local:4] (rtable) [ 1/1] 0123456789abcdef0123456789abcdef (duplicate)
  [local:4] (rtable) [29/0] 000000000000000000000000000000ff (duplicate)
  [local:4] Send initial leaf set to new node 00000000000000000000000000000101 at local:4
  [local:4] {local} Send message to local:4
  [local:4] Next hop is self (leaf set)
  [local:4] Deliver message to application "crs_maintenance"
  [local:4] {maint} Received initial leaf set from 00000000000000000000000000000100 at local:3
  [local:4] (leafset) [- 1] Add 00000000000000000000000000000100
  [local:4] (leafset) Decode 2 leaf set entries from message
  [local:4] (leafset) [- 2] Add 000000000000000000000000000000ff
  [local:4] (leafset) [+ 1] Add 0123456789abcdef0123456789abcdef
  [local:4] Announce presence to 000000000000000000000000000000ff at local:2
  [local:4] {local} Send message to local:2
  [local:2] Next hop is self (leaf set)
  [local:2] Deliver message to application "crs_maintenance"
  [local:2] {maint} Received presence announcement from 00000000000000000000000000000101 at local:4
  [local:2] (leafset) [+ 2] Found spot for 00000000000000000000000000000101
  [local:2] (leafset) [+ 3] Bubble up 0123456789abcdef0123456789abcdef
  [local:2] (leafset) [+ 2] Add 00000000000000000000000000000101
  [local:2] (rtable) [29/1] 00000000000000000000000000000100 (closer than 00000000000000000000000000000101)
  [local:2] Announce presence to 00000000000000000000000000000100 at local:3
  [local:2] {local} Send message to local:3
  [local:3] Next hop is self (leaf set)
  [local:3] Deliver message to application "crs_maintenance"
  [local:3] {maint} Received presence announcement from 00000000000000000000000000000101 at local:4
  [local:3] (leafset) [+ 1] Found spot for 00000000000000000000000000000101
  [local:3] (leafset) [+ 2] Bubble up 0123456789abcdef0123456789abcdef
  [local:3] (leafset) [+ 1] Add 00000000000000000000000000000101
  [local:3] (rtable) [31/1] 00000000000000000000000000000101 (new entry)
  [local:3] Announce presence to 0123456789abcdef0123456789abcdef at local:1
  [local:3] {local} Send message to local:1
  [local:1] Next hop is self (leaf set)
  [local:1] Deliver message to application "crs_maintenance"
  [local:1] {maint} Received presence announcement from 00000000000000000000000000000101 at local:4
  [local:1] (leafset) [- 1] Found spot for 00000000000000000000000000000101
  [local:1] (leafset) [- 3] Bubble down 000000000000000000000000000000ff
  [local:1] (leafset) [- 2] Bubble down 00000000000000000000000000000100
  [local:1] (leafset) [- 1] Add 00000000000000000000000000000101
  [local:1] (rtable) [ 1/0] 000000000000000000000000000000ff (closer than 00000000000000000000000000000101)
  --- [0123456789abcdef0123456789abcdef]
  --- print routing table
  Routing table for 0123456789abcdef0123456789abcdef
  [ 1/0] 000000000000000000000000000000ff local:2
  --- [0123456789abcdef0123456789abcdef]
  --- print leaf set
  Leaf set for 0123456789abcdef0123456789abcdef
  [min] 000000000000000000000000000000ff
  [- 3] 000000000000000000000000000000ff local:2
  [- 2] 00000000000000000000000000000100 local:3
  [- 1] 00000000000000000000000000000101 local:4
  [  0] 0123456789abcdef0123456789abcdef local:1
  [max] 0123456789abcdef0123456789abcdef
  --- [000000000000000000000000000000ff]
  --- print routing table
  Routing table for 000000000000000000000000000000ff
  [ 1/1] 0123456789abcdef0123456789abcdef local:1
  [29/1] 00000000000000000000000000000100 local:3
  --- [000000000000000000000000000000ff]
  --- print leaf set
  Leaf set for 000000000000000000000000000000ff
  [min] 000000000000000000000000000000ff
  [  0] 000000000000000000000000000000ff local:2
  [+ 1] 00000000000000000000000000000100 local:3
  [+ 2] 00000000000000000000000000000101 local:4
  [+ 3] 0123456789abcdef0123456789abcdef local:1
  [max] 0123456789abcdef0123456789abcdef
  --- [00000000000000000000000000000100]
  --- print routing table
  Routing table for 00000000000000000000000000000100
  [ 1/1] 0123456789abcdef0123456789abcdef local:1
  [29/0] 000000000000000000000000000000ff local:2
  [31/1] 00000000000000000000000000000101 local:4
  --- [00000000000000000000000000000100]
  --- print leaf set
  Leaf set for 00000000000000000000000000000100
  [min] 000000000000000000000000000000ff
  [- 1] 000000000000000000000000000000ff local:2
  [  0] 00000000000000000000000000000100 local:3
  [+ 1] 00000000000000000000000000000101 local:4
  [+ 2] 0123456789abcdef0123456789abcdef local:1
  [max] 0123456789abcdef0123456789abcdef
  --- [00000000000000000000000000000101]
  --- print routing table
  Routing table for 00000000000000000000000000000101
  [ 1/1] 0123456789abcdef0123456789abcdef local:1
  [29/0] 000000000000000000000000000000ff local:2
  [31/0] 00000000000000000000000000000100 local:3
  --- [00000000000000000000000000000101]
  --- print leaf set
  Leaf set for 00000000000000000000000000000101
  [min] 000000000000000000000000000000ff
  [- 2] 000000000000000000000000000000ff local:2
  [- 1] 00000000000000000000000000000100 local:3
  [  0] 00000000000000000000000000000101 local:4
  [+ 1] 0123456789abcdef0123456789abcdef local:1
  [max] 0123456789abcdef0123456789abcdef
  ---
  [local:4] Free node 00000000000000000000000000000101
  [local:3] Free node 00000000000000000000000000000100
  [local:2] Free node 000000000000000000000000000000ff
  [local:1] Free node 0123456789abcdef0123456789abcdef
