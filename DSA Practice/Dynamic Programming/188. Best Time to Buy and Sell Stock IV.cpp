class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
            int n = prices.size();
            vector<int> pre(2*k+1, 0), cur(2*k+1, 0);
            for(int i = n-1; i >= 0; i--){
                for(int t = 2*k-1; t >= 0; t--){
                    if(t % 2 == 0) cur[t] = max(-prices[i] + pre[t+1], pre[t]);
                    else cur[t] = max(prices[i] + pre[t+1], pre[t]);
                }
                pre = cur;
            }
            return pre[0];
        }
    };