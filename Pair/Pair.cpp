#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

//with just long the code fails on the tests of http://codeforces.com/problemset/problem/160/C

void find_pair(long long int n, long long int k, std::vector<long long>& v){

    long long pos_first = (k-1)/n;
    long long r, l;
    long long i = pos_first;

    std::sort(v.begin(), v.end());

    while (i >= 0 && v[i] == v[pos_first])
        --i;
    l = (++i);

    while (i<n && v[i] == v[pos_first])
        ++i;
    r = i - l;

    long long pos_second = ((k - 1) - l*n) / r;  //ref: solution on the course page

    std::cout << v[pos_first] << " " << v[pos_second] << std::endl;

}

int main() {

    long long int n, k, val;
    std::cin >> n;
    std::vector<long long> test;
    test.reserve(n);
    std::cin >> k;

    for (long long i=0; i<n; i++){
        std::cin >> val;
        test.emplace_back(val);
    }

    find_pair(n, k, test);

    return 0;
}