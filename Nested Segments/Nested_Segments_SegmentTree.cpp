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
    size_t pos;
};

template <class T>
struct segment_tree {

private:
    struct node {
        T val;
        int left;
        int right;
        int div;
    };

    std::vector<node> tree;

public:

    explicit segment_tree(size_t n) {
        size_t tree_size = 2 * n - 1;
        tree.resize(tree_size);

        auto h = (int) ceil(log2(n));
        int i = 0;

        if (1<<h == n) {
            //n is already a power of 2
            for (size_t j=tree_size-1; i<n; ++i, --j)
                tree[j] = node {0, i, i, i};

        } else {
            int num_last_level = (int) tree_size - (int) std::pow(2, h) + 1;
            int first = std::max((int) std::pow(2, h)-2, 2);    //for 3 elements

            for (int j = first; i < n-num_last_level; ++i, --j)
                tree[j] = node {0, i, i, i};


            for (int j = (int) tree_size-1; i != n; ++i, --j)
                tree[j] = node {0, i, i, i};
        }

        // set internal nodes
        for (int j = (int) tree_size-1; j != 0; j -= 2)
            tree[PARENT(j)] = node {0, tree[j].left, tree[j-1].right,
                                    tree[j-1].left};

    }

    T get_val(int start, int query, T acc) {

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
            return get_val(RIGHT(start), query, acc);
        } else {
            //go left, don't update acc
            tree[start].val++;
            return get_val(LEFT(start), query, acc);
        }
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


void solve(std::vector<segment> const& segments, segment_tree<int>& tree) {

    std::vector<int> res(segments.size());

    for (auto s : segments)
        res[s.pos] = tree.get_val(0, s.right, 0);

    for (auto r : res)
        std::cout << r << std::endl;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    size_t n;
    int l, r;
    std::cin >> n;

    segment_tree<int> tree(n);

    std::vector<segment> segments;
    segments.reserve(n);

    for (size_t i=0; i<n; ++i) {
        std::cin >> l >> r;
        segments.emplace_back(segment {l, r, i});
    }

    //sort and remap
    rearrange(segments);

    solve(segments, tree);

    return 0;
}
