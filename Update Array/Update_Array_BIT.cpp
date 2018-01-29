#include <iostream>
#include <vector>

template <class NumType>
struct fenwick_tree {

private:

    std::vector<NumType> bit;

public:

    explicit fenwick_tree(size_t n) : bit(n+1) { }

    void update(size_t pos, NumType val) {

        pos++;

        while (pos < bit.size()) {
            bit[pos] += val;
            pos += (pos & -pos);
        }
    }

    NumType get_value(size_t pos) {

        NumType val = 0;

        pos++;

        while (pos > 0) {
            val += bit[pos];
            pos -= (pos & -pos);
        }

        return val;
    }

    size_t size() {
        return bit.size();
    }

};


int main() {

    std::ios_base::sync_with_stdio(false);
    int number_test, u, q, val;
    size_t n, left, right;
    std::cin >> number_test;

    for (int j=0; j<number_test; ++j) {
        std::cin >> n >> u;

        fenwick_tree<int64_t> bit(n);

        for (int i=0; i<u; ++i){
            std::cin >> left >> right >> val;
            bit.update(left, val);
            if (right+1 < bit.size())
                bit.update(right+1, -val);
        }

        std::cin >> q;

        for (int i=0; i<q; ++i){
            std::cin >> left;
            std::cout << bit.get_value(left) << std::endl;
        }
    }

    return 0;
}
