#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

bool isOperand(char c){
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

map<char, int> mp{
    {'^',3},
    {'*', 2},
    {'/', 2},
    {'+', 1},
    {'-', 1},
    {'(', 0}
};

string infixToPostfix(string s){
    stack<char> st;
    string ans = "";

    int n = s.size();
    for(int i = 0; i < n; i++){
        char c = s[i];
        if(isOperand(c)){
            ans += c;
        }
        else if(c == '(') st.push(c);
        else if(c == ')'){
            while(st.top() != '('){
                ans += st.top();
                st.pop();
            }st.pop();
        }
        else{
            while(!st.empty() && mp[st.top()] >= mp[c]){
                ans += st.top();
                st.pop();
            }st.push(c);
        }
    }
    while(!st.empty() && st.top() != ')'){
        ans += st.top();
        st.pop();
    }
    return ans;
}   

void solve(){
    string s;   cin >> s;
    cout << infixToPostfix(s) << "\n";
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}