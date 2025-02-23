class Solution {
    public:
      // returns the inorder successor of the Node x in BST (rooted at 'root')
      int inOrderSuccessor(Node *root, Node *x) {
          // Your code here
          int successor = -1;
          while(root){
              if(root->data <= x->data){
                  root = root->right;
              }
              else{
                  successor = root->data;
                  root = root->left;
              }
          }
          return successor;
      }
  };