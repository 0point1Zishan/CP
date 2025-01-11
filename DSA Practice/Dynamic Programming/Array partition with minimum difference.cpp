int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int sum = 0;
	for(int i = 0; i < n; i++) sum += arr[i];

	int half = sum / 2 + (sum & 1 ?  1 :  0);

	vector<vector<bool>> dp(n, vector<bool>(half+1, 0));

	for(int i = 0; i < n; i++) dp[i][0] = true;
	if(arr[0] <= half) dp[0][arr[0]] = true;

	for(int i = 1; i < n; i++){
		for(int j = 1; j <= half; j++){
			bool op1 = dp[i-1][j];
			bool op2 = false;
			if(arr[i] <= j) op2 = dp[i-1][j - arr[i]];

			dp[i][j] = op1 || op2;
		}
	}

	int mn = 1e9;
	for(int i = 0; i <= half; i++){
		if(dp[n-1][i]){
			mn = min(mn, abs((sum - i) - i));
		}
	}
	return mn;

}
