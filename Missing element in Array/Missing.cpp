#include <iostream>
#include <vector>


std::vector<int> getArrayInput(){
    int size;
    std::cin >> size;
    std::vector<int> v(size - 1);   //il secondo input è il numero totale di elementi

    for(int i=0; i<v.size(); i++){
        std::cin >> v[i];
    }
    return v;
}

void missingNumber(std::vector<int> v){
    int totalSum = (v.size() + 1) * (v.size() + 2) / 2;
    int sumVector = 0;

    for (int i=0; i<v.size(); i++){
        sumVector += v[i];
    }

    std::cout << totalSum - sumVector << std::endl;
}

int main() {

    int numberTest;
    std::cin >> numberTest;
    std::vector<std::vector<int>> test(numberTest);

    for (int i=0; i<numberTest; i++){
        test[i] = getArrayInput();
    }

    for (auto v : test)
        missingNumber(v);

    return 0;
}