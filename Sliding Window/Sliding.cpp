#include <iostream>
#include <vector>
#include <stack>
#include <tuple>


std::pair<std::vector<int>, int> getArrayInput(){
    int size;
    int k;
    std::cin >> size >> k;
    std::vector<int> v(size);

    for(int i=0; i<size; i++){
        std::cin >> v[i];
    }
    return std::make_pair (v, k);
}

void maxWindow(std::vector<int> v, int k){
    std::deque<std::pair<int, int>> q;

    for (int i=0; i<v.size(); i++){

        while (!q.empty() && q.front().second <= i - k)
            q.pop_front();

        while (!q.empty() && q.back().first <= v[i])
            q.pop_back();

        q.push_back(std::make_pair(v[i], i));

        if (i >= k-1) std::cout << q.front().first << ' ';

    }

    std::cout << std::endl;
}

int main() {

    int numberTest;
    std::cin >> numberTest;
    std::vector<std::vector<int>> test(numberTest);
    std::vector<int> k(numberTest);

    for (int i=0; i<numberTest; i++){
        std::tie (test[i], k[i]) = getArrayInput();
    }

    for (int i=0; i<numberTest; i++)
        maxWindow(test[i], k[i]);

    return 0;
}