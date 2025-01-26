class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0, mxLen = 0;
        while(r < n){
            if(nums[r] == 0) k--;
            if(k < 0){
                if(nums[l] == 0) k++;
                l++;
            }
            if(k >= 0) mxLen = max(mxLen, r - l + 1);
            r++;
        }
        return mxLen;
    }
};