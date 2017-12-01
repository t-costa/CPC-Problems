#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>
#include <cmath>
#include <cassert>

#define LEFT(i)     (2 * i + 1)
#define RIGHT(i)    (2 * i + 2)
#define PARENT(i)   ((i - 1) / 2)


struct node {
    int64_t min;
    int left;
    int right;
};

struct query {
    bool rmq;
    int left;
    int right;
    int val;
};

void read_queries(std::vector<query>& q, int num_query) {

    //getchar();//remove \n
    std::cin.ignore();

    for (int j=0; j<num_query; ++j) {
        query q1;
        std::string left, right, val;
        std::string line;

        getline(std::cin, line);

        int i=0;
        while (line[i] != ' ') {
            left += line[i];
            i++;
        }

        i++;    //space

        while (i < line.size() && (line[i] != ' ' || line[i] == '\n')) {
            right += line[i];
            i++;
        }

        q1.left = stoi(left);
        q1.right = stoi(right);

        if (i == line.size())
            q1.rmq = true;
        else {
            q1.rmq = false;
            while (i < line.size()) {
                val += line[i];
                i++;
            }
            q1.val = stoi(val);
        }

        q.push_back(q1);
    }
}

void update_lazy(std::vector<node>& tree, std::vector<int64_t>& lazy, int current) {
    if (lazy[current] != 0) {
        //there are pending updates for the node

        tree[current].min += lazy[current];
        //TODO: check!
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

void update(std::vector<node>& tree, std::vector<int64_t>& lazy, int index) {
    update_lazy(tree, lazy, index);
    if (LEFT(index) < tree.size()) {
        //assert (lazy[LEFT(index)] == 0);
        update_lazy(tree, lazy, LEFT(index));
        tree[index].min = tree[LEFT(index)].min;
    }

    if (RIGHT(index) < tree.size()) {
        //assert (lazy[RIGHT(index)] == 0);
        update_lazy(tree, lazy, RIGHT(index));
        tree[index].min = std::min(tree[index].min, tree[RIGHT(index)].min);
    }
}



int64_t range_min(std::vector<node>& tree,
               std::vector<int64_t>& lazy,
               int q_left, int q_right, int current) {

    //node out of range
    if (current >= tree.size())
        return INT64_MAX;

    int left = tree[current].left;
    int right = tree[current].right;

    update_lazy(tree, lazy, current);

    //out of range
    if (left > q_right || right < q_left)
        return INT64_MAX;

    //node fully in range
    if (left >= q_left && right <= q_right)
        return tree[current].min;

    //recursion on children
    //int mid = (left + right) / 2;
    return std::min(range_min(tree, lazy, q_left, q_right, LEFT(current)),
                    range_min(tree, lazy, q_left, q_right, RIGHT(current)));

}

void inc(std::vector<node>& tree,
         std::vector<int64_t>& lazy,
         int q_left, int q_right, int value, int current) {

    if (current >= tree.size())
        return;

    int left = tree[current].left;
    int right = tree[current].right;

    update_lazy(tree, lazy, current);

    //out of range
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
        int i = current;
        while (i != 0) {
            update(tree, lazy, PARENT(i));
            i = PARENT(i);
        }
        //update(tree, 0);

    } else {
        //recursion on children
        //int mid = (left + right) / 2;
        inc(tree, lazy, q_left, q_right, value, LEFT(current));
        inc(tree, lazy, q_left, q_right, value, RIGHT(current));
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);

    std::vector<node> tree;
    std::vector<query> queries;

    int n = 0, num_queries = 0;
    std::cin >> n;
    int tree_size = 2 * n - 1;
    tree.resize((size_t) tree_size);
    std::vector<int64_t> lazy((size_t) tree_size, 0);

    /**
     * ref: slide of the course
     * */

    auto h = (int) ceil(log2(n));
    int left_most_node, offset;
    // left-most internal node id
    if (h > 0) {
        left_most_node = (int(1) << (h - 1)) - 1;
        offset = LEFT(left_most_node);
    } else
        offset = 0;

    // left-most node

    // set leaves circularly

    // 1. go forward
    int i = 0;
    int64_t x;
    for (int j = offset; j != tree_size; ++i, ++j) {
        std::cin >> x;
        tree[j] = node {x, i, i};
    }

    // 2. fall back
    for (int j = 0; i != n; ++i, ++j) {
        std::cin >> x;
        tree[n - 1 + j] = node {x, i, i};
    }

    // set internal nodes
    for (int j = tree_size - 1; j != 0; j -= 2) {
        int64_t min = std::min<int64_t>(tree[j].min, tree[j - 1].min);
        tree[PARENT(j)] = node {min, tree[j-1].left, tree[j].right};
    }

    std::cin >> num_queries;  //number queries
    queries.reserve((size_t) num_queries);

    read_queries(queries, num_queries);
    //int num = 0;
    for (auto q : queries) {
        if (q.left > q.right) {
            //circular query
            if (q.rmq) {
                //num++;
                int64_t min = std::min(range_min(tree, lazy, q.left, n-1, 0),
                                       range_min(tree, lazy, 0, q.right, 0));
                std::cout << min << std::endl;
            }
            else {
                inc(tree, lazy, q.left, n-1, q.val, 0);
                inc(tree, lazy, 0, q.right, q.val, 0);
            }
        } else {
            if (q.rmq) {
                //num++;
                std::cout << range_min(tree, lazy, q.left, q.right, 0) << std::endl;
            }
            else
                inc(tree, lazy, q.left, q.right, q.val, 0);

        }
    }

    return 0;
}