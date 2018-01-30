# Longest Prefix Suffix

[geeksforgeeks](https://practice.geeksforgeeks.org/problems/longest-prefix-suffix/0)

### Description
The solution is just the implementation of the Knuth-Morris-Pratt algorithm to build the support vector `failure function`, modified to return just the last computed value and not the entire vector.

### Complexity
Since it's just the KMP algorithm, the time and space complexity is `O(n)` for a string in input of sze `n`.
