# Firing Employees

### Description
The algorithm, for each test case, builds a vector of `struct Node`, which consists of a value (the rank of the employee) and the list of child nodes, identified as index of the vector. Since we know that the rank of each employee goes from 1 to n, and that there aren't two employees whith the same rank, the values of the nodes are just from 1 to n. So for each value in input, if the j-th value is zero, it means that the root of the tree is in position `j`, so we save this position for later; otherwise, the value `val` represents the index of the father in the vector, so we add in the vector of all the employees in position `val` the new child `j`.

Once the tree is completed, we do a BFS starting from the root and we check for each node if the value saved in the node plus the depth of the node is prime. Since we don't know the depth of each node, we keep a variable `number_children` which indicates the number of nodes the first time we insert nodes in the queue for the visit and a variable `depth` initialized to one which counts the depth of the nodes; for each visited element, we add the children in the queue and decrement `number_children`; if it reaches zero, it means that we have visited all the nodes in that level, so all the nodes in the queue in that moment are at the same level and we increment `depth` and set `number_children` to the numbers of elementes currently in the queue. 

### Complexity
Once we collected the input, the algorithm is just a BFS and a primality test. The BFS is obviously linear but for each element we have to invoke `checkPrime`, which is linear in the square root of the value in input. So in the worst case the total time complexity can be `O(n^2)`, since n is both the number of elements and the maximum rank. Since we have that n is less than 10^5, the primality test could have be done keeping just a list of primes and checking only those values, but I prefered a more general solution.

The space complexity is `O(n)`, since we keep a vector of n `Node` elements and the total size of the list of children is exactly n, since every element has just a father.
