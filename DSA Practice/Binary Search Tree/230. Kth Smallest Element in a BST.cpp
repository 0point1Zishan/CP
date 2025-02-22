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
        void traverse(TreeNode *root, int k, int &n, int &val){
            if(!root) return;
            traverse(root->left, k, n, val);
            n++;
            if(n == k){
                val = root->val;
                return;
            }
            traverse(root->right, k, n, val);
        }
        int kthSmallest(TreeNode* root, int k) {
            int val = -1, n = 0;
            traverse(root, k, n, val);
            return val;
        }
    };