class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> pre1(2, 0), cur(2,0), pre2(2, 0);
        for(int i = n-1; i >= 0; i--){
            for(int b = 0; b < 2; b++){
                if(b) cur[b] = max(-prices[i] + pre1[0], pre1[1]);
                else cur[b] = max(prices[i] + pre2[1], pre1[0]);
            }
            pre2 = pre1;
            pre1 = cur;
        }
        return cur[1];
    }
};