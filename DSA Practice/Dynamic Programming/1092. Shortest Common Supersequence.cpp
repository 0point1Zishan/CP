class Solution {
    public:
        string shortestCommonSupersequence(string s, string t) {
            int n = s.size(), m = t.size();
            vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    dp[i][j] = (s[i-1] == t[j-1]) ? 1 + dp[i-1][j-1]   :  max(dp[i-1][j], dp[i][j-1]);
                }
            }
            string ans = "";
            while(n > 0 && m > 0){
                if(s[n-1] == t[m-1]){
                    ans += s[n-1];
                    n--;
                    m--;
                }
                else if(dp[n][m] <= dp[n-1][m]){
                    ans += s[n-1];
                    n--;
                }
                else{
                    ans += t[m-1];
                    m--;
                }
            }
            while(n > 0) ans += s[n-1], n--;
            while(m > 0) ans += t[m-1], m--;
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };