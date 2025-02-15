
class Solution {
    public:
      bool isLeaf(Node* node){
          return node && !node->left && !node->right;
      }
      void TraversLeft(Node* root, vector<int>& ans){
          Node* curr = root->left;
          while(curr){
              if(!isLeaf(curr))  ans.push_back(curr->data);
              curr = (curr->left)  ?  curr->left   :  curr->right;
          }
      }
      
      void TraversRight(Node* root, vector<int>& ans){
          Node* curr = root->right;
          vector<int> v;
          while(curr){
              if(!isLeaf(curr))  v.push_back(curr->data);
              curr = (curr->right)  ?  curr->right   :  curr->left;
          }
          for(int i = v.size()-1; i >= 0; i--) ans.push_back(v[i]);
      }
      
      void TraversLeaves(Node* root, vector<int>& ans){
          if(!root) return;
          if(isLeaf(root)){
              ans.push_back(root->data);
              return;
          }
          TraversLeaves(root->left, ans);
          TraversLeaves(root->right, ans);
      }
      vector<int> boundaryTraversal(Node *root) {
          // code here
          vector<int> ans;
          if(!root) return ans;
      
          if(!isLeaf(root))  ans.push_back(root->data);
          TraversLeft(root, ans);
          TraversLeaves(root, ans);
          TraversRight(root, ans);
          return ans;
      }
  };