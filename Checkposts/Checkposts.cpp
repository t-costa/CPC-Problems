#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


struct node{
    bool visited;
    int64_t cost;
    std::vector<node*> edges;
    std::vector<node*> transposed_edges;
};

void dfs_visit(node* n, std::stack<node*>& stack) {

    n->visited = true;
    for (auto& v : n->edges)
        if (!v->visited)
            dfs_visit(v, stack);
    stack.push(n);
}

void dfs(std::vector<node>& g, std::stack<node*>& stack) {

    for (auto& v : g)
        if (!v.visited)
            dfs_visit(&v, stack);

}

void dfs_visit(node* n, int64_t& min_cost, int64_t& occ) {

    n->visited = true;
    for (auto v : n->transposed_edges)
        if (!v->visited) {
            if (v->cost < min_cost) {
                min_cost = v->cost;
                occ = 1;
            } else
                if (v->cost == min_cost)
                    occ++;

            dfs_visit(v, min_cost, occ);
        }
}

void dfs_transposed(std::vector<node>* g, std::stack<node*>& stack) {

    for (auto& v : *g)
        v.visited = false;

    int64_t total_cost = 0, min_cost = 0;
    int64_t possibilities = 1, occ;

    while (!stack.empty()) {
        auto v = stack.top();
        stack.pop();
        if (!v->visited) {
            min_cost = v->cost;
            occ = 1;
            dfs_visit(v, min_cost, occ);
            total_cost += min_cost;
            possibilities *= occ;
        }
    }

    std::cout << total_cost << " " << possibilities % 1000000007 << std::endl;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    size_t n, m, u, v;
    int64_t cost;
    std::vector<node> graph;
    std::stack<node*> stack;
    std::cin >> n;
    graph.reserve(n);

    for (auto i=0; i<n; ++i){
        std::cin >> cost;
        graph.emplace_back(node { false, cost, {}, {}});
    }

    std::cin >> m;

    for (auto i=0; i<m; ++i) {
        std::cin >> u >> v;
        u--;
        v--;
        graph[u].edges.push_back(&graph[v]);
        graph[v].transposed_edges.push_back(&graph[u]);
    }

    dfs(graph, stack);

    dfs_transposed(&graph, stack);

    return 0;
}