#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size(), m = grid[0].size();
    vector<int> dp(m), temp(m);
    for(int i = 0; i < m; i++) temp[i] = grid[0][i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0){
                dp[j] = grid[i][j];
                continue;
            }
            int mn = INT_MAX;
            if(i > 0) mn = min(mn, temp[j]);
            if(j > 0) mn = min(mn, dp[j-1]);
            dp[j] = grid[i][j] + mn;
        }
        temp = dp;
    }
    return dp[m-1];
}