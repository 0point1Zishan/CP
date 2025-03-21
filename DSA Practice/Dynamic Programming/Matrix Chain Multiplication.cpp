class Solution {
    private:
      int sol(int i, int j, vector<int>& arr, vector<vector<int>> &dp){
          if(i == j) return 0;
          if(dp[i][j] != -1) return dp[i][j];
      
          int mn = 1e9;
          for(int k = i; k < j; k++){
              int steps = arr[i-1] * arr[k] * arr[j] + sol(i, k, arr, dp) + sol(k+1, j, arr, dp);
              mn = min(mn, steps);
          }
          return dp[i][j] = mn;
      }
    public:
      int matrixMultiplication(vector<int> &arr) {
          // code here
          int N = arr.size();
          vector<vector<int>> dp(N, vector<int>(N, -1));
          return sol(1, N-1, arr, dp);
      }
  };