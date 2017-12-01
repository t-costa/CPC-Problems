#include <iostream>
#include <vector>


int lis(std::vector<int> const& s) {

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

    int max = 0;
    for (auto m : lis)
        if (m > max)
            max = m;

    return max;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    int n, t;
    std::cin >> t;

    for (int i=0; i<t; ++i) {
        std::cin >> n;
        std::vector<int> s;
        s.reserve((size_t) n);

        for (int j=0; j<n; ++j) {
            int val;
            std::cin >> val;
            s.push_back(val);
        }
        
        if (n > 0)
            std::cout << lis(s) << std::endl;
        else
            std::cout << 0 << std::endl;
    }

    return 0;
}
