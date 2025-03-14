class Solution {
    public:
        bool isMatch(string s, string p) {
            int n = s.size(), m = p.size();
            
            vector<bool> pre(m+1, false), cur(m+1, false);
            pre[0] = true;
            for(int i = 1; i <= m; i++){
                bool f = true;
                for(int j = 1; j <= i; j++){
                    if(p[j-1] != '*') f = false;
                }
                pre[i] = f;
            }
    
            for(int i = 1; i <= n; i++){
                cur[0] = false;
                for(int j = 1; j <= m; j++){
                    if(s[i-1] == p[j-1] || p[j-1] == '?') cur[j] = pre[j-1];
                    else if(p[j-1] == '*')                cur[j] = cur[j-1] || pre[j];
                    else cur[j] = false;
                }
                pre = cur;
            }
            return pre[m];
        }
    };