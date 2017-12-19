# Longest Bitonic Subsequence

[geeksforgeeks](https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence/0)

### Description
The algorithm computes the longest increasing subsequence for every element in the input sequence, then it computes the LIS of the reversed input sequence. In this way, we have computed the starting optimal increasing subsequence and the ending optimal decreasing subsequence; we just need to merge them searching the elements that maximize the sequence.

Actually, we just have to search for the last element of the increasing sequence, which is also the first element of the decreasing sequence (it is the merging point).

How do we find this element? For how we build the increasing and decreasing sequences, the merging point is in the same position in both the sequences, so we just need to search the position that maximizes the sum of the increasing and decreasing subsequence. The computed sum minus 1 is the value that we search; we have to decrement it since we count twice the merging point.

### Complexity
The algorithm computes twice the LIS of a sequcence of `n` elements, then reverses two sequences of `n` elements and then just performs a linear scan of the increasing and decreasing sequences, so the total time complexity is `O(n^2)`.

The space complexity instead is `O(n)`, since we have to keep all the LIS for the original and for the reversed sequence in input.
