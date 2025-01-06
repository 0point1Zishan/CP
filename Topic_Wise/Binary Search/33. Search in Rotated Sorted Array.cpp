class Solution {
public:
    int pivot_idx(vector<int> &nums, int n){
        int s = 0, e = n-1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(mid < n-1 && mid > 0 && nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1])        return mid;
            else if(nums[mid] > nums[e])   s = mid + 1;
            else e = mid-1;
        }
        return s;
    }

    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int pivot = pivot_idx(nums, n);
        int s = 0, e = n-1;
        if(target > nums.back())              s = 0, e = pivot-1;
        else   s = pivot, e = n-1;
        
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(nums[mid] == target)      return mid;
            else if(nums[mid] > target)  e = mid-1;
            else                         s = mid + 1;
        }return -1;

    }
};