#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

#define LEFT(i)     (2 * (i) + 1)
#define RIGHT(i)    (2 * (i) + 2)
#define PARENT(i)   (((i) - 1) / 2)


struct node{
    int val;
    int left;
    int right;
    int size_sub_tree;
    bool index;
};

void copy(std::vector<node>& b, int index_a, int index_b, int index_b_end, int start = 0) {

    if (start >= b.size())
        return;

    if (b[start].left > index_b_end || b[start].right < index_b)
        return;

    if (b[start].left >= index_b && b[start].right <= index_b_end) {
        //fully inside
        b[start].val = index_a;
        if (b[start].left == b[start].right)
            b[start].index = true;
        return;
    }

    int div = b[start].left + b[LEFT(start)].size_sub_tree-1;

    //if node had a value, push to children and reset
    if (b[start].val != INT_MIN) {
        //push down updates to children
        if (LEFT(start) < b.size())
            b[LEFT(start)].val = b[start].val;
        if (RIGHT(start) < b.size()) {
            //from parent to children, the left children was fully included
            int range = b[LEFT(start)].size_sub_tree;
            b[RIGHT(start)].val = b[start].val + range;
        }
        b[start].val = INT_MIN;
    }

    bool gone_left = false;
    if (index_b <= div) {
        //recursion to the left
        copy(b, index_a, index_b, index_b_end, LEFT(start));
        gone_left = true;
    }
    if (index_b_end > div) {
        //recursion (also) to the right
        if (gone_left) {
            int range =  b[LEFT(start)].left + b[LEFT(start)].size_sub_tree - index_b;
            copy(b, index_a + range, index_b+range, index_b_end, RIGHT(start));
        } else {
            //don't add range, no left
            copy(b, index_a, index_b, index_b_end, RIGHT(start));
        }

    }

}

void access(std::vector<node>& b, std::vector<int> const& a,
               int index, int start = 0) {
    //take the value of the first node that contains the index
    if (start >= b.size())
        return;

    if (index < b[start].left || index > b[start].right)
        return;

    if (index >= b[start].left && index <= b[start].right && b[start].val != INT_MIN) {
        //first node that contains index with a meaningful value
        if (b[start].left == b[start].right) {
            //leaf, check if index or value
            if (b[start].index)
                std::cout << a[b[start].val] << std::endl;
            else
                std::cout << b[start].val << std::endl;
        } else {
            //internal node, find value in a
            int div = index - b[start].left;
            std::cout << a[b[start].val + div] << std::endl;
        }
        return;
    }

    int div = b[start].left + b[LEFT(start)].size_sub_tree-1;

    if (index > div)
        access(b, a, index, RIGHT(start));
    else
        access(b, a, index, LEFT(start));
}

int main() {

    int m;
    size_t n;
    int x, y, k;
    std::cin >> n >> m;

    std::vector<int> a;
    a.reserve(n);
    int val;
    for (int i=0; i<n; ++i){
        std::cin >> val;
        a.push_back(val);
    }

    //build seg tree on b
    size_t tree_size = 2*n-1;
    std::vector<node> b(tree_size);

    auto h = (int) ceil(log2(n));
    int left_most_node, offset;
    if (h > 0) {
        // left-most internal node id
        left_most_node = (int(1) << (h - 1)) - 1;
        // left-most node
        offset = LEFT(left_most_node);
    } else
        offset = 0;


    int i = 0;
    for (int j = offset; j != tree_size; ++i, ++j) {
        std::cin >> val;
        b[j] = node {val, i, i, 1, false};
    }

    for (int j = 0; i != n; ++i, ++j) {
        std::cin >> x;
        b[n - 1 + j] = node {x, i, i, 1, false};
    }

    // set internal nodes
    for (int j = (int) tree_size - 1; j != 0; j -= 2) {
        b[PARENT(j)] = node {INT_MIN, b[j-1].left, b[j].right,
                             b[j-1].size_sub_tree+b[j].size_sub_tree, true};
    }


    for (int j=0; j<m; ++j) {
        int type;
        std::cin >> type;
        if (type == 1) {
            //copy
            std::cin >> x >> y >> k;
            copy(b, x, y, y+k-1);
        } else {
            //access
            std::cin >> x;
            access(b, a, x);
        }
    }

    return 0;
}