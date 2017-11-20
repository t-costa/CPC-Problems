#include <iostream>
#include <vector>
#include <algorithm>

struct meeting{
    int start;
    int finish;
    int index;
};

void number_meetings(std::vector<meeting> const& v) {

    int last = -1;

    //take the first feasible meeting
    for (auto el : v) {
        if (el.start > last) {
            std::cout << el.index << " ";
            last = el.finish;
        }
    }
    std::cout << std::endl;
}

int main() {

    int t, n, s, f;
    std::vector<meeting> time;

    std::cin >> t;

    for (int i=0; i<t; ++i) {
        std::cin >> n;
        time.reserve((size_t) n);

        for (int j=0; j<n; ++j) {
            std::cin >> s;
            time.emplace_back(meeting {s, 0, j+1});
        }
        for (int j=0; j<n; ++j) {
            std::cin >> f;
            time[j].finish = f;
        }

        //sort finishing time in increasing order
        std::sort(time.begin(), time.end(),
                  [](meeting const& a, meeting const& b) -> bool {
                        return (a.finish < b.finish);
        });

        number_meetings(time);

        time.clear();
    }

    return 0;
}