class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        int i = nums[0], i_j = 0;
        long long ans = 0;

        for(int k = 1; k < n-1; k++){
            i_j = max(i_j, i - nums[k]);
            i = max(i, nums[k]);

            ans = max(ans, 1LL * i_j * nums[k+1]);
        }
        return ans;
    }
};