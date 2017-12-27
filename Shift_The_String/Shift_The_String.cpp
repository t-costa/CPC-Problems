#include <iostream>
#include <vector>

std::vector<int> kmp_pi(std::string const& s) {

    std::vector<int> pi;
    pi.reserve(s.size() + 1);

    int k = 0;
    pi[1] = 0;

    for (int i = 1; i<s.size(); ++i) {
        //first character of the string is already "used";
        while (k > 0 && s[k] != s[i])
            k = pi[k];

        if (s[k] == s[i])
            k++;

        //i goes from 1 to n-1 => I want 2 to n
        pi[i+1] = k;

    }

    return pi;
}

int kmp(std::string const& a, std::string const& b) {

    //I want to search the pattern a inside the various positions of b
    auto pi = kmp_pi(a);
    int q = 0, res=0, temp=0, max_pref=0;

    for (int i=0; i<b.size(); ++i) {

        while (q>0 && a[q] != b[i]) {
            temp = 0;
            q = pi[q];
        }

        if (a[q] == b[i]) {
            ++q;
            ++temp; //count length of current prefix
        }

        if (temp > max_pref) {
            max_pref = temp;
            res = i-max_pref+1;    //always <= b.size()/2
        }
    }

    return res;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    int n;
    std::string a;
    std::string b;

    std::cin >> n;
    std::cin >> a >> b;

    b += b; //it becomes the text in which we search

    std::cout << kmp(a, b) << std::endl;

    return 0;
}