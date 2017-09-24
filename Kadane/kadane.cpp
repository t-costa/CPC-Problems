#include <iostream>
#include <vector>
#include <stack>


std::vector<int> getArrayInput(){
    int size;
    std::cin >> size;
    std::vector<int> v(size);

    for(int i=0; i<size; i++)
        std::cin >> v[i];

    return v;
}

void kadane(std::vector<int> v){
    int max = v[0];
    int sumWindow = 0;

    for (int i=0; i<v.size(); i++){
        sumWindow += v[i];
        if (sumWindow > max) max = sumWindow;
        if (sumWindow < 0) sumWindow = 0;
    }

    std::cout << max << std::endl;
}

int main() {

    int numberTest;
    std::cin >> numberTest;
    std::vector<std::vector<int>> test(numberTest);

    for (int i=0; i<numberTest; i++)
        test[i] = getArrayInput();

    for (auto v : test)
        kadane(v);

    return 0;
}