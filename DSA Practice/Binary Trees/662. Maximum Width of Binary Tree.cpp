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
        int widthOfBinaryTree(TreeNode* root) {
            int ans = 0;
            long long MOD = 1e10 + 7;
            queue<pair<TreeNode*, int>> dq;
            if(root) dq.push({root, 0});
    
            while(!dq.empty()){
                int sz = dq.size(), mn = INT_MAX, mx = INT_MIN;
    
                for(int i = 0; i < sz; i++){
                    TreeNode* node = dq.front().first;
                    int num = dq.front().second;
                    dq.pop();
                    if(node->left) dq.push({node->left, (2 * 1LL * num + 1) % MOD});
                    if(node->right) dq.push({node->right, (2 * 1LL * num + 2) % MOD});
    
                    mn = min(mn, num);
                    mx = max(mx, num);
                }
                ans = max(ans, mx - mn + 1);
            }
            return ans;
        }
    };