# Alternative Thinking

### Description
To count the maximum number of alternating bits in input, changing just a contiguous sequence, we start counting the number of alternating bits from the beginning, as soon as we find a bit equal to the last one, we change it, and we continue change all the following bits that are equal to the last one. As soon as we find a bit different from the last one, we don't change anymore bits and continue counting normally.
Let `n` be the number of alternating bits in the sequence, without any change. Changing one bit, we can increment the number of alternating bits of at most two (for example from `111` to `101`, so from 1 to 3). Obviously, we don't change a bit if it's already different from the last one, otherwise we can decrement `n`. So, since we can change just a single sequence, as soon as we find a bit that can be changed, we change it, going from `n` to `n+1`. Now, it's possible that the next bit is equal to the changed one, but since we can change contiguous bit, we change it too. When we find a bit different from the last one, changing it we go back to `n`, so we don't change any other bit, so we count that to. In this way, the total number of alternating bits is `n+2` because the first and the last bit changed weren't counted before.

There can be many different sequences that can be changed, but in any case we can increment the value of at most 2.

### Complexity
After receiving the sequence in input, we start scanning the array from left to right, checking every element and possibly changing a subsiquence of them. So the time complexity of the algorithm is `O(n)`, since we have to look at every element, and also the space complexity is `O(n)`, since we keep a vector with all the bits.

TODO: The algorithm could be more efficient counting on the fly the alternating bit storing only the last one, and not all of them, so keeping the same time complexity but reducing the space complexity from linear to constant.
