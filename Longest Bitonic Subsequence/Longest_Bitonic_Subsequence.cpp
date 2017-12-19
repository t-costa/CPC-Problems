#include <iostream>
#include <algorithm>
#include <vector>


std::vector<int> lis(std::vector<int> const& s) {

    std::vector<int> lis;
    lis.reserve(s.size());

    lis.push_back(1);   //first sequence is just the first element

    for (int i=1; i<s.size(); ++i) {
        int j = 0, max = 0;
        while (j < i) {
            if (lis[j] > max && s[j] < s[i])
                max = lis[j];
            ++j;
        }
        lis.push_back(max+1);   //if there is no j s.t. lis[j]>max, max is 0 -> ok
    }


    return lis;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    int num_test, n, val;
    std::cin >> num_test;

    while (num_test--) {
        std::vector<int> s;
        std::cin >> n;
        s.reserve((size_t) n);

        for (int i=0; i<n; ++i) {
            std::cin >> val;
            s.push_back(val);
        }

        std::vector<int> inc = lis(s);

        std::reverse(s.begin(), s.end());
        std::vector<int> dec = lis(s);
        
        std::reverse(dec.begin(), dec.end());

        int max = inc[0] + dec[0];
        for (int i=1; i<inc.size(); ++i) {
            if (inc[i] + dec[i] > max)
                max = inc[i] + dec[i];
        }
        std::cout << max - 1 << std::endl;

    }

    return 0;
}
