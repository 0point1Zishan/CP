class Solution {

  public:
    int minCoins(vector<int> &coins, int sum) {
        // Your code goes here
        int n = coins.size();
        sort(coins.begin(), coins.end(), greater<>());
        
        int i = 0, cnt = 0;
        while(sum && i < n){
            int currCoins = sum / coins[i];
            sum -= (currCoins * coins[i]);
            cnt += currCoins;
            i++;
        }
        return (sum == 0) ? cnt : -1;
    }
};