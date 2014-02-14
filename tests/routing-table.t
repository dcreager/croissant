Some tests of manually updating the contents of a node's routing table.

  $ CLOG=DEBUG croissant test <<EOF
  > new node 0123456789abcdef0123456789abcdef;
  > new node 00000000000000000000000000000000;
  > node 0123456789abcdef0123456789abcdef {
  >     add routing table entry 00000000000000000000000000000000;
  >     print routing table;
  > };
  > EOF
  --- new node 0123456789abcdef0123456789abcdef
  [local:1] New node 0123456789abcdef0123456789abcdef
  [local:1] New routing table
  [local:1] New leaf set
  --- new node 00000000000000000000000000000000
  [local:2] New node 00000000000000000000000000000000
  [local:2] New routing table
  [local:2] New leaf set
  --- [0123456789abcdef0123456789abcdef]
  --- add routing table entry 00000000000000000000000000000000
  [local:1] (rtable) [ 1/0] 00000000000000000000000000000000 (new entry)
  --- [0123456789abcdef0123456789abcdef]
  --- print routing table
  Routing table for 0123456789abcdef0123456789abcdef
  [ 1/0] 00000000000000000000000000000000 local:2
  ---
  [local:2] Free node
  [local:1] Free node

  $ CLOG=DEBUG croissant test <<EOF
  > new node 0123456789abcdef0123456789abcdef;
  > new node 00000000000000000000000000000000;
  > new node 01000000000000000000000000000000;
  > node 0123456789abcdef0123456789abcdef {
  >     add routing table entry 00000000000000000000000000000000;
  >     add routing table entry 01000000000000000000000000000000;
  >     print routing table;
  > };
  > EOF
  --- new node 0123456789abcdef0123456789abcdef
  [local:1] New node 0123456789abcdef0123456789abcdef
  [local:1] New routing table
  [local:1] New leaf set
  --- new node 00000000000000000000000000000000
  [local:2] New node 00000000000000000000000000000000
  [local:2] New routing table
  [local:2] New leaf set
  --- new node 01000000000000000000000000000000
  [local:3] New node 01000000000000000000000000000000
  [local:3] New routing table
  [local:3] New leaf set
  --- [0123456789abcdef0123456789abcdef]
  --- add routing table entry 00000000000000000000000000000000
  [local:1] (rtable) [ 1/0] 00000000000000000000000000000000 (new entry)
  --- [0123456789abcdef0123456789abcdef]
  --- add routing table entry 01000000000000000000000000000000
  [local:1] (rtable) [ 2/0] 01000000000000000000000000000000 (new entry)
  --- [0123456789abcdef0123456789abcdef]
  --- print routing table
  Routing table for 0123456789abcdef0123456789abcdef
  [ 1/0] 00000000000000000000000000000000 local:2
  [ 2/0] 01000000000000000000000000000000 local:3
  ---
  [local:3] Free node
  [local:2] Free node
  [local:1] Free node

  $ CLOG=DEBUG croissant test <<EOF
  > new node 0123456789abcdef0123456789abcdef;
  > new node 00000000000000000000000000000000;
  > new node 00200000000000000000000000000000;
  > node 0123456789abcdef0123456789abcdef {
  >     add routing table entry 00000000000000000000000000000000;
  >     add routing table entry 00200000000000000000000000000000;
  >     print routing table;
  > };
  > EOF
  --- new node 0123456789abcdef0123456789abcdef
  [local:1] New node 0123456789abcdef0123456789abcdef
  [local:1] New routing table
  [local:1] New leaf set
  --- new node 00000000000000000000000000000000
  [local:2] New node 00000000000000000000000000000000
  [local:2] New routing table
  [local:2] New leaf set
  --- new node 00200000000000000000000000000000
  [local:3] New node 00200000000000000000000000000000
  [local:3] New routing table
  [local:3] New leaf set
  --- [0123456789abcdef0123456789abcdef]
  --- add routing table entry 00000000000000000000000000000000
  [local:1] (rtable) [ 1/0] 00000000000000000000000000000000 (new entry)
  --- [0123456789abcdef0123456789abcdef]
  --- add routing table entry 00200000000000000000000000000000
  [local:1] (rtable) [ 1/0] 00000000000000000000000000000000 (closer than 00200000000000000000000000000000)
  --- [0123456789abcdef0123456789abcdef]
  --- print routing table
  Routing table for 0123456789abcdef0123456789abcdef
  [ 1/0] 00000000000000000000000000000000 local:2
  ---
  [local:3] Free node
  [local:2] Free node
  [local:1] Free node
