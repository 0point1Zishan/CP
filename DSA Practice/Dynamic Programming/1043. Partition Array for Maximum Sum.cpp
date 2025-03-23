class Solution {
    public:
        int maxSumAfterPartitioning(vector<int>& arr, int k) {
            int n = arr.size();
            vector<int> dp(n+1, 0);
            for(int i = n-1; i >= 0; i--){
                int mx = INT_MIN, len = 0, mx_ele = INT_MIN;
                for(int idx = i; idx < min(n, k+i); idx++){
                    len++;
                    mx_ele = max(mx_ele, arr[idx]);
                    int get = mx_ele * len + dp[idx+1];
                    mx = max(mx, get);
                }
                dp[i] = mx;
            }
            return dp[0];
        }
    };