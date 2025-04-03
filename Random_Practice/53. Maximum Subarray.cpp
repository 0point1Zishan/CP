class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            long long sum = 0, mx = INT_MIN;
            int i = 0, j = 0;
            while(i < n){
                sum += nums[i];
                mx = max(mx, sum);
    
                while(j <= i && sum < 0){
                    mx = max(mx, sum);
                    sum -= nums[j];
                    j++;
                }
                i++;
            }
            return mx;
        }
    };