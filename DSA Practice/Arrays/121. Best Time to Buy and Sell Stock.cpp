class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX, n = prices.size(), ans = 0;
        for(int i = 0; i < n; i++){
            mn = min(mn, prices[i]);
            ans = max(ans, prices[i] - mn);
        }return ans;
    }
};