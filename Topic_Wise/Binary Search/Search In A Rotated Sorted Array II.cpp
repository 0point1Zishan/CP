bool ans(vector<int>& nums, int target, int s, int e){
    while(s <= e){
        int mid = s + (e - s) / 2;
        if(nums[mid] == target) return true;
        else if(nums[s] == nums[mid] && nums[mid] == nums[e]){
            return ans(nums, target, s, mid-1) || ans(nums, target, mid+1, e);
        }
        else if(nums[s] <= nums[mid]){
            if(target >= nums[s] && target <= nums[mid]) e = mid - 1;
            else                                         s = mid + 1;
        }
        else{
            if(target <= nums[e] && target >= nums[mid]) s = mid + 1;
            else                                         e = mid - 1;
        }
    }
    return false;
}
bool searchInARotatedSortedArrayII(vector<int>&a, int key) {
    // Write your code here.
    int s = 0, e = a.size()-1;
    return ans(a, key, s, e);
}