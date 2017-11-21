# Magic Numbers

### Description
First of all, the algorithm checks if the first number is a 1, if not, it prints `NO` and returns. Otherwise, until it finds an error or the end of the number is reached, for each digit, the algorithm counts the number of 4 found one after the others: if it finds more than  two 4 in a row, it's an error; if it finds a digit different from 1 or 4, it's an error.

### Complexity
The algorithm scans the number in input, so for a number of `n` digits, the time complexity is `O(n)`, and also the space complexity is linear.
