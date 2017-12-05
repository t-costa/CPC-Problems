#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


struct node {
    bool is_root;
    bool visited;
    bool covered;
    std::vector<node*> children;
};

void cover(node& root) {

    if (root.visited)
        return;

    root.visited = true;

    for (auto& n : root.children)
        cover(*n);

    /*
    if (root.children.size() == 1 && !root.is_root)  //leaf
        root.covered = true;
    else {
        if (std::any_of(root.children.begin(), root.children.end(),
                        [](node* n) {
                            return n->covered;
                        }))
            root.covered = false;   //at least a child is covered
        else
            root.covered = true;    //no child is covered
    }
    */

    root.covered = root.children.size() == 1 && !root.is_root ||
                    !std::any_of(root.children.begin(), root.children.end(),
                                 [](node* n) {
                        return n->covered;
                    });

}

int main() {

    std::ios_base::sync_with_stdio(false);
    int n, u, v;

    std::cin >> n;
    std::vector<node> tree((size_t) n, node {true, false, false, std::initializer_list<node*> {}});

    for (int i=0; i<n-1; ++i) {
        std::cin >> u >> v;
        u--;
        v--;
        //undirected tree
        tree[u].children.push_back(&tree[v]);
        tree[v].children.push_back(&tree[u]);
        tree[v].is_root = false;
    }

    if (n == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }

    int i=0;
    while (i<n && !tree[i].is_root)
        i++;

    //counts largest group
    cover(tree[i]);

    int count = 0;
    for (auto c : tree)
        if (!c.covered)
            count++;

    std::cout << count << std::endl;
    return 0;
}