class Solution {
  private:
    bool isOpertor(char c){
        return c == '^' || c == '*' || c == '/' || c == '+' || c == '-';
    }
  public:
    string preToInfix(string s) {
        // Write your code here
        
        stack<string> st;
        int n = s.size();
        for(int i = n-1; i >= 0; i--){
            if(isOpertor(s[i])){
                string a = st.top();
                st.pop();
                
                string b = st.top();
                st.pop();
                
                string curr = '(' + a + s[i] + b + ')';
                st.push(curr);
            }
            else st.push(string(1, s[i]));
        }
        return st.top();
    }
};