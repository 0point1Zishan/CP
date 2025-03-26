class Solution {
    public:
        int minAddToMakeValid(string s) {
            int l = 0, r = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == '(') l++;
                else if(l && s[i] == ')') l--;
                else r++;
            }
            return l + r;
        }
    };