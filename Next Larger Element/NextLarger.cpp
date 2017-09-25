#include <iostream>
#include <vector>
#include <stack>
#include <tuple>


std::vector<int> getArrayInput(){
    int size;
    std::cin >> size;
    std::vector<int> v(size);

    for(int i=0; i<size; i++)
        std::cin >> v[i];

    return v;
}

void nextLarger(std::vector<int> v){
    //forse dato che fai solo back puoi usare una coda semplice
    std::deque<std::pair<int, int>> q;
    std::vector<int> largest(v.size());

    for (int i=0; i<v.size(); i++){
        while (!q.empty() && q.back().first <= v[i]){
            largest[q.back().second] = v[i];
            q.pop_back();
        }

        q.push_back(std::make_pair(v[i], i));
    }

    for(auto el : q){
        largest[el.second] = -1;
    }

    for(int n : largest)
        std::cout << n << ' ';
    std::cout << std::endl;

}

int main() {

    int numberTest;
    std::cin >> numberTest;
    std::vector<std::vector<int>> test(numberTest);

    for (int i=0; i<numberTest; i++){
        test[i] = getArrayInput();
    }

    for (int i=0; i<numberTest; i++)
        nextLarger(test[i]);

    return 0;
}