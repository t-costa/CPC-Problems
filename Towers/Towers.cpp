#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <map>
#include <unordered_map>
#include <algorithm>


void towers(int size){
    std::unordered_map<int, int> table;
    table.reserve(size);
    int total = 0;
    int val;

    for (int i=0; i<size; i++){
        std::cin >> val;
        if (table.find(val) == table.end()){
            table.emplace(val, 1);
            total++;
        } else table[val]++;
    }

    int max = 0;    //minimum value is 1
    for (auto it=table.begin(); it!=table.end(); ++it){
        if (it->second > max)
            max = it->second;
    }

    std::cout << max << ' ' << total << std::endl;

}

int main() {

    int size;
    std::cin >> size;
    std::vector<int> test(size);

    towers(size);

    return 0;
}
