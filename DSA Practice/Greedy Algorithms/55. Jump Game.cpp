class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int req = 1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] >= req) req = 1;
            else req++;
        }
        return req == 1;
    }
};