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
        int findMax(TreeNode* root, int& mx){
            if(!root)   return 0;
    
            int l = findMax(root->left, mx);
            int r = findMax(root->right, mx);
    
            mx = max(mx, l + r);
            return max(l, r) + 1;
        }
        int diameterOfBinaryTree(TreeNode* root) {
            int mx = 0;
            findMax(root, mx);
            return mx;
        }
    };