class Solution {
    public:
      bool isBSTTraversal(vector<int>& arr) {
          // your code here
          if(arr.size() == 1) return true;
          for(int i = 1; i < arr.size(); i++){
              if(arr[i] <= arr[i-1]) return false;
          }return true;
      }
  };