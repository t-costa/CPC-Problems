# Pashmak and Parmida

[codeforces](http://codeforces.com/contest/459/problem/D)

## Solution with BIT

### Description
After receiving the elements in input, the algorithm remaps them in a range from 1 to n and creates three other vectors: `counter` which will store the number of occurences of an element, `suffix_sum` which in position `i` will contain the value of `f(i, n, i-th element)`, and `bit` which is a Fenwick tree with the property that `bit[i] = x` means that there are `x` entries in `suffix_sum` equal to `i`. This vectors will be filled scanning the elements from right to left.

After having filled the three vectors, `counter` is reinitialized to zero, and scanning the elements from left to right we update `bit` removing the current element and we update counter so that at every iteration the value of `counter[i-th element]` is equal to `f(1, i, i-th element)`.

At this point, we have all the values we need in `counter` and `bit`, so we just need to retrieve the correct value in `bit` to count the answer to the problem, so we retrieve `counter[i-th element]-1` since we are looking for the number of `(i, j)` so that `f(1, i, i-th element) > f(j, n, j-th element)`. Notice that first we have to remove the contribution of `i` in `bit`, since the problem requires `i < j`.

### Complexity
The time complexity of the algorithm is `O(n*log(n))`, since we have to sort the element to remap them and we have to perform `O(n)` operations over a BIT that have a logarithmic cost.

The space complexity is `O(n)`, since we store three more vectors, and all the vectors have at most `O(n)` elements. Notice that without the remapping the space complexity could be very large, since we need to index a vector with the value of the elements in input. 


## Solution with Segment Tree

### Description
The problem is solved in exactly the same way, the only difference is that now we have to build a segment tree complete on left which will store the sum of the values of `suffix_sum`. So we can use the segment tree as we used the BIT in the other solution, retrieving efficiently the sum of the desired values.

### Complexity
The time and space complexity is the same as for the BIT solution: `O(n*log(n))` and `O(n)`.
