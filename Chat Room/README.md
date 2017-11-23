# Chat Room

### Description
Once we have the string in input, we check character by character if it's equal to the expected character of the word "hello". If it's not, we skip the character, otherwise we go on checking the next character of "hello". If I have seen all the characters of "hello", the string in input is valid, otherwise not.

### Complexity
The time complexity is linear in the size of the string in input, since in the worst case we have to check every character of it. Also the space complexity is linear, since we keep the string in input.

TODO: We can avoid to keep all the string in input and check character by character, so the space complexity becames constant.
