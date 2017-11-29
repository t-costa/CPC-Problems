# X Total Shapes

### Description
The algorithm reads the input character by character and for every sequence of `X` in the same row, it checks if it's a new shape or if it belongs to an already seen shape. Every shape has a unique id, so we can store in a map (`x_found`) for each `X` the sequence it belongs to and count how many different shapes there are.

In details, let's suppose we have already found `n` different shapes and we have to check if the new sequence received in input belongs to one (or more) of the already found shapes or if it's a new one.  
To compute the right number of shapes at a given point, we use a few support variables: the already cited map `x_found`; `id_up_block`, a variable that indicates which is the id of the shape of `X` that contacts the current sequence; `space_found`, initialized to false, to remember if at least one `X` doesn't contact another `X` in the preceding row; `same_up_block`, initialized to false, to check if the `X`'s found in the preceding row belongs to the same group.

The algorithm procedes as follows: it scans the sequence from left to right, and for each element it checks if there is an already seen `X` in the same column and preceding row. This is possible checking if that position is present in `x_found`. If is there, the sequence belongs to that shape, so we don't increment the number of shapes and we keep for this sequence the same id of the found x.  
If there is no `X` up, we record this setting to true the variable `space_found`, and we increment the number of shapes found only if it is the first `X` in the sequence. Remembering if there is a space, we can control if the actual sequence joins two different shapes.


```
Example: when we process the sequence in the third row,                       0 1 2 3 4 5 6 7 8 9
processing the first `X` we believe that this sequence belongs              0 O O O X O O X X O X
just to that group, but when we see the third one,                          1 O O X X X O X X O O
since we remember the empty space over the second `X`,                      2 O O O O X X X O O O 
we understands that actually this sequence joins 2 groups that we believed were separated.
```

To control if those shapes are actually different, we check if the already saved id is equal to the one of the new `X` found: if not, we set to false `same_up_block` and we can decrement the number of sequences found. The number of sequences is decremented also if the first `X` has a space up and then we find a shape that contacts the sequence. We don't decrement the variable only if the two blocks already belongs to the same shape, so they have the same id.

Once we have scanned all the current sequence, the algorithm stores all the `X` in `x_found` with a new id if they are a new shape, or with the same id of one of the sequences that it belongs to. This means that older `X` in the map can have a wrong id, because we didn't found yet all the `X` in that shape, but this doesn't matter, since only the `X` in the last row are usefoul.

### Complexity
The time complexity of the algorithm is `O(n*m)`, and also the space complexity is `O(n*m)`, but it's optimizable to a linear space since we can remove all the useless rows.
