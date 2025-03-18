class Solution {
    private:
        int f(int i, int pre, int n, vector<int>& arr, vector<vector<int>> &dp){
            if(i == n) return 0;
            if(dp[i][pre + 1] != -1) return dp[i][pre + 1];
    
            int take = 0;
            if(pre == -1 || arr[pre] < arr[i]) take = 1 + f(i+1, i, n, arr, dp);
            int nontake = f(i+1, pre, n, arr, dp);
            return dp[i][pre + 1] = max(take, nontake);
            
        }
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
            return f(0, -1, n, nums, dp);
        }
    };