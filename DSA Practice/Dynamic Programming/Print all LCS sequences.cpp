class Solution {

    public:
      vector<string> all_longest_common_subsequences(string s, string t) {
          // Code here
          int n = s.size(), m = t.size();
          vector<vector<int>> len(n+1, vector<int>(m+1, 0));
          for(int i = 1; i <= n; i++){
              for(int j = 1; j <= m; j++){
                  if(s[i-1] == t[j-1]) len[i][j] = 1 + len[i-1][j-1];
                  else len[i][j] = max(len[i-1][j], len[i][j-1]);
              }
          }
          vector<vector<set<string>>> dp(n+1, vector<set<string>>(m+1));
          for(int i = 0; i <= n; i++) dp[i][0].insert("");
          for(int i = 0; i <= m; i++) dp[0][i].insert("");
          
          for(int i = 1; i <= n; i++){
              for(int j = 1; j <= m; j++){
                  if(s[i-1] == t[j-1]){
                      for(auto seq: dp[i-1][j-1]) dp[i][j].insert(seq + s[i-1]);
                  }
                  else{
                      if(len[i-1][j] >= len[i][j-1]) dp[i][j].insert(dp[i-1][j].begin(), dp[i-1][j].end());
                      if(len[i][j-1] >= len[i-1][j]) dp[i][j].insert(dp[i][j-1].begin(), dp[i][j-1].end());
                  }
              }
          }
          
          vector<string> res(dp[n][m].begin(), dp[n][m].end());
          return res;
      
      }
  };