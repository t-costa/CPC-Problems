#include <iostream>
#include <vector>


std::vector<int> build_prefix_sum(std::string s){
    std::vector<int> v(s.size(), 0);
    int i = 0;

    for (i = 1; i<s.size(); ++i){
        if (s[i] == s[i-1]) v[i] = v[i-1]+1;
        else v[i] = v[i-1];
    }

    return v;
}

int answer_query(std::vector<int> const& v, int l, int r){
    l--;
    r--;
    return v[r] - v[l];
}

int main() {
    int n;
    std::string s;
    std::cin >> s;
    std::vector<int> prefix = build_prefix_sum(s);

    std::cin >> n;

    for (int j=0; j<n; ++j){
        int left, right;
        std::cin >> left;
        std::cin >> right;

        std::cout << answer_query(prefix, left, right) << std::endl;
    }

    return 0;
}
