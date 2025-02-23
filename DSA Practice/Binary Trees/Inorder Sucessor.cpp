void inorderTraverse(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node, BinaryTreeNode<int>* &succesor, bool &isVisited){
    if(!root) return;
    inorderTraverse(root->left, node, succesor, isVisited);
    if(isVisited && !succesor) succesor = root;
    if(root->data == node->data) isVisited = true;
    inorderTraverse(root->right, node, succesor, isVisited);
}
BinaryTreeNode<int> *inorderSuccesor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node)
{
    // Write your code here.
    BinaryTreeNode<int>* succesor = NULL;
    bool isVisited = false;
    inorderTraverse(root, node, succesor, isVisited);
    return succesor;
}