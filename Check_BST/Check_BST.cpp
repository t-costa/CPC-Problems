struct Node {
    int data;
    Node* left, *right;
};

int getMin(Node* n){
    while (n->left != nullptr)
        n = n->left;
    return n->data;
}

int getMax(Node* n){
    while (n->right != nullptr)
        n = n->right;
    return n->data;
}

bool isBST(Node* root){
    //in order visit
    if (root == nullptr)
        return true;

    int minRight = 1000, maxLeft = 1;    //from constraint, if there is just a node I want true
    if (root->left != nullptr) maxLeft = getMax(root->left);
    if (root->right != nullptr) minRight = getMin(root->right);

    if (minRight > root->data && maxLeft <= root->data) return isBST(root->left) && isBST(root->right);
    else return false;

}