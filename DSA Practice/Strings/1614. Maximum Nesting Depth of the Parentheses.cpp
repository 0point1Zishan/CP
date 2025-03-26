class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int mx = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == ')') cnt--;
            else if(s[i] == '(') cnt++, mx = max(mx, cnt);
        }
        return mx;
    }
};