class Solution {
public:
    bool checkValidString(string s) {
        int a = 0, b = 0;
        for(int i = 0; i < s.size(); i++){

            if(s[i] == '(')      a++, b++;
            else if(s[i] == ')') a--, b--;
            else                 a++, b--;
            
            if(a < 0) return false;
            if(b < 0) b = 0; 
        }
        return b == 0;
    }
};