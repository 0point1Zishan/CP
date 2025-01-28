class Solution {
private:
    long long count(vector<int>& nums, int k){
        int n = nums.size(), l = 0, r = 0, cnt = 0;
        while(r < n){
            if(nums[r] & 1) k--;

            while(k < 0){
                if(nums[l] & 1) k++;
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (int)(count(nums, k) - count(nums, k-1));
    }
};