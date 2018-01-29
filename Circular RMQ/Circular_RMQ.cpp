#include <iostream>
#include <vector>
#include <cmath>

#define LEFT(i)     (2 * (i) + 1)
#define RIGHT(i)    (2 * (i) + 2)
#define PARENT(i)   (((i) - 1) / 2)


struct query {
    bool rmq;
    size_t left;
    size_t right;
    int val;
};

template <class T>
struct segment_tree {

private:

    struct node {
        T min;
        size_t left;
        size_t right;
    };

    std::vector<node> tree;
    std::vector<T> lazy;
    size_t num_elements;
    size_t tree_size;

    void update_lazy(size_t current) {
        if (lazy[current] != 0) {

            //there are pending updates for the node
            tree[current].min += lazy[current];

            if (tree[current].left != tree[current].right) {
                //the element is not a leaf
                //postpone updates for children
                if (LEFT(current) < tree.size())
                    lazy[LEFT(current)] += lazy[current];
                if (RIGHT(current) < tree.size())
                    lazy[RIGHT(current)] += lazy[current];
            }

            //current node has been updated
            lazy[current] = 0;
        }
    }

    void update(size_t index) {
        update_lazy(index);
        if (LEFT(index) < tree.size()) {
            update_lazy(LEFT(index));
            tree[index].min = tree[LEFT(index)].min;
        }

        if (RIGHT(index) < tree.size()) {
            update_lazy(RIGHT(index));
            tree[index].min = std::min(tree[index].min, tree[RIGHT(index)].min);
        }
    }

public:

    explicit segment_tree(size_t n) {
        tree_size = 2 * n - 1;
        num_elements = n;
        tree.resize(tree_size);
        lazy.resize(tree_size, 0);
    }

    void build_from_input() {
        /**
        * ref: slide of the course
        * */

        auto h = (int) ceil(log2(num_elements));
        int left_most_node, offset;
        if (h > 0) {
            left_most_node = (int(1) << (h - 1)) - 1;
            offset = LEFT(left_most_node);
        } else
            offset = 0;

        size_t i = 0;
        T x;
        for (int j = offset; j != (int) tree_size; ++i, ++j) {
            std::cin >> x;
            tree[j] = node {x, i, i};
        }

        for (int j = 0; i != num_elements; ++i, ++j) {
            std::cin >> x;
            tree[num_elements - 1 + j] = node {x, i, i};
        }

        for (int j = (int) tree_size - 1; j != 0; j -= 2) {
            T min = std::min<T>(tree[j].min, tree[j - 1].min);
            tree[PARENT(j)] = node {min, tree[j-1].left, tree[j].right};
        }
    }

    T range_min(size_t q_left, size_t q_right, size_t current) {

        //node out of range
        if (current >= tree.size())
            return INT64_MAX;

        size_t left = tree[current].left;
        size_t right = tree[current].right;

        update_lazy(current);

        //query out of range
        if (left > q_right || right < q_left)
            return INT64_MAX;

        //node fully in range
        if (left >= q_left && right <= q_right)
            return tree[current].min;

        //recursion on children
        return std::min(range_min(q_left, q_right, LEFT(current)),
                        range_min(q_left, q_right, RIGHT(current)));

    }

    void inc(size_t q_left, size_t q_right, T value, size_t current) {

        //node out of range
        if (current >= tree.size())
            return;

        size_t left = tree[current].left;
        size_t right = tree[current].right;

        update_lazy(current);

        //query out of range
        if (left > q_right || right < q_left)
            return;

        //node fully in range
        if (left >= q_left && right <= q_right) {
            tree[current].min += value;

            if (left != right) {
                //postpone update for children
                if (LEFT(current) < tree.size())
                    lazy[LEFT(current)] += value;
                if (RIGHT(current) < tree.size())
                    lazy[RIGHT(current)] += value;
            }

            //update parents
            size_t i = current;
            while (i != 0) {
                update(PARENT(i));
                i = PARENT(i);
            }

        } else {
            //recursion on children
            inc(q_left, q_right, value, LEFT(current));
            inc(q_left, q_right, value, RIGHT(current));
        }
    }
};  //segment tree class


query read_queries() {

    query q = {};
    std::string left, right, val;
    std::string line;

    getline(std::cin, line);

    size_t i = 0;
    while (line[i] != ' ') {
        left += line[i];
        i++;
    }

    i++;    //space

    while (i < line.size() && (line[i] != ' ' || line[i] == '\n')) {
        right += line[i];
        i++;
    }

    q.left = (size_t) stoi(left);
    q.right = (size_t) stoi(right);

    if (i == line.size())
        q.rmq = true;
    else {
        q.rmq = false;
        while (i < line.size()) {
            val += line[i];
            i++;
        }
        q.val = stoi(val);
    }

    return q;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    size_t n = 0;
    int num_queries = 0;
    std::cin >> n;

    segment_tree<int64_t> tree(n);

    tree.build_from_input();

    std::cin >> num_queries;
    std::cin.ignore(); //remove \n

    for (int i=0; i<num_queries; ++i) {
        query q = read_queries();

        if (q.left > q.right) {
            //circular query
            if (q.rmq) {
                int64_t min = std::min(tree.range_min(q.left, n-1, 0),
                                       tree.range_min(0, q.right, 0));
                std::cout << min << std::endl;
            }
            else {
                tree.inc(q.left, n-1, q.val, 0);
                tree.inc(0, q.right, q.val, 0);
            }
        } else {
            if (q.rmq)
                std::cout << tree.range_min(q.left, q.right, 0) << std::endl;
            else
                tree.inc(q.left, q.right, q.val, 0);
        }
    }

    return 0;
}
