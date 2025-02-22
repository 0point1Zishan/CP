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
        // bool isValid(TreeNode* root, int lMn, int lMx, int)
        bool isValid(TreeNode* root, long long mn, long long mx){
            if(!root) return true;
            if(root->val < mn || root->val > mx) return false;
            return isValid(root->left, mn, (long long)root->val - 1) && isValid(root->right, (long long)root->val + 1, mx);
        }
        bool isValidBST(TreeNode* root) {
            return isValid(root, INT_MIN, INT_MAX);
        }
    };