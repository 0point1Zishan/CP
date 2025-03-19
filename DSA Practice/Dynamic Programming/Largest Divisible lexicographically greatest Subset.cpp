class Solution {
    public:
      vector<int> largestDivisibleSubset(vector<int>& nums) {
          // Code here
          int n = nums.size();
          sort(nums.begin(), nums.end());
          
          vector<vector<int>> dp(n);
          for(int i = 0; i < n; i++)   dp[i] = {nums[i]};
          
          for(int i = 0; i < n; i++){
              for(int j = 0; j < i; j++){
                  
                  if(nums[i] % nums[j] == 0){
                      
                      vector<int> cur = dp[j];
                      cur.push_back(nums[i]);
                      if(cur.size() > dp[i].size() || (cur.size() == dp[i].size() && cur > dp[i]))     dp[i] = cur;
                  }
              }
          }
          vector<int> ans;
          for(int i = 0; i < n; i++){
              if(dp[i].size() > ans.size() || (dp[i].size() == ans.size() && dp[i] > ans))    ans = dp[i];
          }
          return ans;
      
      }
  };