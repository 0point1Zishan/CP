#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
    int n, x;   cin >> n >> x;
    vector<int> v(n);
    for(auto &i: v) cin >> i;

    int mx = v[0];
    for(int i = 1; i < n; i++){
        mx = max(mx, v[i] - v[i-1]);
    }
    mx = max(mx, 2 * (x - v.back()));
    cout << mx << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}