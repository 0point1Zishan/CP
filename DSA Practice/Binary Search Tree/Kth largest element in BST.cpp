class Solution {
    public:
      void traverse(Node* root, int k, int &n, int &val){
          if(!root || n >= k) return;
          traverse(root->right, k, n, val);
          n++;
          if(n == k){
              val = root->data;
              return;
          }
          traverse(root->left, k, n, val);
      }
      int kthLargest(Node *root, int k) {
          // Your code here
          int n = 0, val = -1;
          traverse(root, k, n, val);
          return val;
      }
  };