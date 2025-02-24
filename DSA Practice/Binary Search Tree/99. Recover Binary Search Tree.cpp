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
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* middle = NULL;
        TreeNode* last = NULL;
        void inorderT(TreeNode* root){
            if(!root) return;
            inorderT(root->left);
            if(prev && root->val < prev->val){
                if(first) last = root;
                else{
                    first = prev;
                    middle = root;
                }
            }
            prev = root;
            inorderT(root->right);
        }
        void recoverTree(TreeNode* root) {
            prev = first = middle = last = NULL;
            inorderT(root);
            if(last) swap(last->val, first->val);
            else swap(first->val, middle->val);
        }
    };