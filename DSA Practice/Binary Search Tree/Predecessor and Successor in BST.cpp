class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        Node*temp = root;
        while(root){
            if(root->key <= key) root = root->right;
            else{
                suc = root;
                root = root->left;
            }
        }
        while(temp){
            if(temp->key >= key) temp = temp->left;
            else{
                pre = temp;
                temp = temp->right;
            }
        }
    }
};