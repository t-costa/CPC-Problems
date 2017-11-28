# Powerful Array

### Description
The algorithm collects the elements in input in a vector and the queries in a struct keeping also the original index. Then the Mo's algorithm is applied: the elements in input are logically diveded in buckets of size square root of n, and the queries are sorted with respect to the left value so that each query belongs to a bucket, and inside the same bucket the query are sorted increasingly with respect to the right value of the query.

Now we can apply Mo's algorithm: we keep a vector that counts the occurencies of the elements inside the query and a variable that accumulates the results of the queries.

If we do the computation `Ks·Ks·s` in a naive way, the algorithm would be too slow, so we use a trick: if we have already computed the value `(k^2)*s`, and we have to compute `(k+1)^2*s` we have that `(k+1)^2*s = k^2 + 2*k*s + s` so we just need to add `2*k*s + s`. This is true also if it is the first occurrence of the element (since `k = 0`) and when we have to subtract an occurance of the element.

Once we have the answer for a query, we just use the previously saved index to store the result in a vector, then we just have to scan that vector to recover all the answers in the correct order.

### Complexity
The time complexity of the algorithm is `O((m+n)\sqrt{n})` with `m` queries and `n` elements, since we use Mo's algorithm, while the space complexity is `O(n)` to store the support counter vector.
