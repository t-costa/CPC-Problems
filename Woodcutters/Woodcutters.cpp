#include <iostream>
#include <vector>


int32_t count_fallen(std::vector<std::pair<int32_t, int32_t>>& trees) {

    int32_t fallen = 2; //extremes

    for (size_t i=1; i<trees.size()-1; ++i) {
        if (trees[i].first - trees[i].second > trees[i-1].first) {
            //can fall to the left, right extreme of trees[i] unchanged
            fallen++;
        } else {
            if (trees[i].first + trees[i].second < trees[i+1].first) {
                //can fall to the right, update right extreme
                fallen++;
                trees[i].first += trees[i].second;
            }
        }
    }

    return fallen;

}

int main() {

    size_t n_trees;
    int32_t x, h;
    std::vector<std::pair<int32_t, int32_t>> trees;

    std::cin >> n_trees;
    trees.reserve(n_trees);

    for (int32_t i=0; i<n_trees; ++i) {
        std::cin >> x >> h;
        trees.emplace_back(x, h);
    }

    if (n_trees <= 2) {
        //just 1 or 2 trees, they always fall
        std::cout << n_trees << std::endl;
        return 0;
    }

    std::cout << count_fallen(trees) << std::endl;

    return 0;
}