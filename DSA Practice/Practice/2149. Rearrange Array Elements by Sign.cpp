class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& nums) {
            int n = nums.size(), i = 0, j = 1;
            vector<int> ans(n);
            for(int k = 0; k < n; k++){
                if(nums[k] < 0){
                    ans[j] = nums[k];
                    j += 2;
                }
                else{
                    ans[i] = nums[k];
                    i += 2;
                }
            }
            return ans;
        }
    };