# Lexicographically Maximum Subsequence

### Description
To find the lexicographically maximum subsequence of the string `s`, we scan `s` from left to right: if we find a character that follows the last seen (initially `a`), we add that character to the result and update the `last_char` variable. When we reach the beginning of the string, we have the result accumulated in the opposit order, so we just reverse the string `result` and print it.

### Complexity
The algorithm performs just a scan on the input string, so let `n` be the number of characters of the string, the time complexity is `O(n)`.

Also the space complexity is `O(n)`, since we have to store the input string.
