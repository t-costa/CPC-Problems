#include <iostream>

int main() {

    std::string s;
    std::string hello = "hello";
    std::cin >> s;

    int j = 0, i = 0;

    while (j < hello.size() && i < s.size()) {
        //check character by character if it has to be removed
        if (s[i] == hello[j]) {
            //match
            j++;
        }
        i++;
    }

    if (j == hello.size())
        std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;

    return 0;
}
