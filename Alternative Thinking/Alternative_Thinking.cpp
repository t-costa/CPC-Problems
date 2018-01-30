#include <iostream>

int main() {

    int n, val;
    bool last, curr;

    std::cin >> n;

    getchar();
    val = getchar();
    last = (val==49); //representation of 1

    //start counting, as soon as you don't increment
    //change the value, and continue change until you CAN increment
    int counter = 1;
    bool start_change = false, has_changed = false;
    for (int i=1; i<n; ++i) {
        val = getchar();
        curr = (val == 49);
        if (last != curr) {
            counter++;
            if (start_change)
                has_changed = true;
            //can't change anymore
        }
        else {
            if (!has_changed) {
                start_change = true;
                curr = !curr;
                counter++;
            }
        }
        last = curr;
    }

    std::cout << counter << std::endl;

    return 0;
}
