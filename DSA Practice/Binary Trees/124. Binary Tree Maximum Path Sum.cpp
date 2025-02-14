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
        int mxSum(TreeNode* root, int& mx){
            if(!root) return 0;
    
            int l = max(0, mxSum(root->left, mx));
            int r = max(0, mxSum(root->right, mx));
    
            mx = max(mx, l + r + root->val);
            return root->val + max(l, r);
        }
        int maxPathSum(TreeNode* root) {
            int mx = -1e9;
            mxSum(root, mx);
            return mx;
        }
    };