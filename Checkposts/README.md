# Checkposts 

[Codeforces](http://codeforces.com/problemset/problem/427/C?locale=en)

### Description
The algorithm collects the input and builds a graph with edges and transposed edges. To solve the problem, we notice that a checkpost it's enough to protect an entire SCC, so we just need to find all the SCC and the nodes with minimum cost inside the components.


To find the SCC, the algorithm performs a dfs and keeps a reference for every node in a stack; in this way, popping the nodes from the top of the stack, we actually pop them in reverse order with respect to the dfs. The second step of the algorithm consists in performing another dfs visit but this time on the transposed graph, so we exploit the transposed edges, and we visit the nodes in reverse finish time with respect the first dfs. This means start the visit from the node at the top of the stack. During the visit of a SCC, we keep the minimum value of a node (the cost) and the number of occurences of that value.  
In this way we can compute the total cost and the number of possibilities required by the problem.

### Complexity
The algorithm performs twice a DFS visit, so the total time complexity is `O(n + m)`, with `n` number of nodes and `m` number of edges.

The space complexity is also `O(n + m)`, since we have to keep `n` references to the nodes in the stack and the `m` transposed edges.
