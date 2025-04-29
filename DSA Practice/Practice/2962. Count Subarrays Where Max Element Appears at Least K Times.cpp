class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
           int idx = 0, leftIdx = 0;
            int n = nums.size();
            int mxNum = *max_element(nums.begin(), nums.end());
            int cnt = 0;
            long long ans = 0;
    
            while(idx < n){
                if(nums[idx] == mxNum) cnt++;
                if(cnt >= k){
                    int first = leftIdx;
                    while(first < idx && nums[first] != mxNum) first++;
                    long long cur = 1LL * (n - idx) * (first - leftIdx + 1);
                    ans += cur;
                    leftIdx = first+1;
                    cnt--;
                }
                idx++;
            }
            return ans;
        }
    };