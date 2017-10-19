# Check for BST

### Description
Starting from the root, the algorithm checks if the value of the node is between the minimum and the maximum accepted values. Then, for each child, it checks recursivly if the value of the left child is between the minimum and the value of the current node, and vice versa for the right child checks if the value is between the value of the current node and the maximum. As soon as we reach a node that doesn't fulfill these requirements the algorithm returns false; otherwise, if we reach a null node we return true. The final value returned will be the logic and between the return values of all the nodes.

### Complexity
The algorithm checks every node just once, so the total time complexity is `O(n)`, while the space complexity is constant since the algorithm doesn't use additional memory. 
