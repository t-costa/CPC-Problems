#include <iostream>
#include <vector>
#include <algorithm>

//the tree is complete at right, so the left and right operations are inverted
#define RIGHT(i)    (2 * (i) + 1)
#define LEFT(i)     (2 * (i) + 2)
#define PARENT(i)   (((i) - 1) / 2)

struct segment {
    int left;
    int right;
    int pos;
};

struct node {
    int val;
    int left;
    int right;
    int div;
};


bool compare_left(segment a, segment b) {
    return (a.left > b.left);       //there are no segments that coincide
}

bool compare_right(segment a, segment b) {
    return (a.right < b.right);     //there are no segments that coincide
}

void rearrange(std::vector<segment>& v) {

    std::sort(v.begin(), v.end(), compare_right);

    for (int i=0; i<v.size(); ++i)
        v[i].right = i+1;

    std::sort(v.begin(), v.end(), compare_left);
}

int get_val(std::vector<node>& tree, int start, int query, int acc) {

    //visit the tree recursively, if query>=right I reached the
    //smallest interval that contains the searched interval, take the
    //value stored and than increment it
    if (tree[start].right <= query) {
        acc += tree[start].val;
        tree[start].val++;
        return acc;
    }

	//div is the smallest element in the right subtree
    if (query >= tree[start].div) {
        //go right, it includes all the segments in the left child
        acc += tree[LEFT(start)].val;
        tree[start].val++;
        return get_val(tree, RIGHT(start), query, acc);
    } else {
        //go left, don't update acc
        tree[start].val++;
        return get_val(tree, LEFT(start), query, acc);
    }

}

void solve(std::vector<segment> const& segments, std::vector<node>& tree) {

    std::vector<int> res(segments.size());

    for (auto s : segments)
        res[s.pos] = get_val(tree, 0, s.right, 0);

    for (auto r : res)
        std::cout << r << std::endl;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    int n, l, r;
    std::vector<node> tree;
    std::cin >> n;

    int tree_size = 2 * n - 1;
    tree.resize((size_t) tree_size);

    auto h = (int) ceil(log2(n));

    std::vector<segment> segments;
    segments.reserve((size_t) n);

    for (int i=0; i<n; ++i) {
        std::cin >> l >> r;
        segments.emplace_back(segment {l, r, i});
    }

    //sort and remap
    rearrange(segments);

    int i = 0;

    if ((int) std::pow(2, h) == n) {
        //n is already a power of 2
        for (int j=tree_size-1; i<n; ++i, --j){
            tree[j] = node {0, i+1, i+1, i+1};
        }
    } else {
        int num_last_level = tree_size - (int) std::pow(2, h) + 1;
        int first = std::max((int) std::pow(2, h)-2, 2);    //for 3 elements
        for (int j = first; i < n-num_last_level; ++i, --j) {
            tree[j] = node {0, i+1, i+1, i+1};
        }

        for (int j = tree_size-1; i != n; ++i, --j) {
            tree[j] = node {0, i+1, i+1, i+1};
        }
    }

    // set internal nodes
    for (int j = tree_size-1; j != 0; j -= 2) {
        tree[PARENT(j)] = node {0, tree[j].left, tree[j-1].right, tree[j-1].left};
    }


    solve(segments, tree);

    return 0;
}
