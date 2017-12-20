# Subset Sum

[geeksforgeeks](https://practice.geeksforgeeks.org/problems/subset-sum-problem/0)

### Description
To find out if the set can be divided in two disjoint subsets of equal sum, first we compute the total sum of the set. If the sum is odd, the set can not be divided. Otherwise, we check if it is possible to find a subset which sum is exactly half the total sum.

We check if it is possible via dynamic programming: we build a matrix `m` of boolean values where the position `(i, j)` is true iff it is possible to find a subset of the first `i` elements so that their sum is exactly `j`. To fill this matrix, we use the following rules:

* if the set is empty, the answer is false;
* if the sum is 0, the answer is true;
* `m[i, j]` is true if and only if:
  * we can build a subset with the `i-1` first elements of sum `j - i-th element in the set` or
  * we can build a subset with sum `j` using the `i-1` first elements (`m[i-1, j] == true`).
  
The last rule allows to decide if we have to take the `i-th` element of the set or not.

The final answer will be in the last cell of the matrix.

### Complexity
The time and space complexity of the algorithm is `O(n*sum)`, with `n` number of elements in the set and `sum` the desired sum. Notice that it is a pseudo-polynomial time.
