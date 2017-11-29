# Wilbur and Array

### Description
To count the minimum number of additions of 1 or -1 that we have to do to obtain the array of input, we compute the difference of all the elements in the array, taking every time the absolute value of the result.

For example, for the array `[-2, 1, 7, -3, 5]` we count `abs(0 - (-2)) = 2`, `abs(2 - 1) = 1`, `abs(1 - 7) = 6` and so on.

In this way, we are using a greedy approach: to "create" the first element `n`, we have to perform `n` sums of 1 or -1 (for us they are the same operation, so it dosn't matter if they are `n` increments or `n` decrements). Now, also all the other elements are equal to `n`, so to obtain the second one, we have to perform `n-n2` operations, and we are left with an array of `n-1` elements all equal to `n2`, and we do the same for all the remaining elements.

The computed number of operations is indeed the minimum. To understand it, let's focus on the first element: the only way to increment/decrement it is by performing n operations on all the elements (since every operation on the element in position `i` affects al the elements in the interval `[i, n-1]`. Once the first element is computed, we can't touch it anymore, since it is already the correct value, and we are left with an array of `n-1` elements, all with value `n`, and we repeat the same reasoning for the now first element. To change it from `n` to `n2` we have to perform at least `abs(n-n2)` operations. The absolute value is needed because the result could be negative. So every time we compute the minimum number of operations for change a single value, and we sum this minimums, so we obtain the correct value to change all the elements.

### Complexity
The time complexity is linear, since we scan just once all the elements, while the space complexity is constant, since we keep just a few variables.
