#include <iostream>
#include <unordered_map>


//needed for the unordered_map
struct PairHash {
    long operator()(std::pair<int, int> const& p) const {
        //+1 should avoid problem with zeroes
        //return concatenation of coordinates
        int pow = 10;
        while ((p.second + 1) >= pow)
            pow *= 10;
        return (p.first + 1) * pow + (p.second + 1);
    }
};

int number_shapes = 0, id = 0;
std::unordered_map<std::pair<int, int>, int, PairHash> x_found;

int count_match(int row, int col_start, int col_end) {

    //I have to check how many times I find a O up, or an X up
    //they are already on the same row

    bool space_found = false, same_up_block = false;
    int id_up_block = -1;

    for (int j = col_start; j<=col_end; ++j) {
        //for each column
        if (x_found.find(std::make_pair(row-1, j)) != x_found.end()) {

            if (id_up_block == -1)
                id_up_block = x_found[std::make_pair(row-1, j)];
            else {
                if (id_up_block == x_found[std::make_pair(row-1, j)]) {
                    //over the current row there is the same block
                    same_up_block = true;
                } else {
                    //update id up block
                    id_up_block = x_found[std::make_pair(row-1, j)];
                    same_up_block = false;
                }
            }
            if (space_found && number_shapes > 0) {
                //actually same shape, maybe there were no need to update number shapes
                if (!same_up_block)
                    number_shapes--;
                //else there is the same block up there and i have already counted it
                space_found = false;
            }
        } else {
            if (j == col_start) {
                //it starts as a different shape
                number_shapes++;    //increment only for the leftmost of the group
                space_found = true;
            }
            if (!space_found) {
                //hole between xs
                space_found = true;
            }
        }
    }
    if (id_up_block != -1) return id_up_block;    //id of the unified block
    else return ++id;   //new id for a new block
}

int main() {

    int t, n, m;
    std::cin >> t;

    for (int k=0; k<t; ++k) {
        std::cin >> n >> m;
        for (int i=0; i<n; ++i) {
            getchar(); //remove newline/separating space
            int j = 0;
            while (j < m) {
                //read sequences of x
                if (getchar() == 'X') {
                    int j_start, j_end;
                    j_start = j;
                    j_end = j;  //for isolated x

                    while (++j < m && getchar() == 'X')
                        j_end++;

                    int sequence_id = count_match(i, j_start, j_end);
                    //insert current x with relative id
                    for (int x=j_start; x<=j_end; ++x)
                        x_found.insert({std::make_pair(i, x), sequence_id});
                } //else just go on
                j++;
            }
            //TODO -> should be possible with map
            /*
             * every 2 iterations (I think) we can remove same elements
             * in x_found because they are useless now (I need only the last row)
             * */
        }
        std::cout << number_shapes << std::endl;
        //clear for next test case
        number_shapes = 0;
        x_found.clear();
    }

    return 0;
}