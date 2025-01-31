int countNode(BinaryTreeNode<int>* root){
    if(!root) return 0;
    return 1 + countNode(root->left) + countNode(root->right);
}

bool isCompBinT(BinaryTreeNode<int>* root, int idx, int cnt){
    if(!root) return true;
    if(idx >= cnt) return false;
    return isCompBinT(root->left, 2 * idx + 1, cnt) && isCompBinT(root->right, 2 * idx + 2, cnt);
}

bool isMaxHeap(BinaryTreeNode<int>* root){
    if(!root) return true;
    
    if(root->left && root->data < root->left->data) return false;
    if(root->right && root->data < root->right->data) return false;

    return isMaxHeap(root->left) && isMaxHeap(root->right);
}

bool isBinaryHeapTree(BinaryTreeNode<int>* root) 
{
    // Write your code here.
    int total = countNode(root);
    return isCompBinT(root, 0, total) && isMaxHeap(root);
}