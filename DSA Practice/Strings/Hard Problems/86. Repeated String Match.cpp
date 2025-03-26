class Solution {
    private:
        void constructLps(string& pat, vector<int>& lps){
            int len = 0, i = 1, n = pat.size();
            
            while(i < n){
                if(pat[i] == pat[len]){
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
        bool search(string& pat, string& txt) {
            int n = txt.size(), m = pat.size(), i = 0, j = 0;
            vector<int> lps(m, 0);
            constructLps(pat, lps);
            
            while(i < n){
                if(txt[i] == pat[j]){
                    i++;
                    j++;
                    if(j == m) return true;
                }
                else{
                    if(j != 0) j = lps[j-1];
                    else i++;
                }
            }
            return false;
        }
    public:
        int repeatedStringMatch(string a, string b) {
            int cnt = 1;
            string temp = a;
            while(temp.size() < b.size()){
                temp += a;
                cnt++;
            }
            if(temp == b || search(b, temp)) return cnt;
            temp += a;
            if(search(b, temp))     return cnt+1;
    
            return -1;
        }
    };