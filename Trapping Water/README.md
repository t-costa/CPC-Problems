<b><i>Trapping Water</i></b>

<b>Description:</b> To calculate the maximum amount of water that can be trapped, the algorithm counts how much water can be trapped
in every single cell. To do this, we notice that for every single cell, we can't trap more water than the height of the heighest
column (on the right or left) nor less than the shorter column (otherwise we could trap more water).
So to trap the maximum amount of water we have to calculate the shorter of the highest columns surrounding the cell and remove
the height of the current cell (because that space can not be filled with water). Doing this for every cell, we could end up with
negative values, which are nonsense for our purposes, so we have to take the maximum between the calculated value and zero.

This explains the last for in maxWater:

```c++
for (int i=0; i<n; i++)
        trappedWater += std::max(std::min(leftMax[i], rightMax[i]) - v[i], 0);
```

The other for loop are needed to initialize the vectors `leftMax` and `rightMax`, which contain respectively the largest value from the
left and from the right (zero for the first and last value in the initial array).

<b>Complexity:</b> The algorithm scan all the input array three times, so the time complexity is `O(n)`, and keeps in memory two addictional array (`leftMax` and `rightMax`) of n elements each, so the space complexity is `O(n)`.
