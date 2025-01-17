bool isExists(int i, int k, int n, vector<int>& a, vector<vector<int>>& dp){
    if(i == n) return k == 0;

    if(dp[i][k] != -1) return dp[i][k];

    int op1 = 0;
    if(k - a[i] >= 0) op1 = isExists(i+1, k- a[i], n, a, dp);
    int op2 = isExists(i+1, k, n, a, dp);

    return dp[i][k] = op1 + op2;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return isExists(0, k, n, a, dp);
}