class Solution {
    private:
        void constructLps(string& needle, vector<int>& lps){
            int len = 0;
            lps[0] = 0;
    
            int i = 1;
            while(i < needle.size()){
                if(needle[i] == needle[len]){
                    len++;
                    lps[i] = len;
                    i++;
                }
                else{
                    if(len == 0){
                        lps[i] = 0;
                        i++;
                    }
                    else         len = lps[len-1];
                }
            }
        }
    public:
        int strStr(string haystack, string needle) {
            int n = haystack.size(), m = needle.size();
            vector<int>lps(m, 0), res;
            constructLps(needle, lps);
            
    
            int i = 0, j = 0;
            while(i < n){
                if(haystack[i] == needle[j]){
                    j++;
                    i++;
                    if(j == m) return i - m;
                }
                else{
                    if(j != 0) j = lps[j-1];
                    else i++;
                }
            }
            return -1;
        }
    };