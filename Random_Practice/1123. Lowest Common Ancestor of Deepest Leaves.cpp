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
    private:
        int findHeight(TreeNode* root, vector<int>& h){
            if(!root) return 0;
            int l = 1 + findHeight(root->left, h);
            int r = 1 + findHeight(root->right, h);
            h[root->val] = max(l, r);
            return max(l, r);
        }
        TreeNode* lca(TreeNode* root, vector<int>& h){
            if(!root) return NULL;
            if(root && !root->left && !root->right) return root;
    
            if(root->left && root->right && h[root->left->val] == h[root->right->val]) return root;
            if(root->left && root->right && h[root->left->val] > h[root->right->val]) return lca(root->left, h);
            if(root->left && root->right && h[root->left->val] < h[root->right->val]) return lca(root->right, h);
    
            if(!root->left) return lca(root->right, h);
            else            return lca(root->left, h);
        }
    public:
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            vector<int> height(1001, 0);
            findHeight(root, height);
            
            return lca(root, height);
        }
    };