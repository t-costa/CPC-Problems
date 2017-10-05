# Find Pair

### Description
Also in this case we procede with a sort of the input array: we compute the position of the first element of the k-th couple (between 0 and n-1) with the formula `(k-1)/n`, and we call the corresonding element `first`, but the second position of the couple is more tricky to compute. If there were no duplicated elements, it would be just `(k-1) mod n` , but since there are duplicated elements, after we sort the array, we have to compute the position of the first element equal to `first`, `l`, and the number of elements equal to `first`, `r`.
With these informations, we can compute the position of the second element with the formula `((k-1)-l*n)/r`.

For example, in the array `[1 1 1 3 5 8 8 8 8 12]` with `k = 61` and `n = 10`, we have that the position of the element `first` is `(61-1)/10 = 6`, so `first = 8`, and the position of the first element equal to `first` is `5`, while the number of elements equal to `first` is `4`, so the position of the second element of the couple is `(61-1)-5*10)/4 = 2`, so the 61th couple is `(8, 1)`.
 
### Complexity
The algorithm performs a sort of the input array, a scan of it and a couple of costant operations, so the dominating cost is `O(n*log(n))`, while the space complexity is just `O(n)` for storing the input array.
