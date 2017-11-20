#include <iostream>
#include <vector>

int main() {

    int n;
    int64_t val, counter = 0;
    std::cin >> n;

    std::vector<int64_t> finish;
    finish.reserve(n);

    for (int i=0; i<n; ++i) {
        std::cin >> val;
        finish.push_back(val);
    }

    val = finish[0];
    counter = std::abs(val);
    for (auto v : finish) {
        counter += std::abs(val-v);
        val = v;
    }

    std::cout << counter << std::endl;

    return 0;
}