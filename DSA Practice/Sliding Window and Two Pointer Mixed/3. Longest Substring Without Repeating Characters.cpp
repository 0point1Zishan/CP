class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> fre(256, -1);
        int l = 0, r = 0, mx = 0;
        while(r < n){
            if(fre[s[r]] != -1)  l = max(l, fre[s[r]] + 1);

            fre[s[r]] = r;
            mx = max(mx, r - l + 1);
            r++;
        }
        return mx;
    }
};