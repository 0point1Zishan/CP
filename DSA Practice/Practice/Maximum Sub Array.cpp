class Solution {
    public:
      vector<int> findSubarray(vector<int>& arr) {
          // code here
          int i = 0, j = 0, left = 0, right = -1, sum = 0, mx = 0;
          int n = arr.size();
          
          while(i < n){
              if(arr[i] < 0){
                  if(sum > mx){
                      mx = sum;
                      left = j;
                      right = i-1;
                  }
                  j = i+1;
                  sum = 0;
              }
              else{
                  sum += arr[i];
              }
              i++;
          }
          if(sum > mx){
              left = j;
              right = i-1;
          }
          
          vector<int> ans;
          for(i = left; i <= right; i++){
              ans.push_back(arr[i]);
          }
          if(ans.size()) return ans;
          return {-1};
          
      }
  };