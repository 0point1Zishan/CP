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
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            TreeNode* temp = root;
            while(temp){
                if(temp->val < val){
                    if(!temp->right)  temp->right = new TreeNode(val), temp = NULL;
                    else temp = temp->right;
                }
                else{
                    if(!temp->left) temp->left = new TreeNode(val), temp = NULL;
                    else temp = temp->left;
                }
            }
            if(!root) root = new TreeNode(val);
            return root;
        }
    };