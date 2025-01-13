class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), s = 1, e = n-2;
        if(n == 1 || nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2])       return n-1;
        
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            else if(nums[mid] > nums[mid-1]) s = mid + 1;
            else e = mid - 1;
        }
        return -1;
    }
};