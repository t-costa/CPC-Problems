#include <iostream>
#include <vector>
#include <stack>


std::vector<int> getArrayInput(){
    int size;
    std::cin >> size;
    std::vector<int> v(size);

    for(int i=0; i<size; i++){
        std::cin >> v[i];
    }
    return v;
}

void printLeaders(std::vector<int> v){
    int max = -1;
    std::deque<int> leader;

    for(int i = v.size()-1; i >= 0; i--){
        if (v[i] > max) {
            max = v[i];
            leader.push_front(max);
        }
    }

    while (!leader.empty()){
        std::cout << leader.front() << ' ';
        leader.pop_front();
    }
    std::cout << std::endl;
}

int main() {

    int numberTest;
    std::cin >> numberTest;
    std::vector<std::vector<int>> test(numberTest);

    for (int i=0; i<numberTest; i++){
        test[i] = getArrayInput();
    }

    for (auto v : test)
        printLeaders(v);

    return 0;
}
