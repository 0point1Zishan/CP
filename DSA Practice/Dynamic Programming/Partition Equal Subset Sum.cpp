bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++) sum += arr[i];
	if(sum & 1) return false;

	int half = sum / 2;
	vector<bool> dp(half+1, false);
	dp[0] = true;
	for(int i = 1; i <= n; i++){
		for(int j = half; j >= 0; j--){
			if(arr[i-1] <= j){
				dp[j] = dp[j - arr[i-1]] || dp[j];
			}
		}
	}
	return dp[half];
}
