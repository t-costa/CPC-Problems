# Longest Palindromic Subsequece

[geeksforgeeks](https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence/0)

### Description
To find the longest palindromic subsequence, we use dynamic programming with the following rules:

* the lps of s[i, i] is 1;
* the lps of s[i, j] with j<i is 0;
* the lps of s[i, j] with i<j is:
  * the maximum between the lps of s[i+1, j] and the lps of s[i, j-1], &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if s[i] != s[j];
  * the lps of s[i+1, j-1] + 2, &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if s[i] == s[j];

The first two rules are base cases: if the sequence is just one character, the lps is 1, the character itself; if the sequence is empty (j<i) the lps is 0.  
Otherwise, if the two character at the extremes are different, we are not extending the lps, so we keep the maximum already computed; if instead the two characters are equal, we are extending the lps of s[i+1,j-1] of 2.

This corresponds to filling a matrix, with all ones in the diagonal, from the top left corner to the bottom right corner.

```
1 🡖 🡖 🡖 🡖 🡖 🡖 🡖 
0 1 🡖 🡖 🡖 🡖 🡖 🡖 
  0 1 🡖 🡖 🡖 🡖 🡖 
    0 1 🡖 🡖 🡖 🡖 
      0 1 🡖 🡖 🡖 
        0 1 🡖 🡖 
          0 1 🡖 
            0 1
```

The solution to the problem will be in the top left corner, which is the last computed cell.

### Complexity
The time and space complexity of the algorithm is `O(n^2)`.
