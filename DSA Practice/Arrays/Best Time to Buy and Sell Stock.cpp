#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mn = INT_MAX, n = prices.size(), ans = 0;
    for(int i = 0; i < n; i++){
        if(prices[i] < mn) mn = prices[i];
        ans = max(ans, prices[i] - mn);
    }return ans;
}