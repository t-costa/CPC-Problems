# Edit Distance

### Description
The algorithm follows the following rule to dermine the edit distance for two strings `s1` and `s2` knowing the edit distance of the first `n-1` characters of `s1` with respect to `s2`. The rule is the following:

* ED(0, j) = j
* ED(i, 0) = i
* ED(i, j) = min (ED(i-1,j-1), ED(i-1, j), ED(i, j-1))

What do these rules mean? The first two rules are base cases: if one of the two strings is empty, the edit distance is the lenght of the non empty string; otherwise, the edit distance for two strings of length `i` and `j` can be computed knowing the edit distance of the same two strings without the last character. There are three cases that corresponds to the three edit operations, respectively: substitution of the last character of `s1` and of `s2`, deletion of the last character in `s1`, insertion of a new character in `s2`. Among all the possible values, we take the minimum, since the edit distance is defined as the minimum number of operations to transform a string to another.

So the algorithm builds a matrix that in position `(i, j)` keeps the result of the edit distance for the first `i` and `j` characters of the strings in input. The solution will be in the last cell of the matrix, in position `(n, m)`.

### Complexity
The time and space complexity of the algorithm is `O(n*m)`, with `n` and `m` length of the strings in input.
