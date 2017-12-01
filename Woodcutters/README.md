# Woodcutters

### Description
If there are just one or two tree, they can always fall (one to the left and one to the right for example). Otherwise, for sure the first and the last one can fall (left and right). Then, processing the trees from left to right, the general tree in position `i` can fall to the left or to the right: if it can fall to the left, it falls, since it doesn't "steal" space to any other tree; if it can fall to the right, it could "steal" space to the next tree, but is this a problem? If the `i-th` tree falls to the right three things can happen:

1. The `i+1-th` tree can fall to the left
2. The `i+1-th` tree can't fall to the left because of the `i-th` tree that occupies the space
3. The `i+1-th` tree can't fall to the left regardless of what we decide for the `i-th` tree

In cases 1 and 3, we can safely cut the tree, we don't decrease the maximum number of cutten trees; in case 2, we postpone the problem to the first tree that can't be cut neither to the left nor to the right. It seems like we are reducing the maximum number of cutten trees by 1, but actually we are just selecting different trees, since if we cut the first we can't cut the last, and if we don't cut the first we can cut the last.

### Complexity
The time complexity is `O(n)` since we just scan once the array, while the space complexity is constant.
