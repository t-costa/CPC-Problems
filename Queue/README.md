# Queue

[codeforces](http://codeforces.com/problemset/problem/141/C?locale=en)

### Description
After receiving the input, we sort the couples `<name, position>` in increasing order of position. In this way, if there exist a valid order in the queue, this is one of the valid ones. Then we scan the vector from left to right and we compute `len = index - position`; if `len < 0`, this means that there is no valid ordering, otherwise, we use it as a base to compute the height of people in the queue.

Then we run a inner loop from the first to the current position in the array, and every time the height of an element in position `j < i` is greater or equal then the height of the element in position `i`, we increment the height of the j-th element. In this way we keep consistent the values received in input and we use all different heights from 1 to n.

### Complexity
Since we have two for loops in `generate_heights`, the total time complexity is `O(n^2)`, while the space complexity is `O(n)`.
