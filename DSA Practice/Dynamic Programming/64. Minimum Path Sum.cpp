class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) continue;
                int mn = INT_MAX;
                if(j > 0) mn = min(mn, grid[i][j-1]);
                if(i > 0) mn = min(mn, grid[i-1][j]);
                grid[i][j] += mn;
            }
        }
        return grid[n-1][m-1];
    }
};