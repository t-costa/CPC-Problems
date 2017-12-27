# Misha and Forest

[codeforces](http://codeforces.com/problemset/problem/501/C?locale=en)

### Description
To build the original graph, we notice that if the degree of the node `i` is 1, with sum `j`, then we immediatly know that the node `i` has just one edge to the node `j`, so we can store that edge and decrement the degree and the sum of the node `j`.

So we put all the leafs in a queue and we start building the graph from the leafs. In this way, since every leaf decrement the degree of another node, we can discover new leafs and put the new leafs in the queue.

We are assured to terminate with the correct graph since we know that there are no loops and no parallel edges, so we have always at least a leaf.

### Complexity
The algorithm first finds all the leafs, in linear time in the number of the nodes, then it visit each leaf and "removes" it from the graph, decrementing the degree of another node and possibly creating a new leaf. So since we have `n` nodes, and every node is inserted in the queue and removed from the queue just once, the total time complexity of the algorithm is `O(n)`.

The space complexity is `O(n)`, since we have to keep all the created edges and a copy of the nodes in the queue.
