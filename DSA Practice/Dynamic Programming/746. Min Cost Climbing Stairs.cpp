class Solution {
public:
    int mini(vector<int>&cost, int des, int i, vector<int>&dp){
        if(i > des) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = min(mini(cost, des, i+1, dp) + cost[i], mini(cost, des, i+2, dp) + cost[i]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(1009, -1);
        int mn1 = mini(cost, n-1, 0, dp);
        for(int i = 0; i < 1009; i++) dp[i] = -1;
        int mn2 = mini(cost, n-1, 1, dp);
        return min(mn1, mn2);
    }
};