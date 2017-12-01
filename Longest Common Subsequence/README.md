# Longest Common Subsequence

### Description
To find the LCS of two strings, we build a matrix where in position `(i, j)` is stored the solution to the LCS problem for the first `i` characters of the first string and the first `j` characters of the second string. In this way, in position `(n, m)` we find the solution to our problem. 
How do we fill the matrix? We use the following rules:

- LCS(i, 0) = LCS(0, j) = 0
- LCS(i, j) = 
  - LCS(i-1, j-1) + 1               &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if s1[i] = s2[j]
  - max (LCS(i-1, j), LCS(i, j-1))  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;otherwise
  
The first two rules are the base cases: if one of the two strings are empty, it's clear that the LCS is 0. Otherwise, in the general case, if the two considered characters are equal, the LCS of the two strings without the last character is incremented by one, otherwise, since the characters are different, the LCS is the maximum between the LCS of the two strings without the last character of the first string and the LCS of the two strings without the last character of the second string. This is true because we want the longest possible sequence already formed, since the last character does not increment the length of the LCS.

### Complexity
Since we have to build the matrix, the time and space complexity of the algorithm is `O(n*m)`.
