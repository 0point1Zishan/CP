class Solution {
private:
    bool isPos(int i, int n, int sz, string& s, unordered_map<string, int>& mp, vector<int>& dp){
        if(i == n) return true;
        if(dp[i] != -1) return dp[i];

        for(int j = i; j < n; j++){
            if(mp[s.substr(i, j-i+1)] && isPos(j+1, n, sz, s, mp, dp)){
                dp[i] = true;
                return true;
            }
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), m = wordDict.size();
        vector<int> dp(n+1, -1);

        unordered_map<string, int> mp;
        for(int i = 0; i < m; i++) mp[wordDict[i]]++;

        return isPos(0, n, m, s, mp, dp);
    }
};