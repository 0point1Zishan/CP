class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size(), maxPro = 0, mn = INT_MAX;
            for(int i = 0; i < n; i++){
                mn = min(mn, prices[i]);
                maxPro = max(maxPro, prices[i] - mn);
            }
            return maxPro;
        }
    };