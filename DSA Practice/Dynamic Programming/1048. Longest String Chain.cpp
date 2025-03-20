class Solution {
    public:
        int longestStrChain(vector<string>& words) {
            int n = words.size();
            sort(words.begin(), words.end(), [&](string &a, string &b){
                return a.size() < b.size();
            });
    
            auto isPos = [&](string &a, string &b){
                if(a.size() != b.size() + 1) return false;
                int i = 0, j = 0;
                while(i < a.size()){
                    if(j < b.size() && a[i] == b[j]) i++, j++;
                    else i++;
                }
                return (i == a.size() && j == b.size());
            };
            
            vector<int> dp(n, 1);
            int mx = 1;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < i; j++){
                    if(isPos(words[i], words[j]) && 1 + dp[j] > dp[i]){
                        dp[i] = dp[j] + 1;
                    }
                }
                mx = max(mx, dp[i]);
            }
            return mx;
        }
    };