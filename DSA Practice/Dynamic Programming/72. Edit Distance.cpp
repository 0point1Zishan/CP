class Solution {
    public:
        int minDistance(string s, string t) {
    
            n = s.size(), m = t.size();
            vector<int> pre(m+1, 0), cur(m+1, 0);
            for(int j = 0; j <= m; j++) pre[j] = j;
    
            for(int i = 1; i <= n; i++){
                cur[0] = i;
                for(int j = 1; j <= m; j++){
                    if(s[i-1] == t[j-1]) cur[j] = pre[j-1];
                    else{
                        cur[j] = 1 + min({cur[j-1], pre[j], pre[j-1]});
                    }
                }
                pre = cur;
            }
            return pre[m];
        }
    };