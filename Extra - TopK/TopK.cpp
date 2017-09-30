#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <assert.h>


void print_values(std::vector<int>& v){
    for (auto el : v)
        std::cout << el << " ";
    std::cout << std::endl;
}

struct compare
{
    bool operator()(const int& l, const int& r)
    {
        return l > r;
    }
};

void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(std::vector<int>& v, int left, int right){
    int pivot = v[right];

    while ( left < right ) {
        while (v[left] < pivot)
            left++;

        while (v[right] > pivot)
            right--;

        if (v[left] == v[right])
            left++;
        else if (left < right) {
            swap(v[left], v[right]);
        }
    }
    return right;
}



void unsorted_top_k(std::vector<int>& v, int k, int left, int right, std::vector<int>& acc){

    if (k > 0) {
        //go on
        int pos = partition(v, left, right);    //position of pivot
        if (right - pos <= k) {
            for (int i=right; (i>=pos && k>0); --i){
                acc.push_back(v[i]);
                k--;
            }
            if (k == 0) {
                std::cout << "Unsorted top k: " << " ";
                print_values(acc);
                return;
            }
            unsorted_top_k(v, k, left, pos-1, acc);
        } else unsorted_top_k(v, k, std::min(pos+1, right), std::max(pos+1, right), acc);
    }
}

std::vector<int> sorted_top_k(std::vector<int>& v, int k){
    std::priority_queue<int, std::vector<int>, compare> queue;

    for (auto el : v){
        if (queue.size() < k) queue.push(el);
        else if (el > queue.top()) {
            //the new element is greater than the minimum in the queue
            queue.pop();
            queue.push(el);
        }
        //else the new element is smaller of my k elements
    }

    std::vector<int> top;
    top.reserve(k);

    std::cout << "Sorted top k: " << " ";
    while (!queue.empty()){
        std::cout << queue.top() << " ";
        top.push_back(queue.top());
        queue.pop();
    }
    std::cout << std::endl;

    return top;
}


int main() {

    int val, size, k;
    std::cin >> size;
    std::cin >> k;
    std::vector<int> test;
    std::vector<int> test2;
    test.reserve(size);
    test2.reserve(size);

    srand (time(nullptr));
    //random input just to test the functions
    for (int i=0; i<size; ++i){
        val = std::rand()%1000;
        test.push_back(val);
        test2.push_back(val);
    }

    std::cout << "Test: " << " ";
    print_values(test);

    std::vector<int> acc;
    acc.reserve(k);
    
    unsorted_top_k(test, k, 0, test.size()-1, acc); //test is modified
    std::vector<int> top = sorted_top_k(test2, k);
    
    std::sort(acc.begin(), acc.end());  //just for the assert function below

    assert (std::equal(acc.begin(), acc.end(), top.begin()));

    return 0;
}
