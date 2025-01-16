class Solution {
  private:
    int subCount(string s){
        int n = s.size();
        vector<int> dp(n+1, 0);
        vector<int> mp(26, -1);
        
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i] = 2 * dp[i-1];
            if(mp[s[i-1] - 'a'] != -1){
                dp[i] -= dp[mp[s[i-1] - 'a']];
            }
            mp[s[i-1] - 'a'] = i-1;
        }

        return dp[n];
    }
  public:
    string betterString(string str1, string str2) {
        // code heref
        int a = subCount(str1);
        int b = subCount(str2);
        return (a >= b)   ?    str1  :  str2;
    }
};