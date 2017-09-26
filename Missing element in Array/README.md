<b><i>Missing element in Array</i></b>

<b>Description:</b> The algorithm is based on the well known formula ![sum](https://latex.codecogs.com/gif.latex?%5Ctiny%20%5Csum%5Climits_%7Bi%3D1%7D%5En%20i%20%3D%20%5Cfrac%7Bn%28n&plus;1%29%7D%7B2%7D).
So to find the missing number in an unordered list of numbers we just need to calculate the expected sum with the formula above
and subtract from that the sum of the elements in the array.

<b>Complexity:</b> The time complexity is linear, we just need to scan the array once to calculate the sum of all the elements,
and the space is constant, since we keep in memory just two more variables.
