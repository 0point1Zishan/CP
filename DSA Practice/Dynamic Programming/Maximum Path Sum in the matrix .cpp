#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size(), m = matrix[0].size();
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0) continue;
            int mx = INT_MIN;
            if(j > 0) mx = max(mx, matrix[i-1][j-1]);
            if(j < matrix[0].size() -1) mx = max(mx, matrix[i-1][j+1]);
            mx = max(mx, matrix[i-1][j]);
            matrix[i][j] += mx;
        }
    }

    int mx = INT_MIN;
    for(int i = 0; i < m; i++){
        mx = max(mx, matrix[n-1][i]);
    }
    return mx;
}