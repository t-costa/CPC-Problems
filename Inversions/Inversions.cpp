#include <iostream>
#include <vector>


long long countInversion = 0;

void merge(std::vector<long long>& v, unsigned int left, unsigned int right){

    unsigned int center = (left + right) / 2;
    unsigned int i = left;
    unsigned int j = center + 1;
    unsigned int swapped = 0;
    std::vector<long long> aux;
    aux.reserve(right - left + 1);

    while (i <= center && j <= right){
        if (v[i] > v[j]) {
            //inversion
            countInversion += j-i-swapped;
            swapped++;	//avoid counting multiple times the same inversion
            aux.push_back(v[j]);
            j++;
        } else {
            //the element follows the order
            aux.push_back(v[i]);
            i++;
        }
    }

    if (swapped > 0) {
	//there has been a modification
        while (i <= center){
            aux.push_back(v[i]);
            i++;
        }

        while (j <= right){
            aux.push_back(v[j]);
            j++;
        }

	//report the modification to the original array
        for (int val : aux){
            v[left] = val;
            left++;
        }
    }
    //else the array has not been modified
}

void count(std::vector<long long>& v, unsigned int left, unsigned int right){
    //basically merge sort
    if (left < right){
        count(v, left, (left + right)/2);
        count(v, (left + right)/2 + 1, right);
        merge(v, left, right);
    }

    //true only at the end of all the recursion calls
    if (left == 0 && right == v.size() - 1){
        std::cout << countInversion << std::endl;
        countInversion = 0;	//many test cases
    }

}

int main() {

    long long val;
    unsigned int numberTest, size;
    std::vector<long long> test;
    std::cin >> numberTest;

    for (unsigned int i=0; i<numberTest; ++i){
        std::cin >> size;
        test.reserve(size);

        for (unsigned int j=0; j<size; j++) {
            std::cin >> val;
            test.push_back(val);
        }

        count(test, 0, test.size()-1);
        
        test.clear();
    }

    return 0;
}
