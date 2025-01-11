class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        long long s = *max_element(nums.begin(), nums.end()),
        e = accumulate(nums.begin(), nums.end(), 0LL);

        auto count = [&](int mid){
            int cnt = 1, sum = 0;
            for(int i = 0; i < n; i++){
                if(sum + nums[i] > mid){
                    cnt++;
                    sum = nums[i];
                }
                else sum += nums[i];
            }return cnt;
        };
        while(s <= e){
            long long mid = s + (e - s) / 2;
            int cnt = count(mid);
            if(cnt <= k)   e = mid - 1;
            else           s = mid + 1;
        }
        return s;
    }
};