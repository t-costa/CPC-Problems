#include <iostream>
#include <vector>


std::vector<int64_t> create_suffix(std::vector<int64_t> const& v, int64_t sum){
    std::vector<int64_t> suffix(v.size(), 0);
    int64_t acc = 0;

    for (int i = (int) v.size()-1; i>=0; --i){
        acc += v[i];
        if (acc == sum)
            if (i != v.size() - 1) suffix[i] = suffix[i+1] + 1;
            else suffix[i] = 1;
        else {
            if (i != v.size() - 1) suffix[i] = suffix[i+1];
            else suffix[i] = 0;
        }
    }

    return suffix;
}

void count(std::vector<int64_t> const& values, std::vector<int64_t> const& suffix, int64_t sum){
    int i = 0;
    int64_t acc = 0, res = 0;

    for (i = 0; i < (int) values.size() - 2; ++i){
        acc += values[i];
        if (acc == sum)
            res += suffix[i+2];
    }

    std::cout << res << std::endl;
}

int main() {
    unsigned long n;
    int64_t sum = 0;
    std::vector<int64_t> test;
    std::cin >> n;
    test.reserve(n);

    for (int i=0; i<n; ++i){
        int64_t val;
        std::cin >> val;
        test.push_back(val);
        sum += val;
    }

    if (sum % 3 != 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    sum /= 3;

    std::vector<int64_t> suffix_sum = create_suffix(test, sum);

    count(test, suffix_sum, sum);

    return 0;
}
