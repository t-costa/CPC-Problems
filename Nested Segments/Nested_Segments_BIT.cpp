#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

struct segment {
    int left;
    int right;
    size_t pos;
};

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

};


void rearrange(std::vector<segment>& v) {

    std::sort(v.begin(), v.end(),
              [](segment const& a, segment const& b) -> bool {
        return a.right < b.right;
    });

    for (int i=0; i<v.size(); ++i)
        v[i].right = i;

    std::sort(v.begin(), v.end(),
              [](segment const& a, segment const& b) -> bool {
        return a.left > b.left;
    });
}


void solve(std::vector<segment> const& v) {

    fenwick_tree<int> bit(v.size());
    std::vector<int> sol(v.size(), 0);

    for (auto a : v){
        sol[a.pos] = bit.get_value((size_t) a.right);
        bit.update((size_t) a.right, 1);
    }

    for (auto n : sol)
        std::cout << n << std::endl;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    size_t n;
    int l, r;
    std::vector<segment> test;

    std::cin >> n;
    test.reserve(n);

    for (size_t i=0; i<n; ++i){
        std::cin >> l >> r;
        test.emplace_back(segment {l, r, i});
    }

    //sort and remap
    rearrange(test);

    //build bit and solve
    solve(test);

    return 0;
}
