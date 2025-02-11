/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void inOrder(TreeNode* root, vector<int>& traversal){
    if(!root) return;
    inOrder(root->left, traversal);
    traversal.push_back(root->data);
    inOrder(root->right, traversal);
}
void PreOrder(TreeNode* root, vector<int>& traversal){
    if(!root) return;
    traversal.push_back(root->data);
    PreOrder(root->left, traversal);
    PreOrder(root->right, traversal);
}
void PostOrder(TreeNode* root, vector<int>& traversal){
    if(!root) return;
    PostOrder(root->left, traversal);
    PostOrder(root->right, traversal);
    traversal.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>> ans;

    vector<int> traversal;
    inOrder(root, traversal);
    ans.push_back(traversal);

    traversal.clear();
    PreOrder(root, traversal);
    ans.push_back(traversal);

    traversal.clear();
    PostOrder(root, traversal);
    ans.push_back(traversal);

    return ans;
}