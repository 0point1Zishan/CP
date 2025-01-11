class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(), mx = *max_element(nums.begin(), nums.end());
        int s = 1, e = mx, ans = 0;

        auto isPos = [&](int div){
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum += (nums[i] + div - 1) / div;
                if(sum > threshold) return false;
            }
            return true;
        };
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(isPos(mid)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }return ans;
    }
};