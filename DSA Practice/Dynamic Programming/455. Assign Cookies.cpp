class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int cnt = 0;
        int j = 0;
        for(int i = 0; i < n; i++){
            while(j < m && g[i] > s[j]) j++;
            if(j < m && g[i] <= s[j]) cnt++, j++;
            else if(j >= m) return cnt;
        }
        return cnt;
    }
};