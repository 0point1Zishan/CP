/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        TreeNode* reOrder(vector<int>& preorder, int& i, int bound){
            if(i == preorder.size() || bound < preorder[i]) return NULL;
            TreeNode* root = new TreeNode(preorder[i++]);
            root->left = reOrder(preorder, i, root->val);
            root->right = reOrder(preorder, i, bound);
            return root;
        }
        TreeNode* bstFromPreorder(vector<int>& preorder) {
            int i = 0;
            return reOrder(preorder, i, INT_MAX);
        }
    };