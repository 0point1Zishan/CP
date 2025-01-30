class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size(), l = 0, r = 0, mn = n + 1, st = -1;

        vector<int> fre(128, 0);
        for(int i = 0; i < m; i++)  fre[t[i]]++;

        while(r < n){
            if(fre[s[r]] > 0) m--;
            fre[s[r]]--;

            while(m == 0){
                if((r - l + 1) < mn)   st = l,   mn = r - l + 1;
                fre[s[l]]++;
                if(fre[s[l]] > 0) m++;
                l++;
            }
            r++;
        }
        return (st == -1)  ? ""   :   s.substr(st, mn);
    }
};