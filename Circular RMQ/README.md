# Problem

[Codeforces](http://codeforces.com/problemset/problem/52/C)

### Description
Following the [code](https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/code/segment_trees/trees_with_arrays.cpp) of the lesson, the algorithm builds a tree and a lazy tree. Then it reads the queries from the input and starts solving them. 

For an increment query, the algorithm, starting from the root, first checks if there are pending updates for the current node: if so, it updates the value of the current node, postpones the updates to the children and set the corresponding lazy value to 0.  
After that, it checks if the node is in range for the query and if so, it checks if it is fully in range or not. If it's not fully in range, the algorithm calls the same procedure recursively on the children of that node; otherwise, it updates the value of the node, postpones updates for the children, and notifies the updates to the parent nodes, since their minimum value might have changed.

To update the parents, the algorithm goes up to the root, checking every time if there are pending updates for the nodes and updating the current minimum if necessary.

In case the query is a range minimum one, the algorithm is quite similar to the one for the increment, the only difference is that if the node is full in range it returns directly the minimum stored in the node, without updating anithing since it's just a read, while in case the node is not fully in range, the algorithm returns the minimum of the values in the children.


### Complexity
We build a balanced binary tree, and this takes `O(n)` time. Once the tree is built, for every query we have to visit at most log<sub>2</sub> n nodes, for example for queries that contain a single node. The lazy tree permits to save some of the updates, so it can speed up the algorithm in practice, but it doesn't change its time complexity. So the total time complexity is `O(n + q*log(n))`, with `q` number of queries an `n` number of nodes.

The space complexity is instead `O(n + q)`, to keep the lazy tree and the vector with all the queries. Actually, we could optimize this bound, since we can answer every query on the fly, without saving all of them first.
