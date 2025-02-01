#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

string findValidPair(string s) {
    vector<int> v(11, 0);
    for(int i = 0; i < s.size(); i++)     v[s[i] - '0']++;
    
    for(int i = 1; i < s.size(); i++){
        if(v[s[i] - '0'] == s[i] - '0' && v[s[i-1] - '0'] == s[i-1] - '0' && s[i] != s[i-1]){
            string ans = "";
            ans += s[i-1];
            ans += s[i];
            return ans;
        }
    }
    return "";
}

void solve(){
    string s;   cin >> s;
    cout << findValidPair(s) << "\n";
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}