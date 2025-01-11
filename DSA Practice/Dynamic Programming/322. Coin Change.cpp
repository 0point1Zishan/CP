class Solution {
public:
    long long f(int i, int n, long long amount, vector<int>& coins, vector<vector<int>> &dp){
        if(i == n){
            if(amount == 0)  return 0;
            else             return INT_MAX;
        }
        if(dp[i][amount] != -1)  return dp[i][amount];

        long long op1 = 0 + f(i+1, n, amount, coins, dp);
        long long op2 = INT_MAX;
        if(coins[i] <= amount) op2 = 1 + f(i, n, amount-coins[i], coins, dp);

        return dp[i][amount] = min(op1, op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        long long ans = f(0, n, amount, coins, dp);

        return (ans == INT_MAX  ? -1  : ans);
    }
};