class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), mx = 1, cnt = 0;
        vector<pair<int, int> > dp(n, {1, 1});
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(dp[i].first < dp[j].first + 1)  dp[i].first = 1 + dp[j].first, dp[i].second = dp[j].second;
                    else if(dp[i].first == dp[j].first + 1) dp[i].second += dp[j].second;
                } 
            }
            mx = max(mx, dp[i].first);
        }
        for(int i = 0; i < n; i++){
            if(dp[i].first == mx)  cnt += dp[i].second;
        }
        return cnt;
    }
};