# Inversion count

### Description:
The solution is based on a trivial modification of the merge sort algorithm: we keep a global counter initialized to zero and in the merge phase every time there are two elements that have to be swapped to sort the array, we increment the counter. When we swap two elements in position `i` and `j`, with `v[i] > v[j]`, this means that all the elements in the left array following `v[i]` are greater then `v[i]`, because this array is sorted, so we have an inversion for all the elements in the interval from `i` to `j`.
Actually, doing this we count too much elements, because the elements preceding `v[j]` in the right array are not an inversion for `j`, since also the right array is sorted, so these elements are less then `v[j]`. So we subtract those elements and we count the correct number of inversions of the two subarrays.

At the end of the last merge phase, the sum of all the inversions computed at every merge phase will be the total number of inversions.

### Complexity:
The algorithm perform exactly the same steps as the merge sort, plus the operations to update the global counter of inversions, which are constant, so the total time complexity is `O(n*log(n))`.

Since we use an auxiliary array in the merge phase, whose dimension is the sum of the size of the two subarrays we are merging, the space complexity is `O(n)`.
