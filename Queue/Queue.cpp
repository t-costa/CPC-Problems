#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> generate_heights(std::vector<std::pair<std::string, int>> const& v) {
    std::vector<int> heights(v.size());

    for (size_t i=0; i<v.size(); ++i) {
        int len = (int) i - v[i].second;
        if (len < 0) {
            //not possible
            heights.clear();
            return heights;
        }
        heights[i] = len+1;
        for (size_t j=0; j<i; ++j) {
            if (heights[j] >= heights[i])
                heights[j]++;   //adjust values
        }
    }

    return heights;
}

int main() {

    std::vector<std::pair<std::string, int>> clients;
    std::string s;
    int v;
    size_t n;
    std::cin >> n;

    clients.reserve(n);

    for (size_t i=0; i<n; ++i) {
        std::cin >> s >> v;
        clients.emplace_back(s, v);
    }

    std::sort(clients.begin(), clients.end(),
              [](std::pair<std::string, int> const& a,
                 std::pair<std::string, int> const& b) -> bool {
                  return (a.second < b.second);
              });

    std::vector<int> heights = generate_heights(clients);

    if (heights.empty()) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    for (size_t i=0; i<n; ++i)
        std::cout << clients[i].first << " " << heights[i] << std::endl;

    return 0;
}
