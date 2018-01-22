# Largest Even Number

[geeksforgeeks](https://practice.geeksforgeeks.org/problems/largest-even-number/0)

### Description
The algorithm procedes as follows: it reads the input character by character, putting every element in a vector and saving the position of the smallest even digit (if present). When the number in input terminates, the algorithm swaps the smallest even number to the end of the vector and use counting sort to print in decreasing order all the other elements (all the elements if there is no even number).

### Complexity
The algorithm performs the same step of the counting sort (plus an `O(n)` steps to collect the input and find the position of the least even number) so the total time complexity is `O(n)`; the auxiliary array for the counting sort keeps just ten elements so the complexity is linear.

Also the space complexity is `O(n)`, for storing the array of digits in input and the support array for the counting sort, which as already said, keeps just ten elements.  
