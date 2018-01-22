# Minimum Spanning Tree

[sopj](http://www.spoj.com/problems/MST/)

### Description
This is the standard algorithm used to find the MST: we use the disjoint set data structure to store every vertex of the graph as individual sets; then we sort the edges of the graph in increasing order w.r.t. the weight.  
Now we take the edges from the "lightest" to the "heaviest", every time checking if adding the current edge we create a cycle in the graph. This control can easly be done with the disjoint set, since every time we take a valid edge, we merge the two vertices of the edge in the same set, so if the two vertices are already in the same set, this means that adding that edge will create a cycle, so we skip it.  
When there is just one set (or we have visited all the edges) we have the MST.

Why does this algorithm work? First, we notice that the algorithm does find a spanning tree of the graph, since for every edge we check if it generates a cycle and only if it doesn't we add it, and we stop only when all the vertices are in the same set, that means that the created tree spans every vertex of the graph.

Is the created tree one of the possible trees with minimum weight? Yes, let `OPT` be a minimum spanning tree of the graph, and let `T` the tree created by the algorithm. Let `e=(a, b)` be the first edge taken by `T` and not by `OPT` <sup id="a1">[1](#f1)</sup>. Now, in `OPT`, there must exist a path from a to b, and at least an edge `e'` in the path must be in `OPT` and not in `T` with `weight(e') > weight(e)` (`e` is the first different edge). This means that replacing that path with `e` in `OPT` we would obtain a spanning tree with a cost smaller than the one of the minimum, impossible!

So it must be that there is no different edges, so the algorithm actually finds the MST.

<b id="f1">1.</b> The vicecersa is not possible, since the only reason why the algorithm don't choose an edge is because it creates a cycle, so since it is the first different edge, that would create a cycle in `OPT`: impossible.


### Complexity
Let `n` be the number of vertices and `m` the number of edges, the time complexity of the algorithm is `O(m*log(n))`, since the sorting takes `O(m*log(m))` time and than we do `n` operations on the disjoint set, that can be executed in `O(n*alpha(n))`. Since `m <= n^2`, `O(log(m)) = O(log(n))`, and `alpha(n)` is basically constant for each practical value of n.

The space complexity of the algorithm is `O(n)`, to keep the extra informations of the disjoint set.
