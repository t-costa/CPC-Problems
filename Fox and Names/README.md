# Fox and names

### Description
First of all, the algorithm builds an empty graph of letters `new_alphabet`. After that, let `s1` be the i-th string in input and `s2` the (i+1)-th. Since we know that `s1` precedes `s2` in the new order, we search for the first different characters in `s1` and `s2`, let them be `a` and `b`, that are the two characters that determined the actual ordering, and we put an edge from `a` to `b` in `new_alphabet`, to point out that `a` precedes `b`.

Once we have processed all the strings, if there exist an ordering of the alphabet so that the order is valid, then the created graph must be a DAG, so we just do a topological sort of the graph, and if we visit all the nodes, that means that the order in which we visit them is a valid ordering of the graph.

### Complexity
For each of the n string in input, we call the `build_alphabet` method twice (except that for the first and the last). This method, scans the strings until it finds two different characters or it reaches the end of the shorter one. When we have processed all the strings, we do the topological sort, which is liner in the number of nodes of the graph (26 nodes, since they are the letters of the alphabet). So, let `m` be the maximum number of characters of the strings, the total time complexity is `O(m*n)`, in the very worst case when all the strings have length `m` and with all the characters equal. 

The space complexity is instead `O(m)` since we keep just two words at a time, and the size of the graph and of the vector of results is constant.
