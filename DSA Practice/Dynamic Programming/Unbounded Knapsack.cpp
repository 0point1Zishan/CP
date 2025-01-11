#include<bits/stdc++.h>
int mx(int i, int n, int h, vector<int> &p, vector<int> &w, vector<vector<int>> &dp){
    if(i == n || h == 0){
        return 0;
    }
    if(dp[i][h] != -1) return dp[i][h];

    int op1 = 0 + mx(i+1, n, h, p, w, dp);
    int op2 = 0;
    if(h >= w[i]) op2 = p[i] + mx(i, n, h - w[i], p, w, dp);
    return dp[i][h] = max(op1, op2);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    return mx(0, n, w, profit, weight, dp);
}