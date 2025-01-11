#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k+1, false));
    for(int i = 0; i < n; i++) dp[i][0] = true;
    if(arr[0] < k) dp[0][arr[0]] = true;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            bool op1 = dp[i-1][j];
            bool op2 = false;
            if(arr[i] <= j)  op2 = dp[i-1][j - arr[i]];

            dp[i][j] = op1 || op2;
        }
    }
    return dp[n-1][k];
}