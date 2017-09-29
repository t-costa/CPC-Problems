#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <algorithm>


int compare (std::tuple<int, short, short> const& a, std::tuple<int, short, short> const& b) {
    return (std::get<0>(a) > std::get<0>(b));
}

/**
 * n number of elements
 * */
void find_team(std::vector<std::tuple<int, short, short>>& v, int n){
    //sort the elements by value and pick from the largest

    int i = 0, a = 0, b = 0, pair_made = 0;
    std::vector<short> paired(n, 0);

    std::sort(v.begin(), v.end(), compare);

    while (pair_made != n/2){
        a = std::get<1>(v[i]);
        b = std::get<2>(v[i]);
        //the output is from 1 to n
        if (paired[a-1] == 0 && paired[b-1] == 0) {
            paired[a-1] = b;
            paired[b-1] = a;
            pair_made++;
        }
        i++;
    }

    for (auto c : paired)
        std::cout << c << " ";
    std::cout << std::endl;
}

int main() {

    int right = 1, left = 2, val, size;
    std::cin >> size;
    size *= 2;
    std::vector<std::tuple<int, short, short>> test;
    int number_elements = size*(size-1)/2;
    test.reserve(number_elements);

    for (int i=0; i<number_elements; ++i){
        std::cin >> val;
        test.emplace_back(val, left, right);
        if (right == left - 1) {
            //new row
            left++;
            right = 1;
        } else {
            //same row, new column
            right++;
        }
    }

    find_team(test, size);

    return 0;
}