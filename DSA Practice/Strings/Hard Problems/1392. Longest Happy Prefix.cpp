class Solution {
    private:
        void kmp(string& a, vector<int>& lps){
            int len = 0, i = 1, n = a.size();
            
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
        }
    public:
        string longestPrefix(string s) {
            int n = s.size();
            vector<int> lps(n);
            kmp(s, lps);
            int val = lps[n-1];
            string ans = s.substr(0, val);
            return ans;
        }
    };