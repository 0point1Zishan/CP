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
        void RootPath(TreeNode * root, vector<string>& ans, string s){
            if(!root->left && !root->right){
                s += to_string(root->val);
                ans.push_back(s);
                return;
            }
            s += to_string(root->val);
            s += "->";
            if(root->left) RootPath(root->left, ans, s);
            if(root->right) RootPath(root->right, ans, s);
    
        }
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> ans;
            if(!root) return ans;
            RootPath(root, ans, "");
            return ans;
        }
    };