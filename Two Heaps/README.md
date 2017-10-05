# Two Heaps

### Description
The number of distinct four digit numbers we can build is `max = #distinct in heap 1 * #distinct in heap 2`, so to maximize this value we want approximatly the same number of distinct element in each heap. To do this, we sort the vector and then for each element:

- If it is a new one, we put it in a heap, choosing the right one in a round-robin way;
- If it is the first duplicate, we put it in the other heap with respect the previous element (so following the round-robin rule);
- Otherwise, it's at least a second duplicate, so we put it in one heap later.

After this first iteration, we have in the heap just the distinct elements, and they are equally distributed, so if k elements are in the first heap, we have k or k+1 elements in the second heap (it depends if the total number of distinct elements, counting also e couple like `x, x` as distinct since we can put each element in a different heap, is even or odd).

Notice that in this way we have maximized the total number of distinct four digit numbers, as requested. At this point, we just need to put all the remaining elements (if any), in the heaps, always following a round-robin policy. These last elements will not change the number of distinct four digit numbers we can create.

### Complexity
The algorithm performs a sort of the input array and then two scans, so the time complexity is `O(n*log(n))`, while the space complexity is just `O(n)` for storing the input array and the array of positions.
