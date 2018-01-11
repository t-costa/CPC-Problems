# Tree and Queries

[codeforces](http://codeforces.com/contest/375/problem/D)

### Description
First of all, we read the tree in input and we transform it in a sequence via a preorder visit, keeping for each node the size of its subtree and the color of the node. Then we read the queries and collect them in a vector with starting and finishing node with respect to the flat tree, keeping also the index of the original order.  
Then we sort the queries using the strategy of the Mo's Algorithm: we ideally divide the sequence in buckets of size `sqrt(n)` and we solve the queries one bucket at a time.

Since each query consists of a starting node `v` and a value `k`, and the value `k` can be different for each query, we use two maps: `map_cnt[x]` counts the number of occurrencies of the color `x`; `map_res[y]` counts the number of different colors that appear at least `y` times.

So when we have to add a node to solve the current query and the value of the node is `x`, we increment `map_cnt[x]` and `map_res[map_cnt[x]]`; instead if we want to remove a node, first we decrement `map_res[map_cnt[x]]` and then we decrement `map_cnt[x]`. The order in which we perform the updates is important.

At the end, the solution for a query with value `k` will be the value stored in `map_res[k]`.

### Complexity
Since the algorithm is a DFS visit plus the Mo's Algorithm, the total time complexity is `O((n+q)*sqrt(n))`, with `n` nodes and `q` queries.

For the space we have to keep two maps and a second version of the tree, so in total the space complexity is `O(n)`, since the size of the maps is bounded by the number of distinct colors in the tree, which is `O(n)`.
