class Solution {
    public:
        vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
            vector<int> limit;
            int last = 0;
            limit.push_back(last);
    
            for(int i = 1; i < n; i++){
                int k = nums[i] - maxDiff;
                int lowIdx = lower_bound(nums.begin(), nums.end(), k) - nums.begin();
    
                if(lowIdx == i) last = i;
                limit.push_back(last);
            }
            vector<bool> ans;
            int i = 0;
            while(i < queries.size()){
                int u = queries[i][0];
                int v = queries[i][1];
                if(u > v) swap(u, v);
                if(limit[v] <= u) ans.push_back(true);
                else ans.push_back(false);
                i++;
            }
            return ans;
        }
    };