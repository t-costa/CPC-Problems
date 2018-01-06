# Shift the String

[codechef](https://www.codechef.com/problems/TASHIFT)

### Descprition
The algotithm is a slightly modified version of the Knuth-Morris-Pratt algorithm: we search for a pattern inside a string but instead of finding the starting positions of that pattern we don't search all the pattern in the text, but just the longest prefix, and we store the initial position of that prefix (the number of shifts needed).

So, given the strings `a` and `b`, to count the right number of shifts we append `b` to `b` itself. In this way, `b` becomes `bb`, the text in wich we search for the pattern `a`, with all the possible shifts already computed (since the shifted characted goes to the end of the string).  
Then we just need to search for the longest occurence of a prefix of `a` inside `bb`, storing the position of the starting character of `bb`, since it will be the first one after the shifts, so it corresponds to the number of shifts we have to do. 

### Complexity
Since the algorithm is basically the Knuth-Morris-Pratt algorithm, the time complexity is `O(n)`, because the text size is 2 times the pattern, which is of size `n`. 

Also the space complexity is `O(n)`, to store the support vector `pi`.
