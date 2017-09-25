#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <map>
#include <unordered_map>


void towers(std::vector<int> v){
    std::unordered_map<int, int> table;
    int max = 1;
    int total = 0;

    for (int i=0; i<v.size(); i++){
        if (table.find(v[i]) == table.end()){
            table.emplace(v[i], 1); //inserisco per la prima volta
            total++;
        } else {
            table[v[i]]++;
            if (table[v[i]] > max)
                max = table[v[i]];
        }
    }

    std::cout << max << ' ' << total << std::endl;

}

int main() {

    int size;
    std::cin >> size;
    std::vector<int> test(size);

    for (int i=0; i<size; i++)
        std::cin >> test[i];

    towers(test);

    return 0;
}
