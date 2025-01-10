class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int mx = 0, n = s.size();

        for(int i = 0; i < n; i++){
            int l = i, r = i;
            while(l > 0 && r < n-1 && s[l-1] == s[r+1]) l--, r++;
            if(r - l + 1 > mx){
                mx = r - l + 1;
                ans = s.substr(l, r - l + 1);
            }
            if(i < n-1 && s[i+1] == s[i]){
                int l = i, r = i+1;
                while(l > 0 && r < n-1 && s[l-1] == s[r+1]) l--, r++;
                if(r - l + 1 > mx){
                    mx = r - l + 1;
                    ans = s.substr(l, r-l+1);
                }
            }
        }
        return ans;
    }
};