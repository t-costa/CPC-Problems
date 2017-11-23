#include <iostream>
#include <vector>


std::vector<std::vector<int>> fib;

void fibonacci(std::vector<std::vector<int>>& v, size_t n) {

    v.reserve(n+1);

    for (size_t i=0; i<=n; ++i)
        v.emplace_back(std::initializer_list<int>{});

    v[0].emplace_back(0);
    v[1].emplace_back(2);
    v[2].emplace_back(3);

    for (size_t i=3; i<=n; ++i) {
        auto v1 = v[i-2];
        auto v2 = v[i-1];
        //size v1 <= size v2
        size_t j;
        int rest = 0;
        for (j=0; j<v1.size(); ++j){
            int sum = v1[j] + v2[j] + rest;
            if (sum > 9) {
                v[i].emplace_back(sum % 10);
                rest = sum / 10;
            } else {
                v[i].emplace_back(sum);
                rest = 0;
            }
        }
        while (j<v2.size()) {
            int sum = v2[j] + rest;
            if (sum > 9) {
                v[i].emplace_back(sum % 10);
                rest = sum / 10;
            } else {
                v[i].emplace_back(sum);
                rest = 0;
            }
            j++;
        }
        if (rest > 0)
            v[i].emplace_back(rest);
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;

    fibonacci(fib, (size_t) n);

    for (auto it = fib[n].rbegin(); it != fib[n].rend(); ++it)
        std::cout << *it;

    std::cout << std::endl;

    return 0;
}