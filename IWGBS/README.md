# IWGBS - 0110SS

### Description
The goal is to find the number of binary strings without two consecutive zeros. Trying a few cases for short strings, we notice that:

- length 0 -> 0 possibilities
- length 1 -> 2 possibilities (0 and 1)
- length 2 -> 3 possibilities (01, 10, 11)
- length 3 -> 5 possibilities (010, 011, 101, 110, 111)
...

This looks exactly the same rule of the Fibonacci number. Indeed, we notice that the strings of length `n` can be generated taking all the generated strings of length `n-1` and append to them a `1` and all the strings of length `n-2` and append to them a `10`. So we just need to compute the n-th Fibonacci number to get the number of possible strings. Since the value of the desired number can become really huge, it could not fit in 64 bits, so we can store the numbers in arrays, so for each element of the array we have a digit of the number, and we can compute efficiently the n-th Fibonacci number, even for large values of n. To simplify the sum of the values in two arrays, the number is stored from the least significant digit to the most significant one, so when we have to print the value we have to do a reverse iteration on the array.

### Complexity
The time complexity of the algorithm is linear, since we compute the values for every element between 0 and n, storing them in an array, so that every time we need a value we don't have to compute it many times.

Also the space complexity is linear, since we store all the computed values.
