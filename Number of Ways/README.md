# Number of Ways

### Description
While collecting the input, the algorithm keeps track of the total sum of the elements: if the sum is not divisible by three, the algorithm prints zero and terminates, since there are no ways to split the array.
Otherwise, we create a suffix sum array, in which, starting from the last element, we count how many ways of splitting the array in interval of a third of the total sum are there. 
Next, we do the same thing starting from left but keeping just a counter, and every time we reach a point `i` in which the sum of the elements from `0` to `i` is a third of the total sum, it means that in position `i+2` of the suffix array we find the number of ways in which we can split the array keeping fixed the position `i`, so we update the local counter. Doing so for all the elements, except the last two, we find the total number of ways to split all the elements of the array into three contiguous parts so that the sum of the elements in each part is the same.

### Complexity
To build the suffix array, we scan all the elements from right to left, and to count the total number of ways we scan another time the array, but this time from left to right, so the total time complexity is `O(n)`. Since we have to keep the suffix array, the space complexity is `O(n)`.
