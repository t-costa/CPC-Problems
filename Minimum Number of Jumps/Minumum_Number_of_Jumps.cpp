#include <iostream>
#include <vector>


int jump(std::vector<int> const& v) {

    if (v.size() <= 1)
        return 0;

    int max_jump = v[0], jump = 0, pos = 0, total_jump = 0;
    bool end_reached = false;

    while (!end_reached) {

        if (max_jump == 0)
            return -1;

        int max = 0, i = 1;
        while (!end_reached && i <= max_jump) {
            if (pos + i == v.size() - 1)
                end_reached = true;
            else {
                if (v[pos+i] > max) {
                    max = v[pos+i];
                    jump = i;
                }
            }
            i++;
        }

        if (max > 0)
            total_jump++;
        else
            return -1;

        if (!end_reached) {
            pos += jump;
            max_jump = v[pos];
        }
    }

    return total_jump;
}

int main() {

    int t, n;
    std::cin >> t;

    for (int i=0; i<t; ++i) {
        std::cin >> n;
        std::vector<int> v;
        v.reserve((size_t) n);

        for (int j=0; j<n; ++j) {
            int val;
            std::cin >> val;
            v.push_back(val);
        }

        std::cout << jump(v) << std::endl;
    }

    return 0;
}
