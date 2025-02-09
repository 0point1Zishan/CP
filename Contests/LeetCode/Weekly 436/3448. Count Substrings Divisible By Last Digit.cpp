class Solution {
    public:
        long long countSubstrings(string s) {
            
            vector<vector<int>> dp(10, vector<int>(10));
            vector<int> sum(10);
            for(int i = 1; i < 10; i++) dp[i][0] = 1;
            long long ans = 0;
    
            auto update_sum = [&](int val){
                for(int i = 1; i < 10; i++) sum[i] = (10 * sum[i] + val) % i;
            };
            auto update_dp = [&](){
                vector<vector<int>> temp(10, vector<int>(10));
                for(int i = 1; i < 10; i++){
                    for(int j = 0; j < i; j++)  temp[i][(10 * j) % i] += dp[i][j];
                }
                dp = temp;
            };
    
            for(auto ch: s){
                int digit = ch - '0';
                update_sum(digit);
                update_dp();
                if(digit > 0) ans += dp[digit][sum[digit]];
    
                for(int i = 1; i < 10; i++)  dp[i][sum[i]]++;
            }
            return ans;
        }
    };