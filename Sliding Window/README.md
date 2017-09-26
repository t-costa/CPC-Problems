<b><i>Sliding window algorithm</i></b>

<b>Description:</b> To find the maximum element in all the windows of size k, we use a queue in which we insert all the elements that
can be useful to determine which is the maximum. So we start from an empty queue and we insert the elements of the array following this
rule: 
- If there are elements from the head of the queue which are no longer in the window, we remove those elements; 
- If there are elements from the back of the queue which are smaller than the current element, we remove those elements. Then we insert the new element from the back of the queue.

Notice that in doing these, to determine the maximum element we just have to watch at the first element in the queue, because it is certainly in the window (otherwise it would have been removed since we start the check from the head), and it's the maximum beacuse when we insert a new element we remove all the smaller elements and we put it at the end of the queue, so the elements are sorted from the largest (the first) to the smallest (the last).

<b>Complexity:</b> The time complexity of the algorithm is `O(n)`. To see why, we have to notice that every element is inserted in the queue just once, so all the insertions cost `O(n)`, and every time we insert an element (after k iterations) we remove at least one, so we can't insert more elements than we remove. So the total time complexity is `O(n)`.
To see the space complexity, we have to notice that during the execution of the algorithm, it can not happen that there are elements not 
in the window in the queue, because imagine we insert an element `x` which is not the maximum (so it will not be the first element),
this means that the maximum element `y` is "older", otherwise inserting that element will remove `x`, and when we remove `y` two things
can happen: `x` will become the new maximum, so it will be removed as soon as it gets outside the window or a larger element is inserted, or another element `z` greater than `x` becomes the maximum. 
Notice that if `z` is greater than `x`, it has also to be older, otherwise inserting it `x` would have been removed. So if `x` becomes the oldest element in the queue, it has to be the maximum, otherwise it would have been removed sooner, and even if `x` lasts for k iteration, at iteration k+1 it will be removed. So the total space complexity is `O(k)`.
