#include <iostream>
#include <vector>

int main() {

    int n, val;
    bool last;
    std::vector<bool> v;

    std::cin >> n;
    v.reserve((size_t) n);
    
    getchar();
    for (int i=0; i<n; ++i) {
        val = getchar();
        v.push_back(val==49);   //representation of 1
    }

    //start counting, as soon as you don't increment
    //change the value, and continue change until you CAN increment
    int counter = 1;
    bool start_change = false, has_changed = false;
    last = v[0];
    for (int i=1; i<n; ++i) {
        if (last != v[i]) {
            counter++;
            last = v[i];
            if (start_change)
                has_changed = true;
            //can't change anymore
        }
        else {
            if (!has_changed) {
                start_change = true;
                v[i] = !v[i];
                counter++;
                last = v[i];
            }
        }
    }

    std::cout << counter << std::endl;

    return 0;
}
