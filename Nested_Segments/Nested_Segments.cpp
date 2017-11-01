#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>


struct segment {
    long int left;
    long int right;
    int pos;
};

bool compare_left(segment a, segment b) {
    return (a.left > b.left);    //there are no segments that coincide
}

bool compare_right(segment a, segment b) {
    return (a.right < b.right);    //there are no segments that coincide
}

void rearrange(std::vector<segment>& v) {

    std::sort(v.begin(), v.end(), compare_right);

    for (int i=0; i<v.size(); ++i)
        v[i].right = i+1;

    std::sort(v.begin(), v.end(), compare_left);
}

void update(std::vector<int> &v, int pos) {

    while (pos < (int) v.size()) {
        v[pos] += 1;
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

void solve(std::vector<segment> const& v) {

    std::vector<int> bit(v.size() + 1, 0);
    std::vector<long int> sol(v.size(), 0);

    for (auto a : v){
        sol[a.pos] = get_value(bit, a.right);
        update(bit, a.right);
    }

    for (auto n : sol)
        std::cout << n << std::endl;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    long int n, l, r;
    std::vector<segment> test;
    std::cin >> n;
    test.reserve(n);

    for (int i=0; i<n; ++i){
        std::cin >> l >> r;
        test.emplace_back(segment {l, r, i});
    }

    //sort and remap
    rearrange(test);

    //build bit and solve
    solve(test);

    return 0;
}
