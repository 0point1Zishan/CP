class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> cur(2, 0), pre(2, 0);
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                int profit = 0;
                if(j == 1) profit = max(-prices[i] + pre[0], pre[1]);
                else profit = max(prices[i] + pre[1], pre[0]);
                cur[j] = profit;
            }
            pre = cur;
        }
        return pre[1];
    }
};