<b><i>Kadane's Algorithm.</i></b>

<b>Description:</b> The algorithm finds the maximum sum of all contiguous sub-array of the array in input. The solution exploits
two fondamental properties: the elements surrounding the sub-array with maximum sum have to be negative, otherwise we could
include those numbers and increase the sum; the prefix of the maximum sub-array has to be positive, otherwise we could remove
that and we would have a larger sum.

So the algorithm procedes as follows: it scan all the elements once, keeping track of the greatest sum found (initialized to the
first element) and of the sum of the current sub-array. As soon as the sum becomes larger than the current maximum, we update it.
As soon as the sum becomes negative, we set it to zero, because of the second property above.

<b>Complexity:</b> The algorithm consists of just one loop, so each element is examinated only once, so the total time complexity is O(n),
while the extra space in constant (just two variables).
