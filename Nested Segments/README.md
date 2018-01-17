# Nested Segments

[codeforces](http://codeforces.com/problemset/problem/652/D?locale=en)

## Solution with BIT

### Description
Once the input is collected in a vector of `struct segment` with the values of the extremes of the interval and the order of the intervals, it is sorted in increasing order with respect the right extreme of the interval. Next, the right values are remapped in elements between 1 and n, for reason that will be clear shortly, and then sorted again in decreasing order, with respect to the left values this time.
Now, we build a Fenwick tree `bit` and a support vector `sol` initialized to zero. To count the number of segments contained in another segment, we use `bit`: for each segment, we insert a 1 in the position corresponding to the right extreme of the interval. In this way, given a segment `s`, with extremes `l` and `r`, the number of segments contained in `s` is equal to the sum of the elements preceding `r` in `bit`.

Why is this true? Since the segments are sorted in decreasing order with respect to the left extreme, when we are processing a segment `s` with extremes `l` and `r`, we have already processed all the segments whit a left extreme greater then `l`, so we have a 1 in the positions corresponding to their right extremes. When are these already processed segments nested in the current one? Only when `r` is greater then their right extremes, that is when `l < l1 && r > r1`, and this is exactly the prefix sum calculated in position `r`. All the segments that will be processed after `s` will not be contained in `s`, since their left value is certainly smaller then `l` (beacuse there are not extremes in common between segments).

Now it should be clear why we need remapping the right positions: since we need only the relative positions of the segments, and not their actual size, remapping those positions allows to save space for the BIT vector, otherwise for huge values of `r`, with a small number of segments, we could even not be able to store the vector in main memory.

Once we calculated the number of nested segments for `s`, we store this result in `sol`, in the position stored in the `struct segment`, so that we can print all the answers in the correct order.

### Complexity
In this problem, we have first to sort twice the array in input, then we have to do the `sum` and `add` operation of the Fenwick tree `n` times, so, since the operations on the tree are logarithmic, the total time complexity is `O(nlog(n))`. The space complexity instead is `O(n)`, since we have to keep the BIT tree and the array of solutions.


## Solution with Segment Tree

### Description
We treat the input in the same way as in the BIT case, so we remap it and sort in decreasing order of the left extremes. Then we build a binary tree complete on the right, with the `n` values of the right extremes in the leaves. 

To solve the problem, we navigate the tree from the root taking the segments in the computed order and for each segment we search its right extreme and we increment the value of the nodes which fully include the current value, and we stop when we reach the smallest interval which includes the value searched. If during the search we go right in the tree, this means that all the elements in the left subtree are nested in the current segment, so we include them in the solution.

In this way, let `m` be an internal node of the tree, with a left extreme `l` and a right extreme `r`. The value stored in `m` is equal to the number of nested segments for a segment with right extreme `r`, since the left extremes are sorted in decreasing order, so the shorter segments are already counted.

### Complexity
The complexity is the same as for the BIT solution: `O(nlog(n))` in time, since we sort the input and every query takes `O(log(n))` time, and the space is `O(n)` for the segment tree.
