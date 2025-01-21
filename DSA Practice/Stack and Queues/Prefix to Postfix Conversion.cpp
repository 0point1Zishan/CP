class Solution {
  private:
    bool isOperand(char c){
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
  public:
    string preToPost(string s) {
        stack<string> st;
        int n = s.size();
        for(int i = n-1; i >= 0; i--){
            if(isOperand(s[i])) st.push(string(1,s[i]));
            else{
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();
                
                string curr = a + b + s[i];
                st.push(curr);
            }
        }
        return st.top();
    }
};