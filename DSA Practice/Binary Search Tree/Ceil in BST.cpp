int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    // Your code here
    int c = INT_MAX;
    while(root){
        if(root->data >= input){
            c = min(c, root->data);
            root = root->left;
        }
        else root = root->right;
    }
    return (c == INT_MAX) ? -1 : c;
}