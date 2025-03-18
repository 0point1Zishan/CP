class Solution {
    public:
      vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
          // Code here
          vector<int> dp(n, 1), hash(n, 1);
          for(int i = 0; i < n; i++){
              hash[i] = i;
              for(int j = 0; j < i; j++){
                  if(arr[j] < arr[i] && 1 + dp[j] > dp[i]){
                      dp[i] = 1 + dp[j];
                      hash[i] = j;
                  }
              }
          }
          int lastIdx = -1, mx = -1;
          for(int i = 0; i < n; i++){
              if(dp[i] > mx){
                  mx = dp[i];
                  lastIdx = i;
              }
          }
      
          vector<int> temp;
          temp.push_back(arr[lastIdx]);
          while(hash[lastIdx] != lastIdx){
              lastIdx = hash[lastIdx];
              temp.push_back(arr[lastIdx]);
          }
          reverse(temp.begin(), temp.end());
          return temp;
      }
  };