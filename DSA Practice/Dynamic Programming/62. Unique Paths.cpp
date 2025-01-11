class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1), temp(n, 1);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){
                    dp[0] = 1;
                    temp[0] = 1;
                    continue;
                }
                dp[j] = dp[j-1] + temp[j];
            }
            temp = dp;
        }
        return dp[n-1];
    }
};