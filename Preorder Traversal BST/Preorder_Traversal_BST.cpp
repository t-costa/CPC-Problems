#include <iostream>
#include <vector>
#include <stack>


struct Element{
    int data;
    int min_val;
    int max_val;
};

bool insert_Right_Child(std::stack<Element>& s, int val){
    bool found = false;
    int min = 0, max = 0;
    while (!found && !s.empty()){
        Element last = s.top();
        min = last.data;
        max = last.max_val;
        if (val > min && val < max)
            found = true;
        s.pop();
    }

    if (found) s.emplace(Element {val, min, max});
    return found;
}

bool check_BST(std::stack<Element>& s){
    int n, val, min = 0, max = 1001;
    Element last;

    std::cin >> n;
    std::cin >> val;
    s.emplace(Element {val, min, max});
    int i = 1;
    while (i < n){
        std::cin >> val;
        last = s.top(); //it's a stack, so it's the last element
        if (val > last.min_val && val < last.max_val) {
            //valid element, check if right or left
            if (val < last.data)
                //valid left child, just insert
                s.emplace(Element {val, last.min_val, last.data});
            else
                //possibly valid right child of an ancestor of last
                if (!insert_Right_Child(s, val)) break;

        } else {
            if (val < last.data) break; //error, outside range
            else
                //possibly valid right child of an ancestor of last
                if (!insert_Right_Child(s, val)) break;
        }
        ++i;
    }
    if (i == n) return true;
    else
        for (; i<n; ++i)
            std::cin >> val;    //consume input

    return false;
}


int main() {
    int number_test;
    std::stack<Element> test;
    std::cin >> number_test;

    for (int i=0; i<number_test; ++i){
        if (check_BST(test)) std::cout << 1 << std::endl;
        else std::cout << 0 << std::endl;

        while (!test.empty())
            test.pop();
    }

    return 0;
}
