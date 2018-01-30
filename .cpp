#include <iostream>
#include <vector>


int kmp(std::string const& s) {

    std::vector<int> pi;
    pi.reserve(s.size() + 1);

    int k = 0;
    pi[1] = 0;

    for (int i = 1; i<s.size(); ++i) {
        //first character of the string is already "used";
        while (k > 0 && s[k] != s[i])
            k = pi[k];

        if (s[k] == s[i])
            k++;

        //i goes from 1 to n-1 => I want 2 to n
        pi[i+1] = k;

    }

    return k;
}

int main() {

    int num_test;
    std::cin >> num_test;

    while (num_test--) {
        std::string s;
        std::cin >> s;

        std::cout << kmp(s) << std::endl;

    }

    return 0;
}