# Knapsack 0-1

### Description
To solve the problem, we create a matrix of possible values and weights. In position `(i, j)`, we store the maximum revenue for the same problem, considering just the first `i` objects and a maximum capacity of `j`. In this way, in position `(n, W)` we find the solution to our problem.

How do we fill this matrix? We follow a simple rule, when considering position `(i, j)` in the matrix:

- If the weight of the `i-th` object is greater than `j` the value in position `(i, j)` is the same as the one in position `(i-1, j)`
- Otherwise, we put the maximum value between the one stored in position `(i-1, j)` and the one in position `(i-1, j-w[i])` plus `v[i]`, were `w[i]` is the weight of the i-th object, and `v[i]` is its value.

The first rule, simply represents the case where we can not take the i-th object, otherwise we exceed the maximum capacity of the knapsack.
The second rule represents the case where we have to choose if it's better to take the i-th or not. Our choice is guided by the possible revenue we can get: if we don't take the object, our revenue is the same as the one in position `(i-1, j)`; othwerwise, we add the value of the new item to the maximum revenue we had considering all the preceding elements and with a total weight wich is now `j-w[i]`, because we have selected the i-th element, so that space is occupated.

### Complexity
The time and space complexity is `O(n*W)`, which is not polinomial but pseudo-polinomial, since its running time is a polynomial in the length of the input (the number of bits required to represent it) and the numeric value of the input (the largest integer present in the input)<sup>[1](#ref)</sup>.

<a name="ref">1</a>: [Wikipedia - Pseudo-polynomial time](https://en.wikipedia.org/wiki/Pseudo-polynomial_time)
