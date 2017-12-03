#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>


bool sub_sum(std::vector<int> const& set, int sum) {

    //check if it is possible to sum to exactly half the total sum

    char m[set.size()+1][sum+1];

    for (int i=0; i<=sum; ++i)
        m[0][i] = 0;

    for (int i=0; i<=set.size(); ++i)
        m[i][0] = 1;

    for (int i=1; i<=set.size(); ++i) {
        for (int j=1; j<=sum; ++j) {
            int back = j - set[i-1];

            if (m[i-1][j])
                m[i][j] = 1;
            else
                m[i][j] = 0;

            if (back >= 0) {
                if (m[i-1][back])
                    m[i][j] = 1;
            }
        }
    }

    return m[set.size()][sum];

}

int main() {

    std::ios_base::sync_with_stdio(false);
    int num_test, n, val, sum = 0;

    std::cin >> num_test;

    while (num_test--) {
        std::vector<int> set;
        std::cin >> n;

        set.reserve((size_t) n);

        for (int i=0; i<n; ++i) {
            std::cin >> val;
            set.push_back(val);
            sum += val;
        }


        if (sum % 2 == 1)
            std::cout << "NO" << std::endl;
        else {
            sum /= 2;
            if (sub_sum(set, sum))
                std::cout << "YES" << std::endl;
            else
                std::cout << "NO" << std::endl;
        }

        sum = 0;
    }

    return 0;
}