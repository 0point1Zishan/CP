class Solution {
  private:
    bool isOperand(char c){
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
  public:
    string postToPre(string s) {
        // Write your code here
        stack<string> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(isOperand(s[i])) st.push(string(1,s[i]));
            else{
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();
                
                string curr = s[i] + b + a;
                st.push(curr);
            }
        }
        return st.top();
    }
};