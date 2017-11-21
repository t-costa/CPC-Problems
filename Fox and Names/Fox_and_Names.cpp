#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>


struct node{
    char value;
    int has_incoming;
    std::vector<node*> children;
};

//to access position for character a -> a-97

std::vector<node> new_alphabet;
std::vector<char> result;
bool error = false;

bool find(std::vector<node*> const& v, char c) {
    bool found = false;
    int i=0;
    if (v.empty()) return false;

    while (i<v.size() && !found) {
        if (v[i]->value == c)
            found = true;
        i++;
    }

    return found;
}

void build_alphabet(std::string const& a, std::string const& b) {
    size_t i=0;
    size_t shorter = std::min(a.size(), b.size());

    while (i<shorter && a[i]==b[i])
        i++;

    if (i < shorter) {
        //different character found, a[i] precedes b[i]
        if (!find(new_alphabet[(a[i]-97)].children, b[i])) {
            new_alphabet[(a[i]-97)].children.push_back(&new_alphabet[(b[i]-97)]);
            new_alphabet[(b[i]-97)].has_incoming++;
        }
    } else {
        if (shorter == b.size() && shorter < a.size())
            //all the characters are equal, and b is smaller than a
            error = true;
    }
}

bool topological_sort() {

    std::queue<node*> q;
    size_t counter = 0;

    for (auto& n : new_alphabet) {
        if (n.has_incoming == 0)
            q.push(&n);
    }
    //q contains all nodes with no incoming edge

    while (!q.empty()) {
        node* n = q.front();
        q.pop();
        result.push_back(n->value);
        for (auto& c : n->children) {
            c->has_incoming--;  //logically remove edge
            if (c->has_incoming == 0)
                q.push(c);
        }
        counter++;
    }

    return (counter == 26); //all the letters of the alphabet
}

int main() {
    size_t n;
    std::cin >> n;
    
    for (int i=97; i<123; ++i)
        new_alphabet.emplace_back(node {(char) i, 0, {}});
    
    std::string s1, s2;
    std::cin >> s1;
    for (int i=1; i<n; ++i) {
        std::cin >> s2;
        build_alphabet(s1, s2);
        if (error) {
            std::cout << "Impossible";
            return 0;
        }
        s1 = s2;
    }

    if (topological_sort())
        for (auto r : result)
            std::cout << r;
    else
        std::cout << "Impossible";

    return 0;
}
