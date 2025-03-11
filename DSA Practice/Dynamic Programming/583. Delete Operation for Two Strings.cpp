class Solution {
    public:
        int minDistance(string s, string t) {
            int n = s.size(), m = t.size();
            vector<int> pre(m+1, 0), cur(m+1, 0);
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    if(s[i-1] == t[j-1]) cur[j] = 1 + pre[j-1];
                    else cur[j] = max(pre[j], cur[j-1]);
                }
                pre = cur;
            }
            return (m+n) - (2 * pre[m]);
        }
    };