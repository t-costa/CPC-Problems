#include <iostream>


int lcs(std::string const& s1, std::string const& s2, int n, int m) {

    int matrix[101][101];

    for (int i=0; i<=n; ++i) 
        matrix[i][0] = 0;
    
    for (int i=0; i<=m; ++i) 
        matrix[0][i] = 0;

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            if (s1[i-1] == s2[j-1])
                matrix[i][j] = matrix[i-1][j-1]+1;
            else
                matrix[i][j] = std::max(matrix[i-1][j], matrix[i][j-1]);
        }
    }

    return matrix[n][m];
}

int main() {

    std::ios_base::sync_with_stdio(false);
    int t, n, m;
    std::cin >> t;

    for (int i=0; i<t; ++i) {
        std::cin >> n >> m;
        std::string s1, s2;
        std::cin >> s1 >> s2;

        std::cout << lcs(s1, s2, n, m) << std::endl;
    }

    return 0;
}
