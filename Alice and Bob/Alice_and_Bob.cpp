#include <iostream>
#include <vector>


void consume(std::vector<int>::iterator start, std::vector<int>::iterator end){
    int alice = 0, bob = 0;
    int alice_counter = 0, bob_counter = 0;

    while (start <= end){
        if (alice + *start <= bob + *end) {
            alice += *start;
            start++;
            alice_counter++;
        } else {
            bob += *end;
            end--;
            bob_counter++;
        }
    }

    std::cout << alice_counter << " " << bob_counter << std::endl;
}

int main() {
    int n;
    std::vector<int> chocolate;
    std::cin >> n;
    chocolate.reserve(n);

    for (int i=0; i<n; ++i){
        int val;
        std::cin >> val;
        chocolate.push_back(val);
    }

    consume(chocolate.begin(), chocolate.end()-1);

    return 0;
}
