Some simple tests where we create some Pastry nodes.  So simple that we never
tell them to join a network.

  $ CLOG=DEBUG croissant test <<EOF
  > new node 0123456789abcdef0123456789abcdef;
  > EOF
  [local:1] New node 0123456789abcdef0123456789abcdef
  [local:1] New routing table
  [local:1] Free node

  $ CLOG=DEBUG croissant test <<EOF
  > new node 0123456789abcdef0123456789abcdef;
  > new node 3456789abcdef0123456789abcdef012;
  > EOF
  [local:1] New node 0123456789abcdef0123456789abcdef
  [local:1] New routing table
  [local:2] New node 3456789abcdef0123456789abcdef012
  [local:2] New routing table
  [local:2] Free node
  [local:1] Free node

It should be fine to create more than one node with the same ID.

  $ CLOG=DEBUG croissant test <<EOF
  > new node 0123456789abcdef0123456789abcdef;
  > new node 0123456789abcdef0123456789abcdef;
  > EOF
  [local:1] New node 0123456789abcdef0123456789abcdef
  [local:1] New routing table
  [local:2] New node 0123456789abcdef0123456789abcdef
  [local:2] New routing table
  [local:2] Free node
  [local:1] Free node
