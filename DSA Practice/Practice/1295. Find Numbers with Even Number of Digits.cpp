class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int digit = floor(log10(abs(nums[i]))) + 1;
            if( !(digit & 1) ) cnt++;
        }
        return cnt;
    }
};