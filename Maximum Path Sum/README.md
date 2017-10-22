# Maximum Path Sum

### Description
Starting from the root, the algorithm is recursively called for each child of the node, returning the maximum value of the path from that node to a leaf. If the node has both children, it means that it is a crossing node for a path from a leaf to another leaf, so the value of the corresponding path is computed and if it's greater than the current maximum (initialized to `INT_MIN`), the variable `max` is updated with the new path. Otherwise, if it has only one child (or if it's a leaf), the function returns the value of the maximum path from itself to a leaf (or just the value of the leaf if it's a leaf), without updating `path`, since it's not a path from one leaf to another but just from an internal node to a leaf.

Once all the node are visited, the variable `max` will be the value of the maximum path from a leaf to another leaf.

### Complexity
The algorithm is a modification of a postorder visit, so the time complexity is `O(n)`, while the additional space complexity is constant, since we use only the variable `max`.
