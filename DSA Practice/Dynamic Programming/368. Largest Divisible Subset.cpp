class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            vector<int> dp(n, 1), pre(n, -1);
    
            int mx_idx = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < i; j++){
                    if(nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]){
                        dp[i] = 1 + dp[j];
                        pre[i] = j;
                    }
                }
                if(dp[i] > dp[mx_idx]) mx_idx = i;
            }
    
            vector<int> ans;
            while(mx_idx != -1){
                ans.push_back(nums[mx_idx]);
                mx_idx = pre[mx_idx];
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };