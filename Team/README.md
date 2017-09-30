# Finding Team Member

### Description: 
The algorithm adopts a brute-force strategy, but it's the only possible one. For every element in input, the algorithm builds a triple <value in input, index first person, index second person>, with index starting from 1, and collects all the triples in a vector.
Once the input is collected, it sorts it in decreasing order checking just the first value of the triple, after that, it tries to build couples starting from the "strongest one" (the one with the maximum value), using the second element in the triple as an index of the vector `paired` and the last one as the value. In this way, we can check if the other couples can be formed or if one of the two people has already a teammate.
When we have formed the required number of couples, the algorithm ends printing the values saved in `paired` from the first to the last.

### Complexity:
The algorithm receives in input `O(n^2)` elements, it saves them in a vector, it sorts the vector, and then it scan it and a smaller vector, so the dominant cost is sorting, `O((n^2)*log(n))`, while the space cost is `O(n^2)` for storing the `test` vector.
To reduce a bit the used space, since from the specification the indeces are smaller then 400, we use a `short int` to store them, in ` std::vector<std::tuple<int, short, short>> test` and ` std::vector<short> paired(n, 0)`.
