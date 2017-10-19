
#include <algorithm>
#include <climits>

int visit(struct Node *n, int& max){
    int left = 0, right = 0, path;
    bool has_Right = false;
    bool has_Left = false;

    if (n->left == nullptr && n->right == nullptr)
        return n->data;
    if (n->left != nullptr) {
        left = visit(n->left, max);
        has_Left = true;
    }
    if (n->right != nullptr) {
        right = visit(n->right, max);
        has_Right = true;
    }

    if (has_Left && has_Right){
        path = n->data + left + right;
        //else it doesn't make sense to have a path
        if (path > max) max = path;
        return n->data + std::max(left, right);
    } else {
        //has only left or right child
        if (has_Left) return n->data + left;
        else return n->data + right;
    }

}

int maxPathSum(struct Node *root)
{
    int max = INT_MIN;
    int v = visit(root, max);
    return max;
}
