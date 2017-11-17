#include <iostream>
#include <vector>
#include <bits/stdc++.h>


std::string find_sub(std::string const& s) {

    std::string result;
    char last_char = 'a';

    for (size_t i=s.size()-1; i>=0; --i) {
        if (s[i] >= last_char) {
            result += s[i];
            last_char = s[i];
        }
    }

    std::reverse(result.begin(), result.end());

    return result;
}

int main() {

    std::string s;
    std::cin >> s;

    std::cout << find_sub(s) << std::endl;

    return 0;
}