# Meeting Room

### Description
The input is collected in a struct to keep the original index and the start and finish time of the meeting. Then the input is sorted in increasing order with respect to the finish time of the meetings. Now, we just peek the first meetings that don't overlap with any other meeting. 

To prove that this algorithm really finds one of the optimal solutions, we first prove this lemma:

* *There is at least an optimal solution that contains the first meeting*

  Let `f` be the activity that finishes first, and `X` an optimal solution that doesn't contain `f`. If we remove the first activity `f'`in `X`, and we substitute it with `f`, we obtain a new set with the same cardinality of `X` and wich is conflict-free, since there were no activity in `X` with a starting time smaller than the finishing time of `f'`, and the finishing time of `f` is even smaller than the one of `f'`.  

We can procede by induction and conclude that the greedy algorithm presented above actually finds a set of conflict-free activity of maximum size.

### Complexity
The algorithm first sorts the elements and then scans every element from left to right, so the total time complexity is `O(n*log(n))`.

The space complexity is constant, since, apart from the input data, the algorithm uses just few integer variables.
