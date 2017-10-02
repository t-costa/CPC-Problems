# Megacity

### Description
The algortithm receives in input the coordinates of the locations and the number of their inhabitants, and for every location it computes its radius and stores it and the number of inhabitants in a vector. 
Once the input is collected, it sorts the vector from the nearest location to the farest. After that, it scans the sorted vector and increases the radius until the total number of inhabitants is greater or equal than 100000 or there are no more locations.

### Complexity
The algorithm sort a vector and then scans it, so the dominating cost in time is `O(n*log(n))`, while the space complexity is `O(n)`, since it stores just the vector of radius and number of inhabitants and a few other variables.
