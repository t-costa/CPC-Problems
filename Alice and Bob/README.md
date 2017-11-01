# Alice and Bob

### Description
Once collected the input, the algorithm scans the input vector from both sides, imitating the behavior of Alice and Bob eating chocolate. In this way, we keep two variables to count how much time is needed for Alice and Bob to eat the chocolate bars, so when the time spent by Alice is less or equal to the time spent by Bob, she eats a new bar and the left iterator advances, otherwise, Bob eats and the right iterator advances. The algorthm terminates when the left iterator is greater then the right one, so all the chocolate has been eaten, and we print the variables counting the number of chocolate bars eaten by Alice and Bob.

### Complexity
The time complexity of the algorithm is clearly `O(n)`, since all the vector is scanned just once, while the space complexity is constant, since we keep just few variables.
