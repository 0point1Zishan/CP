class Solution {
  private:
    int count(vector<int>& arr, int target, int i, int n, vector<vector<int>>& dp){
        if(i == n){
            if(target == 0) return 1;
            return 0;
        }
        if(dp[i][target] != -1) return dp[i][target];
        
        int l = 0;
        if(target - arr[i] >= 0) l = count(arr, target - arr[i], i+1, n, dp);
        int r = count(arr, target, i+1, n, dp);
        
        dp[i][target] = l + r;
        return l + r;
    }
  public:      
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        
        return count(arr, target, 0, n, dp);
    }
};