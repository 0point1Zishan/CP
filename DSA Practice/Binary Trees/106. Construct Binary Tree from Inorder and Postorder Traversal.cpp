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
        TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int>& hashMap, int inS, int inE, int postS, int postE){
            if(inS > inE || postS > postE) return NULL;
    
            TreeNode* root = new TreeNode(postorder[postE]);
            
            int mid = hashMap[postorder[postE]];
            int div = mid - inS;
            root->left = buildTree(inorder, postorder, hashMap, inS, mid-1, postS, postS+div-1);
            root->right = buildTree(inorder, postorder, hashMap, mid+1, inE, postS+div, postE-1);
    
            return root;
        }
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            unordered_map<int, int> hashMap;
            int n = inorder.size();
            for(int i = 0; i < n; i++)   hashMap[inorder[i]] = i;
            
            return buildTree(inorder, postorder, hashMap, 0, n-1, 0, n-1);
        }
    };