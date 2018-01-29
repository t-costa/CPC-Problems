#include <iostream>
#include <vector>
#include <cmath>

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
        size_t div;
    };

    std::vector<node> tree;

public:

    explicit segment_tree(size_t n) {

        size_t tree_size = 2 * n - 1;
        tree.resize(tree_size);

        /**
         * ref: slide of the course
         * */

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
        size_t i = 0;
        for (size_t j = offset; j != tree_size; ++i, ++j)
            tree[j] = node {0, i, i, i};


        for (size_t j = 0; i != n; ++i, ++j)
            tree[n - 1 + j] = node {0, i, i, i};

        // set internal nodes
        for (size_t j = tree_size - 1; j != 0; j -= 2) {
            int64_t sum = tree[j].val + tree[j-1].val;
            tree[PARENT(j)] = node {sum, tree[j-1].left, tree[j].right, tree[j-1].right};
        }
    }

    T get_val(size_t index_query, size_t index_tree, T acc) {

        if (tree[index_tree].left == tree[index_tree].right)
            return tree[index_tree].val + acc;

        size_t div = tree[index_tree].div;

        //div is the biggest value in the left subtree
        if (index_query <= div)
            return get_val(index_query, LEFT(index_tree), acc+tree[index_tree].val);
        else
            return get_val(index_query, RIGHT(index_tree), acc+tree[index_tree].val);
    }

    void inc(size_t q_left, size_t q_right, T value, size_t current) {

        //node out of range
        if (current >= tree.size())
            return;

        size_t left = tree[current].left;
        size_t right = tree[current].right;

        //out of query range
        if (left > q_right || right < q_left)
            return;

        //node fully in range
        if (left >= q_left && right <= q_right)
            tree[current].val += value;
        else {
            //recursion on children
            inc(q_left, q_right, value, LEFT(current));
            inc(q_left, q_right, value, RIGHT(current));
        }
    }
};


int main() {

    std::ios_base::sync_with_stdio(false);
    int t;
    std::cin >> t;

    while (t--) {
        size_t n = 0;
        int num_updates = 0, num_queries = 0;
        std::cin >> n >> num_updates;
        segment_tree<int64_t> tree(n);

        //read and perform update
        for (int j = 0; j < num_updates; ++j) {
            size_t l, r;
            int64_t val;
            std::cin >> l >> r >> val;
            tree.inc(l, r, val, 0);
        }

        //read and perform query
        std::cin >> num_queries;
        for (int j = 0; j < num_queries; ++j) {
            size_t index;
            std::cin >> index;
            std::cout << tree.get_val(index, 0, 0) << std::endl;
        }
    }

    return 0;
}
