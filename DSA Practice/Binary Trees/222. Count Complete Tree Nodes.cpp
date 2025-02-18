class Solution {
    public:
        int findHight(TreeNode* root, char dir){
            int hight = 0;
            while(root){
                if(dir == 'L') root = root->left;
                else root = root->right;
                hight++;
            }
            return hight;
        }
        int countNodes(TreeNode* root) {
            if(!root) return 0;
            int lh = findHight(root, 'L');
            int rh = findHight(root, 'R');
    
            if(lh == rh) return (1 << lh) - 1;
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    };