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
        int hightDiff(TreeNode* root) {
            if(!root) return 0;
            int left = hightDiff(root->left), right = hightDiff(root->right);
            return (left == -1 || right == -1 || abs(left - right) > 1) ? -1 : max(left, right) + 1;
        }
        bool isBalanced(TreeNode* root) {
            return hightDiff(root) != -1;
        }
    };