#include <iostream>
#include <vector>
#include <algorithm>


struct edge {
    int u;
    int v;
    int w;
};

class Disjoint_Set {

private:
    struct element {
        int parent;
        int rank;
    };

    std::vector<element> set;

    int size;

    void link(int x, int y) {
        if (set[x].rank > set[y].rank)
            set[y].parent = x;
        else {
            set[x].parent = y;
            if (set[x].rank == set[y].rank)
                set[y].rank++;
        }
    }

public:
    explicit Disjoint_Set (size_t n) {
        set.reserve(n);

        //initialize set
        for (size_t i=0; i<n; ++i)
            set.emplace_back(element {-1, -1});

        size = (int) n;
    };

    void make_set(int x) {
        if (set[x].parent == -1) {
            set[x].parent = x;
            set[x].rank = 0;
        }
        //otherwise already set
    }

    int find_set(int x) {
        if (x != set[x].parent)
            set[x].parent = find_set(set[x].parent);
        return set[x].parent;
    }

    void unify(int x, int y) {
        int x1 = find_set(x);
        int y1 = find_set(y);

        if (x1 != y1) {
            link(x1, y1);
            size--;
        }
    }

    int get_size() {
        return size;
    }
};

int main() {

    int n, m;
    int u, v, w;
    std::cin >> n >> m;
    std::vector<edge> graph;
    Disjoint_Set set((size_t) n);

    graph.reserve((size_t) m);

    for (int i=0; i<m; ++i) {
        std::cin >> u >> v >> w;
        u--;
        v--;
        graph.emplace_back(edge {u, v, w});
        set.make_set(u);
        set.make_set(v);
    }

    std::sort(graph.begin(), graph.end(),
              [](edge const& a, edge const& b) -> bool {
                  return (a.w < b.w);
                });

    int i=0;
    int64_t weight = 0;

    while (i < m) {
        if (set.find_set(graph[i].u) != set.find_set(graph[i].v)) {
            //edge can be taken
            weight += graph[i].w;
            set.unify(graph[i].u, graph[i].v);
            if (set.get_size() == 1)
                break;  //I have the mst
        }
        i++;
    }

    std::cout << weight << std::endl;

    return 0;
}
