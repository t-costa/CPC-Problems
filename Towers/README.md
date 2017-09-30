# Towers

### Description
The algorithm exploits an hashtable to count efficiently the duplicates element in the input array. The algorithm works
like this: for every element in the input array, it checks if the current element is already in the table: if so, it updates the corresponding
counter and check if its value is greater than the current max (initialized to one), if so, it updates max; otherwise, the element is not
in the table, and it adds it with the counter set to one and increments the counter of the total objects. At the end of the iterations, `total`
will be the total number of different elements in the array and `max` will be the maximum number of equal elements.

### Complexity
The time complexity of the algorithm is `O(n)`, since we scan once all the array and the operations on the hash map are constant in average ([c++ reference](http://www.cplusplus.com/reference/unordered_map/unordered_map/)).
The space complexity is `O(n)`, since we have to keep track of all the distinct values in the input array.
