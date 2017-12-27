#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_map>


std::vector<std::pair<int, int>> build(std::vector<int>& deg, std::vector<int>& sum) {

    std::vector<std::pair<int, int>> edges;
    std::deque<int> leaf;
    edges.reserve(deg.size());

    for (int i=0; i<deg.size(); ++i)
        if (deg[i] == 1)
            leaf.push_back(i);

    while (!leaf.empty()) {
        int i = leaf.front();

        if (deg[i] == 0) {
            //edges added before
            leaf.pop_front();
            continue;
        }

        edges.emplace_back(i, sum[i]);
        //decrement sum of pointed node by my value
        sum[sum[i]] ^= i;
        //decrement degree of pointed node and myself
        deg[sum[i]]--;

        if (deg[sum[i]] == 1){
            //new leaf
            leaf.push_back(sum[i]);
        }

        leaf.pop_front();
    }

    return edges;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    int n, d, s;

    std::cin >> n;

    std::vector<int> degree;
    std::vector<int> sum;
    degree.reserve((size_t) n);
    sum.reserve((size_t) n);

    for (int i=0; i<n; ++i) {
        std::cin >> d >> s;
        degree.push_back(d);
        sum.push_back(s);
    }

    auto v = build(degree, sum);

    std::cout << v.size() << std::endl;

    for (auto c : v)
        std::cout << c.first << " " << c.second << "\n";

    return 0;
}
