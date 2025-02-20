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
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> inOrder;
            TreeNode* cur = root;
            while(cur){
                if(!cur->left){
                    inOrder.push_back(cur->val);
                    cur = cur->right;
                }
                else{
                    TreeNode* prv = cur->left;
                    while(prv->right && prv->right != cur) prv = prv->right;
    
                    if(!prv->right){
                        prv->right = cur;
                        cur = cur->left;
                    }
                    else{
                        prv->right = NULL;
                        inOrder.push_back(cur->val);
                        cur = cur->right;
                    }
                }
            }
            return inOrder;
        }
    };