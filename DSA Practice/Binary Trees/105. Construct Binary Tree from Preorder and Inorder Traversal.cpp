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
        TreeNode* buildTree(vector<int> &inorder, vector<int> &preorder, unordered_map<int, int>& hashMap, int inS, int inE, int preS, int preE){
            if(inS > inE || preS > preE) return NULL;
    
            TreeNode* root = new TreeNode(preorder[preS]);
            
            int mid = hashMap[preorder[preS]];
            int div = mid - inS;
            root->left = buildTree(inorder, preorder, hashMap, inS, mid-1, preS+1, preS + div);
            root->right = buildTree(inorder, preorder, hashMap, mid+1, inE, preS+1+div, preE);
    
            return root;
        }
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            unordered_map<int, int> hashMap;
            int n = inorder.size();
            for(int i = 0; i < n; i++)   hashMap[inorder[i]] = i;
            
            return buildTree(inorder, preorder, hashMap, 0, n-1, 0, n-1);
        }
    };