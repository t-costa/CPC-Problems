#include <iostream>
#include <vector>


void update(std::vector<int64_t> &v, int pos, int val) {

    while (pos <= (int) v.size()) {
        v[pos] += val;
        pos += (pos & -pos);    //update next element
    }
}

void print_value(std::vector<int64_t> const& v, int pos) {

    int val = 0;

    while (pos > 0) {
        val += v[pos];
        pos -= (pos & -pos);
    }

    std::cout << val << std::endl;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    int number_test, u, q, val;
    int n, left, right;
    std::cin >> number_test;

    for (int j=0; j<number_test; ++j) {
        std::cin >> n >> u;

        std::vector<int64_t> bit(n+1, 0);

        for (int i=0; i<u; ++i){
            std::cin >> left >> right >> val;
            update(bit, left+1, val);
            if (right + 2 < (int) bit.size())
                update(bit, right+2, -val);
        }

        std::cin >> q;

        for (int i=0; i<q; ++i){
            std::cin >> left;
            print_value(bit, left+1);
        }

        bit.clear();
    }

    return 0;
}