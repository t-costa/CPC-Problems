# Little Girl Maximum Sum

### Description
Once the input is collected, it's sorted in decreasing order. Next, we create a support array in which we will store the frequency of occurrences of the elements involved in the queries. To do so, for each couple in input, we increment the corresponding value of the right position, and decrement the value of the left position, if different from zero. Then, starting from the end of the array, we build the suffix sum of the frequences. In this way, in position `i` we found the frequency of occurences of the element in position `i` of the original array.
Since the original array is sorted to maximize the sum, we sort the array of frequences, then, we just scan the arrays summing the products between the values in the original array and the corresponding frequency.

### Complexity
First, we sort the input array, then to build the array of frequences we just update `2*q` elements, with `q` number of queries, and then sort the array. After that, we scan the two arrays to calculate the sum, so the total time complexity is `O(nlog(n))`. Since `q` and `n` can span the same range of values, the linear time in `q` to update the elements of the support array should not exceed the time to sort two arrays of `n` elements, even if in practice it can slow down the computation because of cache miss, since the elements are accessed in random positions.
The space complexity is `O(n)`, since we keep just a support array of `n` elements.
