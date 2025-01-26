#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
    int n;  cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    for(int i = 0; i < n; i++){
        int mx = max(n-i, i+1);
        if(mx*2 - 1 > v[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}