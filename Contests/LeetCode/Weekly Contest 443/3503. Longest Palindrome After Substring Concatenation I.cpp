class Solution {
    private:
        bool isPalindrome(string& s){
            int l = 0, r = s.size()-1;
            while(l < r){
                if(s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        }
    public:
        int longestPalindrome(string s, string t) {
    
            vector<string> sSub, tSub; 
            int mx = 1;
            for(int i = 0; i < s.size(); i++){
                string str = "";
                for(int j = i; j < s.size(); j++){
                    str += s[j];
                    sSub.push_back(str);
                    if(mx < str.size() && isPalindrome(str)) mx = str.size();
                }
            }
    
            for(int i = 0; i < t.size(); i++){
                string str = "";
                for(int j = i; j < t.size(); j++){
                    str += t[j];
                    tSub.push_back(str);
                    if(mx < str.size() && isPalindrome(str)) mx = str.size();
                }
            }
    
            for(int i = 0; i < sSub.size(); i++){
                for(int j = 0; j < tSub.size(); j++){
                    if(mx < sSub[i].size() + tSub[j].size()){
                        string k = sSub[i];
                        k += tSub[j];
                        if(isPalindrome(k))    mx = sSub[i].size() + tSub[j].size();
                    }
                }
            }
            return mx;
        }
    };