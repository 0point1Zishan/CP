class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";
        int n = s.size();
        for(int i = 0; i < n; i++){
            ans += s[i];
            if(st.empty() && s[i] == '(') ans.pop_back();
            if(s[i] == '(') st.push(s[i]);
            else if(!st.empty() && st.top() == '(' && s[i] == ')'){
                st.pop();
                if(st.empty()) ans.pop_back();
            }
        }
        return ans;
    }
};