class Solution {
    public:
        int maximumPossibleSize(vector<int>& nums) {
            int n = nums.size();
            int cnt = 1, preMax = nums[0];
            int i = 1;
            while(i < n){
                while(i < n && nums[i] < preMax) i++;
                if(i < n){
                    preMax = nums[i];
                    cnt++;
                    i++;
                }
            }
            return cnt;
        }
    };