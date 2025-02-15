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
        void traverse(TreeNode* root, int x, int y, vector<vector<int>>& ans){
            if(!root) return;
            ans.push_back({x, y, root->val});
            traverse(root->left, x+1, y-1, ans);
            traverse(root->right, x+1, y+1, ans);
        }
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            vector<vector<int>> ans;
            if(!root) return ans;
    
            traverse(root, 0, 0, ans);
            sort(ans.begin(), ans.end(), [&](vector<int>& a, vector<int>& b){
                if(a[0] == b[0] && a[1] == b[1]) return a[2] < b[2];
                if(a[1] == b[1]) return a[0] < b[0];
                return a[1] < b[1];
            });
    
    
            vector<vector<int>> res;
            int curr = -1, i = 0;
            if(!ans.empty()) curr = ans[0][1];
            vector<int> v;
            while(i < ans.size()){
                if(ans[i][1] == curr) v.push_back(ans[i][2]);
                else{
                    res.push_back(v);
                    v.clear();
                    v.push_back(ans[i][2]);
                    curr = ans[i][1];
                }
                i++;
            }
            res.push_back(v);
            
            return res;
        }
    };