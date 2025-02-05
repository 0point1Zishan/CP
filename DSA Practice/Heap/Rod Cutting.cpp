// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
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
};