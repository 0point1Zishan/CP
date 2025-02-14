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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> ans;
            queue<TreeNode*> dq;
            if(root) dq.push(root);
    
            while(!dq.empty()){
                int sz = dq.size();
                vector<int> v(sz);
                for(int i = 0; i < sz; i++){
    
                    if(dq.front()->left)  dq.push(dq.front()->left);
                    if(dq.front()->right)  dq.push(dq.front()->right);
    
                    if(ans.size() & 1) v[sz-i-1] = dq.front()->val;
                    else                    v[i] = dq.front()->val;
                    dq.pop();
                }
                ans.push_back(v);
            }
            return ans;
        }
    };    