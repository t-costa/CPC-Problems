#include <iostream>
#include <vector>

class Disjoint_Set {

private:
    struct element {
        int parent;
        int rank;
    };

    std::vector<element> set;
    std::vector<int> eat;       //eat[x] = y <=> x eats y
    std::vector<int> eaten;     //eaten[x] = y <=> x is eaten by y

    std::pair<int, int> link(int x, int y) {
        //don't modify eat/eaten
        if (find_set(x) == find_set(y)) //already same group
            return std::make_pair(find_set(x), find_set(y));

        if (set[x].rank > set[y].rank) {
            set[y].parent = x;
            return std::make_pair(x, y);
        }
        else {
            set[x].parent = y;
            if (set[x].rank == set[y].rank)
                set[y].rank++;
            return std::make_pair(y, x);
        }
        //the first element returned is the new representative
    }

    bool unify_after_unify(int& x, int& y) {
        if (x == -1 && y == -1)
            return false; //nothing to do
        if (x == -1) {
            x = y;
            return false;
        }
        if (y == -1) {
            y = x;
            return false;
        }

        //they can be unified
        unify(find_set(x), find_set(y));
        return true;
    }

    void simple_eat(int x, int y) {
        int x1 = find_set(x);
        int y1 = find_set(y);

        if (x1 == -1 || y1 == -1 || x1 == y1)
            return;

        eat[x1] = y1;
        eaten[y1] = x1;
    }
    
    void unify_after_eat(int x, int y) {
        int x1 = find_set(x);
        int y1 = find_set(y);

        if (x1 == -1 || y1 == -1)
            return;

        auto cp = link(x1, y1);

        //update the representative only if it is -1
        if (eat[cp.first] == -1)
            eat[cp.first] = eat[cp.second];

        if (eaten[cp.first] == -1)
            eaten[cp.first] = eaten[cp.second];
    }

public:
    explicit Disjoint_Set (size_t n) {
        set.reserve(n);
        eat.reserve(n);
        eaten.reserve(n);

        //initialize set, eat and eaten
        for (size_t i=0; i<n; ++i) {
            set.emplace_back(element {(int) i, 1});
            eat.push_back(-1);
            eaten.push_back(-1);
        }
    };

    int find_set(int x) {
        if (x == -1)
            return -1;

        if (x != set[x].parent)
            set[x].parent = find_set(set[x].parent);
        return set[x].parent;
    }

    bool unify(int x, int y) {
        int x1 = find_set(x);
        int y1 = find_set(y);

        //same leader -> same group
        if (x1 == y1)
            return true;

        int c1 = find_set(eat[x1]);
        int d1 = find_set(eaten[x1]);
        //x->y || y->x || x -> c -> y || y -> d -> x
        if (c1 == y1 ||
                find_set(eat[y1]) == x1 ||
                c1 != -1 && c1 == find_set(eaten[y1]) ||
                d1 != -1 && d1 == find_set(eat[y1]))
            return false;
        
        auto rep = link(x1, y1);

        if (unify_after_unify(eaten[x1], eaten[y1])) {
            //update who eats the representative
            eaten[rep.first] = find_set(eaten[x1]);
        }

        if (unify_after_unify(eat[x1], eat[y1])) {
            //updates who is eaten by the representative
            eat[rep.first] = find_set(eat[x1]);
        }

        //if a->(x-y)->b => b->a
        simple_eat(eat[rep.first], eaten[rep.first]);

        return true;
    }

    bool new_eater(int x, int y) {
        int x1 = find_set(x);
        int y1 = find_set(y);

        //x can't eat y <=> x and y are in the same group or y eats x
        if (x1 == y1 || find_set(eat[y1]) == x1)
            return false;

        //add useful deducted info
        unify_after_eat(eat[x1], y1);
        unify_after_eat(x1, eaten[y1]);
        unify_after_eat(eaten[x1], eat[y1]);

        //add x->y
        eat[x1] = y1;
        eaten[y1] = x1;

        //if this creates a triple, close it
        simple_eat(eat[y1], x1);
        simple_eat(y1, eaten[x1]);

        return true;
    }

    void clear() {
        set.clear();
        eat.clear();
        eaten.clear();
    }
};

int main() {

    std::ios_base::sync_with_stdio(false);
    int t, n, k, d, x, y, n_false = 0;
    std::cin >> t;

    for (int i=0; i<t; ++i) {
        std::cin >> n >> k;
        Disjoint_Set set((size_t) n);

        for (int j=0; j<k; ++j) {
            std::cin >> d >> x >> y;
            //x and y go from 1 to n
            x--;
            y--;

            if ((x >= n || y >= n) || (d == 2 && x == y)) {
                n_false++;
                continue;
            }

            switch (d) {
                case 1 :
                    if (!set.unify(x, y))
                        n_false++;
                    break;

                case 2 :
                    if (!set.new_eater(x, y))
                        n_false++;
                    break;

                default:
                    break;
            }
        }

        std::cout << n_false << std::endl;
        n_false = 0;
        set.clear();
    }

    return 0;
}
