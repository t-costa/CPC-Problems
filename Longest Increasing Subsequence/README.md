# Longest Increasing Subsequence

### Description
To solve the problem, we use a vector `LIS` that stores in position `i` the length of the longest increasing subsequence until the character in position `i` in the original sequence. In this way, the first element is 1, since we have just an element.
In the general case, when we consider position `i`, we have already computed the LIS of the all the elements preceding `i`, so instead of computing from scratch the LIS of the element in position `i`, we scan the vector `LIS` and for each position `j` we check if it's LIS is greater than the current maximum (initialized to zero), and if the value of the j-th element in the original sequence is smaller then the current one. 

In this way, we find the longest increasing subsequence with the last element smaller than the current one, so we just need to add it to obtain a sequence of length `max+1`. If the current element is smaller than any other, the variable `max` remains zero, so we add a sequence with just one element (the current one).

Once we have computed all the positions of `LIS`, we scan it to find wich is the maximum and we return that value.

### Complexity
At iteration `i`, we have to do another iteration of lenght `i-1` on `LIS`, so, since `i` goes from 1 to n, we have that the total time complexity is `O(n^2)`. 

The space complexity is linear, since we keep just a vector of integer values.
