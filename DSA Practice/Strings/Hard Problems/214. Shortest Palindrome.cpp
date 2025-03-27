class Solution {
    public:
        string shortestPalindrome(string s) {
            int sz = s.size();
            string a = s, b = a;
            reverse(b.begin(), b.end());
            a += "*" + b;
    
            int len = 0, i = 1, n = a.size();
            vector<int> lps(n);
              
            while(i < n){
                if(a[i] == a[len]){
                    len++;
                    lps[i] = len;
                    i++;
                }
                else{
                    if(len == 0){
                        lps[i] = 0; i++;   
                    }
                    else len = lps[len - 1];
                }
            }
            string ans = b.substr(0, sz - lps[n-1]) + s;
            return ans;
        }
    };