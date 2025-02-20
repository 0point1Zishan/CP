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
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> preOrder;
            TreeNode* cur = root;
            while(cur){
                if(!cur->left){
                    preOrder.push_back(cur->val);
                    cur = cur->right;
                }
                else{
                    TreeNode* prv = cur->left;
                    while(prv->right && prv->right != cur) prv = prv->right;
    
                    if(!prv->right){
                        prv->right = cur;
                        preOrder.push_back(cur->val);
                        cur = cur->left;
                    }
                    else{
                        prv->right = NULL;
                        cur = cur->right;
                    }
                }
            }
            return preOrder;
        }
    };