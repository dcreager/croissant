Some tests of manually updating the contents of a node's leaf set.

  $ CLOG=DEBUG croissant test <<EOF
  > new node 000000000000000000000000000000ff;
  > new node 00000000000000000000000000000100;
  > new node 00000000000000000000000000000101;
  > node 00000000000000000000000000000100 {
  >     add leaf set entry 000000000000000000000000000000ff;
  >     add leaf set entry 00000000000000000000000000000101;
  >     print leaf set;
  > };
  > EOF
  [local:1] New node 000000000000000000000000000000ff
  [local:1] New routing table
  [local:1] New leaf set
  [local:2] New node 00000000000000000000000000000100
  [local:2] New routing table
  [local:2] New leaf set
  [local:3] New node 00000000000000000000000000000101
  [local:3] New routing table
  [local:3] New leaf set
  [local:2] (leafset) [+ 1] Add 000000000000000000000000000000ff
  [local:2] (leafset) [- 1] Add 000000000000000000000000000000ff
  [local:2] (leafset) [+ 1] Found spot for 00000000000000000000000000000101
  [local:2] (leafset) [+ 2] Bubble up 000000000000000000000000000000ff
  [local:2] (leafset) [+ 1] Add 00000000000000000000000000000101
  [local:2] (leafset) [- 2] Add 00000000000000000000000000000101
  [local:3] Free node
  [local:2] Free node
  [local:1] Free node
  Leaf set for 00000000000000000000000000000100
  [- 2] 00000000000000000000000000000101 local:3
  [- 1] 000000000000000000000000000000ff local:1
  [  0] 00000000000000000000000000000100 local:2
  [+ 1] 00000000000000000000000000000101 local:3
  [+ 2] 000000000000000000000000000000ff local:1