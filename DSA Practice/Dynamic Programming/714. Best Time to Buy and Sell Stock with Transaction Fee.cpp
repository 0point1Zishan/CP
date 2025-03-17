class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee) {
            int n = prices.size();
            vector<int> pre(2, 0), cur(2, 0);
            for(int i = n-1; i >= 0; i--){
                for(int b = 1; b >= 0; b--){
                    if(b) cur[b] = max(-prices[i] - fee + pre[0], pre[1]);
                    else cur[b] = max(prices[i] + pre[1], pre[0]);
                }
                pre = cur;
            }
            return pre[1];
        }
    };