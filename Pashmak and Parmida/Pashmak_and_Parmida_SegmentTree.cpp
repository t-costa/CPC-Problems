#include <iostream>
#include <vector>
#include <algorithm>

#define LEFT(i)     (2 * (i) + 1)
#define RIGHT(i)    (2 * (i) + 2)
#define PARENT(i)   (((i) - 1) / 2)

template <class T>
struct segment_tree {

private:

    struct node {
        T val;
        size_t left;
        size_t right;
    };

    std::vector<node> tree;
    int left_most_node;
    int offset;
    size_t tree_size;

public:

    explicit segment_tree(size_t n) {
        tree_size =  2*n-1;
        tree.resize(tree_size);

        auto h = (int) ceil(log2(n));
        if (h > 0) {
            // left-most internal node id
            left_most_node = (int(1) << (h - 1)) - 1;
            // left-most node
            offset = LEFT(left_most_node);
        } else
            offset = 0;

        // set leaves circularly
        size_t i = 1;
        for (size_t j = offset; j != tree_size; ++i, ++j)
            tree[j] = node {0, i, i};

        for (size_t j = 0; i != n + 1; ++i, ++j)
            tree[n - 1 + j] = node {0, i, i};

        // set internal nodes
        for (size_t j = tree_size - 1; j != 0; j -= 2)
            tree[PARENT(j)] = node {0, tree[j - 1].left, tree[j].right};
    }

    void inc(size_t pos, T val, size_t start = 0) {

        //out of interval
        if (tree[start].left > pos || tree[start].right < pos)
            return;

        tree[start].val += val;

        //reached the leaf
        if (tree[start].left == pos && tree[start].right == pos)
            return;

        inc(pos, val, LEFT(start));
        inc(pos, val, RIGHT(start));
    }

    T get(size_t pos, size_t start = 0) {

        if (tree[start].right == pos)
            return tree[start].val;


        //out of interval
        if (tree[start].left > pos || tree[start].right < pos)
            return 0;

        size_t left = LEFT(start);
        size_t div = tree[left].right;
        //if i go right, i need the value of the left node
        if (pos <= div)
            return get(pos, left);
        else return tree[left].val + get(pos, RIGHT(start));
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

    test.reserve(n);
    std::vector<int> suffix_sum((size_t) n);
    segment_tree<int> seg_tree((size_t)  n);

    for (size_t j=0; j<n; ++j){
        std::cin >> val;
        test.push_back(val);
    }

    size_t sz = remap<int>(test);
    std::vector<int> counter(sz, 0);

    for (int j=(size_t) n-1; j>=0; --j){
        counter[test[j]]++;
        suffix_sum[j] = counter[test[j]];
        seg_tree.inc(counter[test[j]], 1);
    }

    std::fill(counter.begin(), counter.end(), 0);

    for (size_t j=0; j<n; ++j) {
        seg_tree.inc(suffix_sum[j], -1);
        counter[test[j]]++; // == f(1, i, test[i])
        res += seg_tree.get(counter[test[j]]-1);
        //get number of elements smaller then counter[test[i]]
    }

    std::cout << res << std::endl;

    return 0;
}
