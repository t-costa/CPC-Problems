#include <iostream>
#include <vector>
#include <algorithm>


void build_input_array(std::vector<int>& v, size_t n) {

    int val = 0;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> val;
        v.push_back(val);
    }

    std::sort(v.begin(),
              v.end(),
              [](int a, int b) {
                  return b < a;
              });
}

void build_queries_array(std::vector<int>& v, int q) {

    size_t left = 0, right = 0;

    for (int i = 0; i < q; ++i) {
        std::cin >> left >> right;

        //update the interval from 1 to right
        v[right-1]++;
        //if left is greater then one, all the elements
        //between 1 to left don't have to be incremented
        if (left > 1)
            v[left-2]--;
    }

    //suffix sum of the frequencies
    for (auto it = v.end() - 2; it >= v.begin(); --it)
        *it += *(it + 1);

    std::sort(v.begin(),
              v.end(),
              [](int a, int b) {
                  return b < a;
              });
}

void count_sum(std::vector<int> const& values,
               std::vector<int> const& frequencies) {

    int64_t sum = 0;

    for (size_t i = 0; i < values.size(); ++i)
        sum += static_cast<int64_t>(values[i]) * static_cast<int64_t>(frequencies[i]);

    std::cout << sum << std::endl;
}

int main() {

    std::ios_base::sync_with_stdio(false);

    size_t n = 0;
    int q = 0;

    std::cin >> n >> q;

    std::vector<int> test;
    test.reserve(n);
    std::vector<int> queries(n, 0);

    build_input_array(test, n);

    build_queries_array(queries, q);

    count_sum(test, queries);

    return 0;
}