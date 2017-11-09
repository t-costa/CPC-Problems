#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>


struct employee {
    bool visited;
    std::vector<int> languages;
    std::vector<int> edges;
};


void bfs(std::vector<employee>& g, int index) {

    std::queue<employee*> q;

    q.push(&g[index]);
    g[index].visited = true;

    while (!q.empty()) {
        auto node = q.front();
        for (auto v : node->edges) {
            if (!g[v].visited) {
                g[v].visited = true;
                q.push(&g[v]);
            }
        }
        q.pop();
    }

}

int count_SCC(std::vector<employee>& g) {

    //bfs, every time I have to look for another scc, increment variable

    int scc = 0;

    for (int i=0; i<g.size(); ++i) {
        if (!g[i].visited) {
            scc++;
            bfs(g, i);
        }
    }

    return scc;

}

int main() {

    std::ios_base::sync_with_stdio(false);
    int n, m, k, l;
    std::cin >> n >> m;
    std::vector<employee> employees(n, employee {false, {}, {}});
    std::unordered_map<int, std::vector<int>> lang_dip;

    for (int i=0; i<n; ++i) {
        std::cin >> k;
        if (k > 0) {
            for (int j=0; j<k; ++j){
                std::cin >> l;
                //build graph
                for (auto dip : lang_dip[l]) {
                    employees[dip].edges.push_back(i);
                    employees[i].edges.push_back(dip);
                }
                lang_dip[l].push_back(i);
                employees[i].languages.push_back(l);
            }
        }
    }

    int counter = 0;
    for (auto emp : employees) {
        if (emp.edges.empty()) counter++;
    }
    if (counter == employees.size()){   //all isolated nodes
        int i=0;
        while (i<employees.size()) {
            if (employees[i].languages.empty()) i++;
            else break; //at least one language spoken, teach that to n-1 nodes
        }
        if (i==employees.size())
            std::cout << employees.size() << std::endl;
        else std::cout << employees.size()-1 << std::endl;
        return 0;
    }

    //there is more then one connected component
    std::cout << count_SCC(employees) - 1 << std::endl;

    return 0;
}