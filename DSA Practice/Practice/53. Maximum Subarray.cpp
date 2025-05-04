class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size(), i = 0, mx = INT_MIN, sum = 0;

            // Kadane's Algorithm
            while(i < n){
                sum += nums[i];
                mx = max(mx, sum);
                if(sum < 0){
                    sum = 0;
                }
                i++;
            }
            return mx;
        }
    };