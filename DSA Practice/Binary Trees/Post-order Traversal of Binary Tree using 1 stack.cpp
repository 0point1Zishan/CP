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
        vector<int> postorderTraversal(TreeNode* root) {
    
            vector<int> v;
            stack<TreeNode*> st;
            TreeNode* curr = root;
            TreeNode* temp = NULL;
            
            while(curr || !st.empty()){
                if(curr){
                    st.push(curr);
                    curr = curr->left;
                } 
                else{
                    TreeNode* top = st.top();
                    if(top->right && temp != top->right)     curr = top->right;
                    else{
                        v.push_back(top->val);
                        temp = top;
                        st.pop();
                    }
                }
            }
            return v;
        }
    };