# Vertex Cover

[spoj](http://www.spoj.com/problems/PT07X/)

### Description
Since the tree is undirected, we keep the edges between parent and children and vice versa. Then we find the root of the tree and we start visiting it with a post order visit. For each node, we follow the following rules: let `n` be the node we are considering:

* If `n` is a leaf, then we consider it as covered;
* If `n` is not a leaf, and at least one node at distance one is covered, then `n` is not covered;
* Otherwise, `n` is covered.

In this way the nodes covered by the algorithm are the ones that form a vertex set of maximum size in which every node has at least one of its end-points in that set. Since we are intersted in the minimum vertex set, we just count the nodes which are not covered by the algorithm.

### Complexity
The algorithm is a post order visit of a tree, and for each node we look at its children and parent to see if at least a node is coverd. How much does it cost? Let `u` be the node currently considered by the visit, and `v` be one of its children. The node `u` has been visited once as the parent of the node `v`, is visited now since it's the current node, and will be visited again one more time when the visit will consider its parent.

So we visit every node once to find the root, three times to find the vertex set, and another time to count the number of non covered nodes, this means that the total time complexity of the algorithm for a tree of `n` nodes is `O(n)`.
