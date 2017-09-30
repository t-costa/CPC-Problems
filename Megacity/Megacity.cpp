#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <math.h>

#define N 1000000

bool compare (std::pair<double, int> a, std::pair<double, int> b){
    return (a.first < b.first);
}

void megacity(std::vector<std::pair<double, int>>& v, int people){

    int missing = N - people;
    if (missing <= 0) {
        std::cout << "0" << std::endl;
        return;
    }

    std::sort(v.begin(), v.end(), compare); //TODO: CHECK

    std::vector<std::pair<double, int>>::iterator iter;
    double radius = 0;
    iter = v.begin();
    while (iter != v.end() && missing > 0){
        //std::get<0>(v[0]);
        radius = std::get<0>(*iter.base());
        missing -= std::get<1>(*iter.base());
        iter++;
    }

    if (missing <= 0) {
        std::cout.precision(8);
        std::cout << radius << std::endl;
    } else std::cout << "-1\n"; //not reach N



}

int main() {

    int size, people, x, y, k;
    double r;
    std::cin >> size;
    std::vector<std::pair<double, int>> test;
    test.reserve(size);
    std::cin >> people;

    for (int i=0; i<size; i++){

        std::cin >> x;              //x coordinate
        std::cin >> y;              //y coordinate
        std::cin >> k;              //number inhabitants
        r = std::sqrt(x*x + y*y);   //radius location
        test.emplace_back(r, k);
    }

    megacity(test, people);

    return 0;
}