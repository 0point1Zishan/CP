class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int n = nums.size();
            int sum = 0;
            for(auto &it: nums) sum += it;
            if(sum & 1) return false;
    
            int target = sum / 2;
            vector<int> pre(target+1, 0), cur(target+1, 0);
            pre[0] = true;
    
            for(int i = 1; i <= n; i++){
                cur[0] = true;
                for(int t = 0; t <= target; t++){
                    bool take = false;
                    if(nums[i-1] <= t) take = pre[t-nums[i-1]];
                    bool nontake = pre[t];
                    cur[t] = take | nontake;
                }
                pre = cur;
            }
            return pre[target];
        }
    };