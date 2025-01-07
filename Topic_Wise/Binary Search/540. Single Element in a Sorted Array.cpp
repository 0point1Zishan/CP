class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        while(s < e){
            int mid = s + (e - s) / 2;
            if((mid-s+1) % 2 != 0 && (e-mid+1) % 2 != 0){
                if(s < mid && nums[mid] == nums[mid-1]) e = mid;
                else                                    s = mid;
            }
            else if((mid - s + 1) % 2 == 0 && s < mid && nums[mid] == nums[mid-1]) s = mid + 1;
            else e = mid - 1;
        }
        return nums[e];
    }
};