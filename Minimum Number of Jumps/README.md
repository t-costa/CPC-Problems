# Minimum Number of Jumps

### Description
To find the minimum number of jumps to go from the beginning to the end of the array, the algorithm follows a greed strategy. Since the value of one element of the array represents the maximum number of jumps we can do, the algorithm procedes as follows: 

1. It initializes the `max_jump` to the value of the first element of the array;
2. It searches the maximum value in the range [starting position + 1, starting position + `max_jump`], and sets `max_jump` to the new maximum found;
3. It repeat the second step until the end of the array is reached.

This works because we can do less jumps than our current maximum, so we can search among all the elements in the interval and find a new maximum in case we don't reach the end of the array, and choosing the maximum permits to reach the end of the array as soon as possible.


### Complexity
The time complexity of the algorithm is linear, since we scan once all the elements in the array, while the space complexity is constant, since we keep just a few variables.
