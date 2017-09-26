<b><i>Next Larger Element</i></b>

<b>Description:</b> The algorithm exploits a queue to keep track of the elements for which it has not been found a next larger
element yet. The algorithm procedes as follows: for every element in the input array it checks if the current one is larger
than the last element in the queue, if so, it removes it and sets the current element as its next larger element.
At the first element in the queue larger than the current one, we know that all the elements in the queue are larger than the
current one, so we add it at the bottom of the queue.
At the end of the for loop, the elements still in the queue don't have a larger next element, so we set it to -1.

<b>Complexity:</b> The algorithm runs a for loop between all the elements in input and every element is added to the queue just
once (and removed just once) so the total cost in time is `O(n)`. Also the space complexity is `O(n)`, because of the queue and the
vector of the next larger elements.
