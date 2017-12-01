#include <iostream>
#include <vector>


int knapsack(std::vector<int> const& v, std::vector<int> const& w, int W) {

    int matrix[101][101];

    //matrix[values][weight]

    for (int i=0; i<=W; ++i) 
        matrix[0][i] = 0;

    //v and w starts from 0
    for (int i=1; i<=v.size(); ++i) {
        for (int j=0; j<=W; ++j) {
            if (w[i-1] > j)
                matrix[i][j] = matrix[i-1][j];
            else
                matrix[i][j] = std::max(matrix[i-1][j], matrix[i-1][j-w[i-1]] + v[i-1]);
        }
    }

    return matrix[v.size()][W];
}

int main() {

    std::ios_base::sync_with_stdio(false);
    int t, n, w_max;
    std::cin >> t;

    for (int i=0; i<t; ++i) {
        std::vector<int> v;
        std::vector<int> w;

        std::cin >> n >> w_max;

        v.reserve((size_t) n);
        v.reserve((size_t) n);

        for (int j=0; j<n; ++j) {
            int val;
            std::cin >> val;
            v.push_back(val);
        }

        for (int j=0; j<n; ++j) {
            int weight;
            std::cin >> weight;
            w.push_back(weight);
        }

        std::cout << knapsack(v, w, w_max) << std::endl;
    }

    return 0;
}
