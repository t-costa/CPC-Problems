#include <iostream>
#include <vector>
#include <algorithm>


void update(std::vector<int> &v, int pos, int val) {

    while (pos < (int) v.size()) {
        v[pos] += val;
        pos += (pos & -pos);
    }
}

int get_value(std::vector<int> const& v, int pos) {

    int val = 0;

    while (pos > 0) {
        val += v[pos];
        pos -= (pos & -pos);
    }

    return val;
}

template<typename T>
size_t remap(std::vector<T>& v) {

    std::vector<T> temp(v);

    std::sort(temp.begin(), temp.end());

    auto sz = (size_t) std::distance(temp.begin(),
                              std::unique(temp.begin(), temp.end()));
    temp.resize(sz);

    for (auto& x : v)
        x = std::distance(temp.begin(),
                          std::lower_bound(temp.begin(), temp.end(), x));
    return sz;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    int n;
    int val;
    int64_t res = 0;
    std::vector<int> test;
    std::cin >> n;

    test.reserve((size_t) n);
    std::vector<int> bit((size_t) n+1, 0);
    std::vector<int> suffix_sum((size_t) n);

    for (int i=0; i<n; ++i){
        std::cin >> val;
        test.push_back(val);
    }

    size_t sz = remap<int>(test);
    std::vector<int> counter(sz, 0);

    for (int i=n-1; i>=0; --i){
        counter[test[i]]++;
        suffix_sum[i] = counter[test[i]];
        update(bit, counter[test[i]], 1);
    }

    //suffix_sum[i] == f(i, n, test[i])
    //bit counts the number of equal elements in suffix_sum
    //bit[i] == x -> there are x entries in suffix_sum equal to i

    std::fill(counter.begin(), counter.end(), 0);

    for (int i=0; i<n; ++i) {
        update(bit, suffix_sum[i], -1); //we don't consider element i
        counter[test[i]]++; // == f(1, i, test[i])
        res += get_value(bit, counter[test[i]]-1);
        //get number of elements smaller then counter[test[i]]
    }

    std::cout << res << std::endl;

    return 0;
}
