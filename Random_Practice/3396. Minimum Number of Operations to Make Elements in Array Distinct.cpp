class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int n = nums.size();
            vector<bool> vis(101, false);
            for(int i = n-1; i >= 0; i--){
                if(vis[nums[i]]){
                    return (i+3) / 3;
                }
                vis[nums[i]] = true;
            }
            return 0;
        }
    };