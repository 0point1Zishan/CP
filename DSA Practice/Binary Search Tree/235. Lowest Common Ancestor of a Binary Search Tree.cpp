/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
            while(root){
                if(root == p || root == q || root->val > min(p->val, q->val) && root->val < max(p->val, q->val)) return root;
                if(root->val > p->val) root = root->left;
                else root = root->right;
            }
            return root;
        }
    };