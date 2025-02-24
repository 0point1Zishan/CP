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
class NodeValue{
    public:
        int mxVal, mnVal, sz;
        bool bst;
    NodeValue(int mxVal, int mnVal, int sz, bool bst){
        this->mxVal = mxVal;
        this->mnVal = mnVal;
        this->sz = sz;
        this->bst = bst;
    }
};
NodeValue largestBSTSubTree(TreeNode* root, int &ans){
    if(!root) return NodeValue(INT_MIN, INT_MAX, 0, true);
    
    auto left = largestBSTSubTree(root->left, ans);
    auto right = largestBSTSubTree(root->right, ans);
    
    int sz = left.sz + right.sz + 1;
    int mxVal = max(root->data, right.mxVal);
    int mnVal = min(root->data, left.mnVal);

    bool isBst = false;
    if(left.bst && right.bst && root->data > left.mxVal && root->data < right.mnVal)
        isBst = true;

    if(isBst) ans = max(ans, sz);
    return NodeValue(mxVal, mnVal, sz, isBst);
}
int largestBST(TreeNode * root){
    // Write your code here.
    int ans = 0;
    largestBSTSubTree(root, ans);
    return ans;
}