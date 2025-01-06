class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1, idx = nums.size();
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(nums[mid] >= target){
                idx = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return idx;
    }
};