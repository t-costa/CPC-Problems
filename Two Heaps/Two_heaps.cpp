#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


struct couple {
    short value;
    short index;
};

bool compare(couple a, couple b){
    return a.value < b.value;
}

void play(std::vector<couple>& v){

    std::vector<short> final(v.size(), 0);   //initialized to zero
    int max_combo;
    int distinct = 0;
    bool duplicated = false;
    short last = -1;
    short pos = 1;

    std::sort(v.begin(), v.end(), compare);

    for (short i = 0; i<v.size(); ++i){
        if (last == v[i].value){
            if (!duplicated) {  //just a couple, it's ok
                final[v[i].index] = pos;
                distinct++;
                duplicated = true;
                pos = (pos % 2) + 1;
            }
        } else {
            duplicated = false;
            distinct++;
            final[v[i].index] = pos;
            pos = (pos % 2) + 1;
        }
        last = v[i].value;
    }
    for (short i = 0; i<v.size(); ++i){
        if (final[v[i].index] == 0) {
            //set it
            final[v[i].index] = pos;
            pos = (pos % 2) + 1;
        }
        //else it has already be set before
    }
    //looking for the biggest product
    //if (distinct % 2 == 0) max_combo = (distinct / 2) * (distinct / 2);
    //else max_combo = (distinct / 2) * ((distinct + 1)/ 2);
    //   ^   they are equivalent   v
    max_combo = (distinct / 2) * (distinct - distinct / 2);
    std::cout << max_combo << std::endl;
    
    for (auto el : final)
        std::cout << el << " ";
    std::cout << std::endl;
}


int main() {
    short n, val;
    std::cin >> n;
    short size = 2*n;
    std::vector<couple> test;
    test.reserve(size);

    for (short i=0; i<size; ++i){
        std::cin >> val;
        test.emplace_back(couple{ val, i });
    }

    play(test);

    return 0;
}
