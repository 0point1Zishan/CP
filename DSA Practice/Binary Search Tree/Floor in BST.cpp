class Solution{

    public:
        int floor(Node* root, int x) {
            // Code here
            int f = INT_MIN;
            while(root){
                if(root->data <= x){
                    f = max(f, root->data);
                    root = root->right;
                }
                else root = root->left;
            }
            return (f == INT_MIN) ? -1 : f;
        }
    };