class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            vector<bool> vis(101, false);
            int cnt = 0;
            for(auto &it: nums){
                if(it < k) return -1;
                if(it > k && !vis[it])  cnt++;
                vis[it] = true;
            }
            return cnt;
        }
    };