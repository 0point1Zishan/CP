class Solution {
    public:
        int numDistinct(string s, string t) {
            int n = s.size(), m = t.size();
    
            vector<double> pre(m+1, 0), cur(m+1, 0);
            pre[0] = 1, cur[0] = 1;
    
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    if(s[i-1] == t[j-1]) cur[j] = pre[j-1] + pre[j];
                    else cur[j] = pre[j];
                }
                pre = cur;
            }
            return (int)cur[m];
        }
    };