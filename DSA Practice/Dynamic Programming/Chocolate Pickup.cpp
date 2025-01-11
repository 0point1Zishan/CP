#include <bits/stdc++.h> 
int f(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector< vector< vector<int>> > &dp){
    if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) return -1e8;

    if(i == n-1){
        if(j1 == j2) return grid[i][j1];
        return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    int mx = -1e8;
    for(int a = -1; a <= 1; a++){
        for(int b = -1; b <= 1; b++){
            int val = 0;
            if(j1 == j2) val = grid[i][j1];
            else         val = grid[i][j1] + grid[i][j2];

            val += f(i+1, j1+a, j2+b, n, m, grid, dp);
            mx = max(mx, val);
        }
    }
    return dp[i][j1][j2] = mx;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.    
    vector< vector< vector<int>> > dp(r, vector< vector<int>>(c, vector<int>(c, -1)));
    return f(0, 0, c-1, r, c, grid, dp);
}