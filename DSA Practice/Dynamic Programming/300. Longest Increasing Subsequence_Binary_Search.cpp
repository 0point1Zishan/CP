class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<int> v;    v.push_back(nums[0]);
            for(int i = 1; i < n; i++){
                if(v.back() < nums[i]) v.push_back(nums[i]);
                else{
                    int low = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                    v[low] = nums[i];
                }
            }
            return v.size();
        }
    };