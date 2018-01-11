#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

struct node {
    uint32_t value;
    std::vector<size_t> children;
    size_t size;
    size_t index_flat;
    bool visited_size;
    bool visited_build;
};

struct flat_node {
    uint32_t value;
    size_t size;
};

struct query {
    uint32_t val;
    size_t start;
    size_t end;
    size_t index;
};

std::vector<node> test;
std::vector<query> queries;
std::unordered_map<uint32_t, uint32_t> map_cnt;
std::unordered_map<uint32_t, uint32_t> map_res;
uint32_t res[100001];
size_t sqn;
size_t index_flat = 0;

void build_tree(node& n ,std::vector<flat_node>& tree) {

    if (n.visited_build)
        return;

    tree.emplace_back(flat_node {n.value, n.size});
    n.index_flat = index_flat;
    index_flat++;

    n.visited_build = true;

    for (auto c : n.children)
        build_tree(test[c], tree);
}

size_t get_size(node& n) {

    if (n.visited_size)
        return 0;

    n.visited_size = true;

    for (auto c : n.children)
        n.size += get_size(test[c]);

    return n.size;
}

void add_node(uint32_t val) {
    map_cnt[val]++;
    map_res[map_cnt[val]]++;
}

void remove_node(uint32_t val) {
    map_res[map_cnt[val]]--;
    map_cnt[val]--;
}

void solve(std::vector<flat_node> const& tree) {

    size_t last_start = 0;
    size_t last_stop = 0;

    for (auto q : queries) {

        size_t start = q.start;
        size_t stop = q.end;

        while (last_start < start) {
            //remove elements currently not included
            remove_node(tree[last_start].value);
            last_start++;
        }

        while (last_start > start) {
            //add elements previously not included
            add_node(tree[--last_start].value);
        }

        while (last_stop < stop) {
            //add elements previously not included
            add_node(tree[last_stop].value);
            last_stop++;
        }

        while (stop < last_stop) {
            //remove elements currently not included
            remove_node(tree[--last_stop].value);
        }

        res[q.index] = map_res[q.val];
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::size_t n, m, l, r;
    uint32_t val;

    std::cin >> n >> m;
    test.reserve(n);
    queries.reserve(m);

    sqn = (size_t) (std::sqrt(n) + 1);

    for (size_t i=0; i<n; ++i) {
        std::cin >> val;
        test.emplace_back(node {val, {}, 1, 0, false, false});
    }

    for (size_t i=1; i<n; ++i) {
        //n-1 lines
        std::cin >> l >> r;
        //l and r go from 1 to n
        --l;
        --r;
        test[l].children.push_back(r);
        test[r].children.push_back(l);
    }

    std::vector<flat_node> tree;
    tree.reserve(n);

    get_size(test[0]);

    build_tree(test[0], tree);

    for (size_t i=0; i<m; ++i){
        std::cin >> l >> val;
        //l goes from 1 to n
        --l;
        queries.emplace_back(query {val, test[l].index_flat,
                                    test[l].index_flat + tree[test[l].index_flat].size, i});
    }

    std::sort(queries.begin(), queries.end(),
              [](query const& a, query const& b) -> bool {
                  if (a.start/sqn != b.start/sqn)
                      return a.start/sqn < b.start/sqn;
                  return (a.end < b.end);
              });

    solve(tree);

    for (size_t j=0; j<m; ++j)
        std::cout << res[j] << "\n";
    
    return 0;
}
