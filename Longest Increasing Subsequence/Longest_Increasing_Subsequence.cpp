#include <iostream>
#include <vector>
#include <deque>


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

int binary_search(std::vector<int> const& v, int l, int r, int key) {

    while (r-l > 1) {
        int m = l + (r-l)/2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

int optimized_lis(std::vector<int> const& s) {

    std::vector<int> lis;
    lis.reserve(s.size());

    lis.push_back(s[0]);
    int length = 1;
    for (int i=1; i<s.size(); ++i) {
        if (s[i] < lis.front()) {
            //new smallest element
            lis.front() = s[i];
        } else {
            if (s[i] > lis.back()) {
                //biggest element increase longest sequence
                lis.push_back(s[i]);
                length++;
            } else {
                //element in the middle, search right position
                int index = binary_search(lis, -1, length-1, s[i]);
                lis[index] = s[i];
            }
        }
    }

    return length;

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
            std::cout << optimized_lis(s) << std::endl;
        else
            std::cout << 0 << std::endl;
    }

    return 0;
}
