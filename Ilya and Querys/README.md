# Ilya and Queries

### Description
Once the input string is received, the algorithm builds a prefix sum array on that string, counting the number of equal contiguous characters. Once the prefix vector is built, the query can be answered immediatly: let `l` and `r` be respectively the left and right extremes of a query, the result is just the difference between the value stored in position `r-1` and the value stored in position `l-1` (because the range goes from 1 to n, and not from 0 to n-1).

### Complexity
The time complexity to build the prefix sum vector is linear in the length of the string, while the time complexity to answer a single query is constant. So the total time complexity is `O(|s| + n)`, where `|s|` is the length of the string and`n` is the number of queries.

The space complexity is `O(|s|)`, since we keep just the prefix sum vector of the string.
