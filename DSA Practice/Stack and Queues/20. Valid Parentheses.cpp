class Solution {
private:
    bool isValid(char a, char b){
        if(a == '(' && b == ')') return true;
        if(a == '{' && b == '}') return true;
        if(a == '[' && b == ']') return true;
        return false;
    }
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(!st.empty() && isValid(st.top(), s[i])){
                st.pop();
            }
            else st.push(s[i]);
        }
        return st.empty();
    }
};