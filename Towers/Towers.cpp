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
    int max = 1;

    for (int i=0; i<size; i++){
        std::cin >> val;
        if (table.find(val) == table.end()){
            table.emplace(val, 1);
            total++;
        } else {
            table[val]++;
            if (table[val] > max) max = table[val];
        }
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
