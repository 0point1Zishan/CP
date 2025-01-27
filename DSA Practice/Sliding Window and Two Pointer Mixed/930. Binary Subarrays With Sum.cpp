class Solution {
private:
    int numSub(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int l = 0, r = 0, sum = 0, cnt = 0;
        while(r < nums.size()){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l++];
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSub(nums, goal) - numSub(nums, goal-1);
    }
};