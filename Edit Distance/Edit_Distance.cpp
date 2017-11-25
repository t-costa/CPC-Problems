#include <iostream>


int min(int a, int b, int c) {
    if (a < b)
        return std::min(a, c);
    return std::min(b, c);
}

int edit(std::string const& s1, std::string const& s2, int n, int m) {

    int matrix[n+1][m+1];

    for (int i=0; i<=n; ++i)
        matrix[i][0] = i;

    for (int i=0; i<=m; ++i)
        matrix[0][i] = i;

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            if (s1[i-1] == s2[j-1])
                matrix[i][j] = matrix[i-1][j-1];
            else {
                matrix[i][j] = min(matrix[i-1][j-1],
                                   matrix[i-1][j],
                                   matrix[i][j-1]) + 1;
            }
        }
    }

    return matrix[n][m];
}

int main() {

    int t, n, m;

    std::cin >> t;

    for (int i=0; i<t; ++i) {
        std::string s1, s2;

        std::cin >> n >> m;
        std::cin >> s1 >> s2;

        std::cout << edit(s1, s2, n , m) << std::endl;
    }

    return 0;
}
