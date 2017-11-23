# Bipartite Graph

### Description
To search if a graph is bipartite, we can try to do a 2-coloring of the graph: if and only if it is possible, the graph is bipartite.
To do the 2-coloring, first of all we search the first node in the adjacency matrix, than we do a DFS, keeping an unordered map to store the color (a boolean true/false) of every node. In the DFS, first of all, we assign a color to the starting node, than, as soon as we reach a not visited node, we assign to it a color different from the one of the father and continue the visit on that node (as usual in the DFS). If we reach an already visited node, with the same color of the current one, the 2-coloring is not possible. Otherwise, if we visit all the nodes successfully, the 2-coloring is possible and so the graph is bipartite.

### Complexity
The algorithm is a slightly changed DFS on an adjacency matrix, so the time complexity is the same, `O(n^2)`, with `n` nodes. The space complexity of the function is `O(n)`, since we keep the mapping between nodes and colors.
