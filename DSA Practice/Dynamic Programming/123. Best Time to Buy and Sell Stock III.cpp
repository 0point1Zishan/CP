class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            
            int n = prices.size();
            vector<vector<int>> pre(2, vector<int>(3, 0)), cur(2, vector<int>(3, 0));
            for(int i = n-1; i >= 0; i--){
                for(int b = 0; b < 2; b++){
                    for(int t = 1; t < 3; t++){
                        if(b) cur[b][t] = max(-prices[i] + pre[0][t], pre[1][t]);
                        else cur[b][t] = max(prices[i] + pre[1][t-1], pre[0][t]);
                    }
                }
                pre = cur;
            }
            return pre[1][2];
        }
    };