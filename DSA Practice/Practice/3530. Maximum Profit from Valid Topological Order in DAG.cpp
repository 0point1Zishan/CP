class Solution {
    vector<int> pre;
    vector<long long> dp;
    private:
        long long dfs(int mask, vector<int>& score, int n){
            
            if(mask == (1 << n) - 1) return 0;
            if(dp[mask] != -1) return dp[mask];
    
            int pos = __builtin_popcount(mask) + 1;
            long long ans = LLONG_MIN;
    
            for(int i = 0; i < n; i++){
                if( (mask & (1 << i) ) ) continue;
                
                if( (pre[i] & ~mask) == 0){
                    long long cur = dfs(mask | (1 << i), score, n);
                    if(cur != LLONG_MIN){
                        ans = max(ans, cur + 1LL * score[i] * pos);
                    }
                }
            }
            return dp[mask] = (ans == LLONG_MIN ? 0 : ans);
        }
    public:
        int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
            pre.assign(n, 0);
            for(auto &it: edges){
                pre[it[1]] |= 1 << it[0];
            }
            dp.assign(1 << n, -1);
            return dfs(0, score, n);
        }
    };