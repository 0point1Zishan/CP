#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void generateString(int sz, string& s, int n){
    if(n == sz){
        cout << s << " ";
        return;
    }

    if(s[n-1] == '1'){
        s[n] = '0';
        generateString(sz, s, n+1);
    }

    if(s[n-1] == '0'){
        s[n] = '1';
        generateString(sz, s, n+1);
        s[n] = '0';
        generateString(sz, s, n+1);
    }
}

void generateAllBinary(int n){
    if(n <= 0) return;
    string s(n, 'a');

    s[0] = '0';
    generateString(n, s, 1);
    s[0] = '1';
    generateString(n, s, 1);
}   

void solve(){
    int n;  cin >> n;
    generateAllBinary(n);
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}