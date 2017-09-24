#include <iostream>
#include <vector>


std::vector<int> getArrayInput(){
    int size;
    std::cin >> size;
    std::vector<int> v(size);

    for(int i=0; i<size; i++){
        std::cin >> v[i];
    }
    return v;
}

void maxWater(std::vector<int> v){
    int n = v.size();
    std::vector<int> leftMax(n);
    std::vector<int> rightMax(n);
    int trappedWater = 0;

    leftMax[0] = 0;
    for (int i=1; i<n; i++)
        //ogni elemento ha come massimo a sinistra l'elemento subito
        //a sinistra o il massimo trovato finora a sinistra
        leftMax[i] = std::max(leftMax[i-1], v[i-1]);


    rightMax[n-1] = 0;
    for (int i=n-2; i>=0; i--)
        rightMax[i] = std::max(rightMax[i+1], v[i+1]);


    for (int i=0; i<n; i++)
        trappedWater += std::max(std::min(leftMax[i], rightMax[i]) - v[i], 0);

    std::cout << trappedWater << std::endl;
}

int main() {

    int numberTest;
    std::cin >> numberTest;
    std::vector<std::vector<int>> test(numberTest);

    for (int i=0; i<numberTest; i++){
        test[i] = getArrayInput();
    }

    for (auto v : test)
        maxWater(v);

    return 0;
}