class Solution {
    private:
        bool isPalindrom(string &str, int s, int e){
            while(s <= e){
                if(str[s] != str[e]) return false;
                s++;  e--;
            }
            return true;
        }
    public:
        int minCut(string str) {
            int n = str.size();
            vector<int> dp(n+1, 0);
            for(int i = n-1; i >= 0; i--){
                int mn = INT_MAX;
                for(int idx = i; idx < n; idx++){
                    if(isPalindrom(str, i, idx)){
                        int part = 1 + dp[idx + 1];
                        mn = min(mn, part);
                    }
                }
                dp[i] = mn;
            }
            return dp[0]-1;
        }
    };