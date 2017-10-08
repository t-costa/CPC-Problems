#include <iostream>
#include <vector>


void buildMax(std::vector<short>::iterator start, std::vector<short>::iterator end){
    int counter[10] = { };  //digit from 0 to 9, array initialized to 0

    for (auto it = start; it != end; ++it)
        counter[*it]++;


    //sort in decreasing order
    for (int i=9; i>=0; --i){
        while (counter[i] > 0) {
            *start = i;
            counter[i]--;
            start++;
        }
    }

}

int main() {

    int testCase, posLeastEven;
    std::vector<short> number;
    std::cin >> testCase;
    posLeastEven = -1;

    getchar();  //remove first \n

    for (int i=0; i<testCase; ++i){
        int c = getchar();
        int j = 0;
        while (c != '\n'){
            if (c == EOF) break;
            short d = (short) (c - '0');    //trick
            number.push_back(d);
            if (d % 2 == 0){
                if (posLeastEven == -1)
                    posLeastEven = j;
                else
                    if (d < number[posLeastEven])
                        posLeastEven = j;
            }
            c = getchar();
            j++;
        }

        if (posLeastEven > -1) {
            //there is a positive number, swap it to the end
            int tmp = number[posLeastEven];
            number[posLeastEven] = number[number.size()-1];
            number[number.size()-1] = tmp;
            buildMax(number.begin(), number.end()-1);
        } else {
            //all odd numbers, no need for swap
            buildMax(number.begin(), number.end());
        }


        for (int v : number)
            std::cout << v << "";

        std::cout << std::endl;
        //restore variables
        posLeastEven = -1;
        number.clear();
    }

}
