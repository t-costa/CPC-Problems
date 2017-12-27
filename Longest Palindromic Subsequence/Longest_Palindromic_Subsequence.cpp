#include <iostream>


int lps(std::string const& s) {

    int m[s.size()][s.size()];

    for (int i=0; i<s.size(); ++i)
        m[i][i] = 1;

    for (int i=1; i<s.size()-1; ++i)
        m[i][i-1] = 0;

    //zig zag filling
    int k = 1, i = 0, j = 1;
    while (k < s.size()) {
        if (s[i] != s[j])
            m[i][j] = std::max(m[i+1][j], m[i][j-1]);
        else
            m[i][j] = m[i+1][j-1] + 2;
        
        i++;
        j++;
        
        if (j == s.size()) {
            k++;
            j = k;
            i = 0;
        }
    }

    return m[0][s.size()-1];
}

int main() {

    std::ios_base::sync_with_stdio(false);
    int num_test;
    std::cin >> num_test;

    while (num_test--) {
        std::string s;
        std::cin >> s;

        std::cout << lps(s) << std::endl;
    }

    return 0;
}
