#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
    string s;   cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1')cnt++;
    }cout << cnt << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}