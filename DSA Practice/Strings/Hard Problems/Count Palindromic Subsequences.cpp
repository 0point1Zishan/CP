class Solution {
    private:
      int mod = 1e9 + 7;
      long long f(int i, int j, string& s, vector<vector<long long>>& dp){
          if(i == j) return 1;
          if(i > j) return 0;
          if(dp[i][j] != -1) return dp[i][j];
      
          if(s[i] == s[j]) return dp[i][j] = (1 + (f(i+1, j, s, dp) + f(i, j-1, s, dp)) % mod ) % mod;
          else{
              return dp[i][j] = ((f(i+1, j, s, dp) + f(i, j-1, s, dp)) % mod - f(i+1, j-1, s, dp) + mod);
          }
      }
    public:
      /*You are required to complete below method */
      int countPS(string &s) {
          // Your code here
          int n = s.size();
          vector<vector<long long>> dp(n+1, vector<long long>(n+1, -1));
          return f(0, n-1, s, dp) % mod;
      }
  };