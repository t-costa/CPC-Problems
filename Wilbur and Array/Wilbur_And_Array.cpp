#include <iostream>
#include <vector>

int main() {

    std::ios_base::sync_with_stdio(false);
    int n;
    int64_t val, counter = 0, last_val = 0;
    std::cin >> n;

    for (int i=0; i<n; ++i) {
        std::cin >> val;
        counter += std::abs(last_val - val);
        last_val = val;
    }

    std::cout << counter << std::endl;

    return 0;
}
