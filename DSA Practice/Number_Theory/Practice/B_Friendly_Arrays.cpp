#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, m;  cin >> n >> m;
    vector<int> a(n), b(m);
    int bOr = 0, mn = 0, mx = 0;
    for(int i = 0; i < n; i++)     cin >> a[i], mx ^= a[i];
    for(int i = 0; i < m; i++){
        cin >> b[i];
        bOr |= b[i];
    }

    for(int i = 0; i < n; i++)  mn ^= (a[i] | bOr);

    if(n & 1) swap(mn, mx);
    cout << mn << " " << mx << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}