#include <iostream>

int main() {

    std::string number;
    std::cin >> number;
    bool error = false;
    int four_saw = 0;
    int i = 1;

    if (number[0] != '1') {
        std::cout << "NO" << std::endl;
        return 0;
    }

    while (!error && i < number.size()) {
        switch (number[i]) {
            case '1' :
                four_saw = 0;
                break;
            case '4' :
                if (four_saw <= 1) {
                    four_saw++;
                } else {
                    //third four in a row
                    error = true;
                }
                break;
            default :
                error = true;
                break;
        }
        i++;
    }

    if (error)
        std::cout << "NO" << std::endl;
    else std::cout << "YES" << std::endl;

    return 0;
}