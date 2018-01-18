#include <iostream>
#include <vector>
#include <algorithm>

#define LEFT(i)     (2 * (i) + 1)
#define RIGHT(i)    (2 * (i) + 2)
#define PARENT(i)   (((i) - 1) / 2)

struct node {
    int val;
    int left;
    int right;
};

void inc(std::vector<node>& tree, int pos, int val, int start = 0) {

    //out of interval
    if (tree[start].left > pos || tree[start].right < pos)
        return;

    tree[start].val += val;

    //reached the leaf
    if (tree[start].left == pos && tree[start].right == pos)
        return;

    inc(tree, pos, val, LEFT(start));
    inc(tree, pos, val, RIGHT(start));
}

int get(std::vector<node>& tree, int pos, int start = 0) {

    if (tree[start].right == pos)
        return tree[start].val;


    //out of interval
    if (tree[start].left > pos || tree[start].right < pos)
        return 0;

    int left = LEFT(start);
    int div = tree[left].right;
    //if i go right, i need the value of the left node
    if (pos <= div)
        return get(tree, pos, left);
    else return tree[left].val + get(tree, pos, RIGHT(start));

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
    std::vector<int> suffix_sum((size_t) n);
    size_t tree_size = (size_t) 2*n-1;
    std::vector<node> segment_tree(tree_size);

    auto h = (int) ceil(log2(n));
    int left_most_node, offset;
    if (h > 0) {
        // left-most internal node id
        left_most_node = (int(1) << (h - 1)) - 1;
        // left-most node
        offset = LEFT(left_most_node);
    } else
        offset = 0;

    // set leaves circularly
    int i = 1;
    for (int j = offset; j != tree_size; ++i, ++j) {
        segment_tree[j] = node {0, i, i};
    }

    for (int j = 0; i != n+1; ++i, ++j) {
        segment_tree[n - 1 + j] = node {0, i, i};
    }

    // set internal nodes
    for (int j = tree_size - 1; j != 0; j -= 2) {
        segment_tree[PARENT(j)] = node {0, segment_tree[j-1].left, segment_tree[j].right};
    }

    for (int j=0; j<n; ++j){
        std::cin >> val;
        test.push_back(val);
    }

    size_t sz = remap<int>(test);
    std::vector<int> counter(sz, 0);

    for (int j=n-1; j>=0; --j){
        counter[test[j]]++;
        suffix_sum[j] = counter[test[j]];
        inc(segment_tree, counter[test[j]], 1);
    }

    std::fill(counter.begin(), counter.end(), 0);

    for (int j=0; j<n; ++j) {
        inc(segment_tree, suffix_sum[j], -1);
        counter[test[j]]++; // == f(1, i, test[i])
        res += get(segment_tree, counter[test[j]]-1);
        //get number of elements smaller then counter[test[i]]
    }

    std::cout << res << std::endl;

    return 0;
}
