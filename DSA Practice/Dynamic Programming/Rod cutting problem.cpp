int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int> dp(n+1, 0);
	for(int i = 1; i <= n; i++){
		int mx = INT_MIN;
		for(int j = 0; j < i; j++){
			mx = max(mx, price[j] + dp[i-j-1]);
		}
		dp[i] = mx;
	}
	return dp[n];
}
