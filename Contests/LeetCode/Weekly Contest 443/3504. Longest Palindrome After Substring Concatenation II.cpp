class Solution {
    private:
        bool isPalin(string& s, int l, int r){
            while(l < r){
                if(s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        }
        void longestPalin(string& s, vector<int>& v){
            int n = s.size();
            for(int i = 0; i < n; i++){
                for(int j = n-1; j >= i && v[i] < 2; j--){
                    v[i] = isPalin(s, i, j)   ?   j - i + 1  :   1;
                }
            }
        }
    public:
        int longestPalindrome(string s, string t) {
            reverse(t.begin(), t.end());
            int n = s.size(), m = t.size(), ans = 0;
    
            vector<int> mxS(n+1, 0), mxT(m+1, 0);
            longestPalin(s, mxS);
            longestPalin(t, mxT);
    
            vector<vector<int>> dp(n+2, vector<int>(m+1, 0));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
    
                    if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
    
                    int mxMid = 0;
                    if(s[i] == t[j]) mxMid = max(mxS[i+1], mxT[j+1]);
                    else             mxMid = max(mxS[i], mxT[j]);
    
                    int cur = (2 * dp[i+1][j+1]) + mxMid;
                    ans = max(ans, cur);
                }
            }
            return ans;
        }
    };