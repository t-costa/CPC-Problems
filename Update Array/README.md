# Update Array

[spoj](http://www.spoj.com/problems/UPDATEIT/)

## Solution with BIT

### Description
In this problem, we use a Fenwick tree to do the update operations. In this way, to update the elements between `l` and `r` with value `val`, we increment the elements from position `l` (following the rule of the BIT vector) with `val`, and the elements from position `r+1` with `-val`. In this way, a simple `sum` operation can retrieve the value of the selected position.

### Complexity
The operations `update` and `print_value` are simple implementations of the operations `add` and `sum` respectively, so their computational cost is `O(log(n))`. Let `u` be the number of update operations in input, and `q` the number of queries, the total time complexity is `O((u+q)log(n))`.
The space complexity instead is `O(n)`, since we keep just the Fenwick tree keeping the values updated.


## Solution with Segment Tree

### Description
We use a complete on the left binary tree, were the leaves are the original values of the array and every internal node is the sum of its subtree. 

To perform the update operations, we navigate the tree from the root and add the value to the nodes which represent the desired interval.

To perform the query operations, we navigate the tree from the root and we visit all the path from the root to the desired node. The total sum of the visited nodes will be the answer to the query.

### Complexity
The contruction of the segment tree takes linear time, while each operation on the tree takes `O(log(n))` time, so the total time complexity is `O((u+q)log(n))`, as with the BIT, and also the space complexity is unchanged, `O(n)`.
