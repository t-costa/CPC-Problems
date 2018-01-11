#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

struct node {
    uint32_t value;
    std::vector<size_t> children;
    size_t index_flat;
    bool visited;
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


size_t build_all(node& n ,std::vector<flat_node>& tree) {
    if (n.visited)
        return 0;

    n.visited = true;

    tree.emplace_back(flat_node {n.value, 1});
    flat_node& node = tree.back();
    n.index_flat = index_flat;
    index_flat++;

    for (auto c : n.children)
        node.size += build_all(test[c], tree);

    return node.size;
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
        test.emplace_back(node {val, {}, 0, false});
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
    
    build_all(test[0], tree);

    for (size_t i=0; i<m; ++i){
        std::cin >> l >> val;
        //l goes from 1 to n
        --l;
        size_t start = test[l].index_flat;
        queries.emplace_back(query {val, start,
                                    start + tree[start].size, i});
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
