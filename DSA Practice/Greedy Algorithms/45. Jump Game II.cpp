class Solution {
public:
    int jump(vector<int>& nums) {
        
        if(nums.size() == 1) return 0;
        int n = nums.size(), cnt = 0, mx = nums[0], i = 0;
        
        while(i < n){
            cnt++;
            if(mx >= n-1) return cnt;

            int j = i, maxi = 0;
            while(j <= min(n-1, mx))    maxi = max(maxi, j + nums[j++]);

            mx = maxi;
            i = j;
        }
        return cnt;
    }
};