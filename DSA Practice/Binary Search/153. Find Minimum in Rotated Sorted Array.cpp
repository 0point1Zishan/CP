class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size()-1, mn = INT_MAX;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(nums[mid] <= nums[e]){
                mn = min(mn, nums[mid]);
                e = mid - 1;
            }
            else s = mid + 1;
        }return mn;
    }
};