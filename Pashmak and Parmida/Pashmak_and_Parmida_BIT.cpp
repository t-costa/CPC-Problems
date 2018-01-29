#include <iostream>
#include <vector>
#include <algorithm>

template <class NumType>
struct fenwick_tree {

private:

    std::vector<NumType> bit;

public:

    explicit fenwick_tree(size_t n) : bit(n+1) { }

    void update(size_t pos, NumType val) {

        while (pos < bit.size()) {
            bit[pos] += val;
            pos += (pos & -pos);
        }
    }

    NumType get_value(size_t pos) {

        NumType val = 0;
        
        while (pos > 0) {
            val += bit[pos];
            pos -= (pos & -pos);
        }

        return val;
    }
};

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
    size_t n;
    int val;
    int64_t res = 0;
    std::vector<int> test;
    std::cin >> n;

    test.reserve((size_t) n);
    fenwick_tree<int> bit(n);
    std::vector<size_t> suffix_sum(n);

    for (size_t i=0; i<n; ++i){
        std::cin >> val;
        test.push_back(val);
    }

    size_t sz = remap<int>(test);
    std::vector<size_t> counter(sz, 0);

    for (int i=(int)n-1; i>=0; --i){
        counter[test[i]]++;
        suffix_sum[i] = counter[test[i]];
        bit.update(counter[test[i]], 1);
    }

    //suffix_sum[i] == f(i, n, test[i])
    //bit counts the number of equal elements in suffix_sum
    //bit[i] == x -> there are x entries in suffix_sum equal to x

    std::fill(counter.begin(), counter.end(), 0);

    for (size_t i=0; i<n; ++i) {
        bit.update(suffix_sum[i], -1);  //we don't consider element i
        counter[test[i]]++; // == f(1, i, test[i])
        res += bit.get_value(counter[test[i]]-1);
        //get number of elements smaller then counter[test[i]]
    }

    std::cout << res << std::endl;

    return 0;
}
