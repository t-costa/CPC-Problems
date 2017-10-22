# Preorder Traversal of BST

### Description
The algorithm puts the first element in a stack, keeping for each node of the tree a struct of three values: value of the node, minimum possible value and maximum possible value. After inserting the first element in the stack, for each other element the algorithm checks if its value is between the minimum and the maximum of the last element in the stack: if so, and the value is less then the value of the current last node, the new element is inserted in the stack. If instead the value is greater, we check if it is a valid element, removing from the stack all the elements whose interval does not contain the value of the new node. If we found such a node, it is removed from the queue, the new element is inserted and we return true; otherwise, the function returns false and the sequence in input is not a preorder traversal of the tree.

In this way, the stack contains only elements which can have a right child. When an element is removed, it means that it can not have any more children. So if a new element does not belong to an interval of some node in the stack, it means that the input is not a preorder visit, otherwise all the input is consumed and every element is inserted in the stack.

### Complexity
The time complexity of the algorithm is `O(n)`, since every element is inserted in the stack at most once, and the space complexity is also `O(n)` since in the worst case all the elements in input are inserted into the stack (for example if every node has only a left child).
