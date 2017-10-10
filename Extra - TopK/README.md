# Top K elements

### Description
Since it's an extra exercise, I took some freedom in developing this solution. The algorithm takes in input two numbers: `n`, the total number of elements, and `k`, the number of elements we have to return. Then it builds a vector of `n` random numbers, prints this vector, and retrieves the top k elements. 

The algorithm retrieves these k elements in two different way:
- Sorted top k elements
- Unsorted top k elements

After having found the top k elements, the program checks if the two methods have found the same elements, sorting those found by the unsorted strategy, and checking for equality with the last command `assert(std::equal(acc.begin(), acc.end(), top.begin()));`, with acc vector of the elements found with the unsorted strategy and top the vector of the elements found with the sorted strategy.

#### Sorted top k elements
To retrieve the top k elements sorted, we build a priority queue of k elements, with the smallest element on top, and scan the vector just once, inserting every new element in the queue if and only if the new element is larger then the smallest element in the queue (or if the queue has less then k elements). At the end of the scan, we can retrieve the elements from the queue from the smallest to the largest.

#### Unsorted top k elements
This is based on the quick select algorithm: the algorithm recursively split the array in half (ideally) and check which is the partition with the top k elements, and continues the itaration only in that partition, until it finds all the k elements.

### Complexity
#### Sorted top k elements
With this strategy, we scan the array just once, but we can possibly pay for every element the cost of inserting a new element in the priority queue, so the total cost is `O(n*log(k))`.

#### Unsorted top k elements
With this strategy, at the first iteration, we scan once all the elements in the array; at the second iteration, we scan (ideally) `n/2` elements; in the third iteration `n/4` and so on. So the total expected cost is given by the summation of `n + n/2 + n/4 ... = O(n)`. In the worst case, the summation becames `n + (n-1) + (n-2) + ... = O(n^2)`, if the array is splitted in a very unlucky way, for example if the array is sorted. Actually, in our case, the worst case is `O(n*(n-k))`, since as soon as we reach the k-th biggest element, we have done.
