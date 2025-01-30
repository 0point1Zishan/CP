class Solution {
private:
    int subArrays(vector<int>& nums, int k){
        int l = 0, r = 0, n = nums.size(), cnt = 0;
        vector<int> fre(n + 5, 0);

        while(r < n){
            fre[nums[r]]++;
            if(fre[nums[r]] == 1) k--;
            
            while(l <= r && k < 0){
                fre[nums[l]]--;
                if(fre[nums[l]] == 0) k++;
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subArrays(nums, k) - subArrays(nums, k-1);
    }
};