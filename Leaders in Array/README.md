# Solution of the "Leaders in Array" problem

### Description
The solution is really easy. To find all the elements in the array larger than the elements following them
we scan the array from right to left, storing the maximum in a queue and then print the stored values in the same order as in the
initial array. We have to keep track of the values we found because the output has to respect the order of the elements.

### Complexity
The time complexity is obviusly `O(n)`, and the space complexity for the queue is also `O(n)`.
