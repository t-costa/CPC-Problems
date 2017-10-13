#include <iostream>
#include <vector>
#include <deque>
#include <complex>


struct Node{
    int rank;
    std::vector<int> child;
};

bool checkPrime(int n){
    int i = 3;
    int stop = (int) std::sqrt(n);

    if (n == 2) return true;
    if (n % 2 == 0) return false;

    while (n%i != 0 && i <= stop)
        i += 2;

    return (i > stop);
}

int getCanFire(std::vector<Node>& v, int root){

    int count = 0, depth = 1;
    int test_val, number_children;
    Node current_node;
    std::deque<int> q;

    for (auto index : v[root].child)
        q.push_back(index);

    number_children = (int) v[root].child.size();

    while (!q.empty()) {
        current_node = v[q.front()];
        test_val = v[q.front()].rank + depth;
        if (checkPrime(test_val)) count++;

        q.pop_front();
        number_children--;

        for (auto index : current_node.child)
            q.push_back(index);

        if (number_children == 0) {
            depth++;
            number_children = (int) q.size();
        }
    }

    return count;
}

void initialize(std::vector<Node>& v, int size){
    //capacity may be bigger because of precedent reserve
    for (int i=1; i<=size; ++i)
        v.emplace_back(Node {i});
}

int main() {
    int number_test;
    int n, val, root = 0;
    std::vector<Node> test;
    std::cin >> number_test;

    for (int i=0; i<number_test; ++i){
        std::cin >> n;
        test.reserve(n);

        initialize(test, n);

        for (int j=1; j<=n; ++j){
            std::cin >> val;
            if (val == 0) {
                root = j-1;
                //the values are useless
            } else {
                //I have to save which are the children of the node
                --val;  //to stay between 0 and n
                test[val].child.push_back(j-1);
            }
        }
        
        std::cout << getCanFire(test, root) << std::endl;
        test.clear();
    }

    return 0;
}
