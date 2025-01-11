class Solution {
public:
    int mxAmount(vector<int>&num, int i, vector<int>&dp){
        if(i >= num.size()) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(mxAmount(num, i + 2, dp) + num[i], mxAmount(num, i+3, dp) + num[i]);
    }
    int rob(vector<int>& num) {
        vector<int> dp(109, -1);
        int mx1 = mxAmount(num, 0, dp);
        for(int i = 0; i < 109; i++)  dp[i] = -1;
        int mx2 = mxAmount(num, 1, dp);
        return max(mx1, mx2);
    }
};