/*
struct Node {
    int data;
    Node* left, *right;
};
*/
/*

//Computes every time min and max for each node, total complexity O(n*height)

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
    if (root == nullptr)
        return true;

    int minRight = 1000, maxLeft = 1;    //values from constraint, if there is just a node I want true
    if (root->left != nullptr) maxLeft = getMax(root->left);
    if (root->right != nullptr) minRight = getMin(root->right);

    if (minRight > root->data && maxLeft <= root->data) 
        return isBST(root->left) && isBST(root->right);
    else return false;

}
*/

bool check_BST(Node* node, int min, int max){
    if (node == nullptr) return true;
    if (node->data < min || node->data > max) return false;
    
    return check_BST(node->left, min, node->data-1) &&      //the value must be between the minimum and the father
        check_BST(node->right, node->data+1, max);          //the value must be between the father and the maximum
}


bool isBST(Node* root){
    return check_BST(root, 1, 1000);    //from constraint
}
