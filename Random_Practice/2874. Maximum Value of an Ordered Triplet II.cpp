class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long i = nums[0], i_j = 0, ans = LLONG_MIN, n = nums.size();
    
            for(int k = 1; k < n-1; k++){
                i_j = max(i_j, i - nums[k]);
                i = max(i, (long long) nums[k]);
                ans = max(ans, 1LL * i_j * nums[k+1]);
            }
            return ans;
        }
    };