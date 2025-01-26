class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), l = 0, r = 0, mx = 0, mxLen = 0;
        vector<int> fre(26, 0);

        while(r < n){
            fre[s[r] - 'A']++;
            mx = max(mx, fre[s[r] - 'A']);

            if((r - l + 1) - mx > k){
                fre[s[l] - 'A']--;
                mx = max(mx, fre[s[l] - 'A']);
                l++;
            }

            if((r - l + 1) - mx <= k) mxLen = max(mxLen, r - l + 1);
            r++;
        }
        return mxLen;
    }
};