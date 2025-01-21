#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

bool isOperand(char c){
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

string postfixToInfix(string s){
    stack<string> st;
    int n = s.size();

    for(int i = 0; i < n; i++){
        if(isOperand(s[i]))  st.push(string(1,s[i]));
        else{
            string curr = s[i] + st.top() + ')';
            st.pop();
            curr = '(' + st.top() + curr;
            st.pop();
            st.push(curr);
        }
    }
    return st.top();
}

void solve(){
    string s;   cin >> s;
    cout << postfixToInfix(s) << "\n";
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}