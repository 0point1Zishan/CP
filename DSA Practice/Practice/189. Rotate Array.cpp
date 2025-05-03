class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int st = n - k;
        reverse(nums.begin()+st, nums.end());
        reverse(nums.begin(), nums.begin()+st);
        reverse(nums.begin(), nums.end());
    }
};