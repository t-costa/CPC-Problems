# Update Array

### Description
In this problem, we use a Fenwick tree to do the update operations. In this way, to update the elements between `l` and `r` with value `val`, we increment the elements from position `l` (following the rule of the BIT vector) with `val`, and the elements from position `r+1` with `-val`. In this way, a simple `sum` operation can retrieve the value of the selected position.

### Complexity
The operations `update` and `print_value` are simple implementations of the operations `add` and `sum` respectively, so their computational cost is `O(log(n))`. Let `u` be the number of update operations in input, and `q` the number of queries, the total time complexity is `O((u+q)log(n))`.
The space complexity instead is `O(n)`, since we keep just the Fenwick tree keeping the values updated.
