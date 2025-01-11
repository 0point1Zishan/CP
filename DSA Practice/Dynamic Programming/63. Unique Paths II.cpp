class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int mod = 2 * 1e9;
        int n = grid.size(), m = grid[0].size();
        vector<long long> dp(m), temp(m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0){
                    dp[j] = (grid[i][j] == 1 ?  0 :  1);
                    continue;
                }
                if(grid[i][j] == 1) dp[j] = 0;
                else{
                    int cnt = 0;
                    if(i > 0) cnt = (cnt + temp[j]) % mod;
                    if(j > 0) cnt = (cnt + dp[j-1]) % mod;
                    dp[j] = cnt;
                }
            }
            temp = dp;
        }
        return dp[m-1];
    }
};