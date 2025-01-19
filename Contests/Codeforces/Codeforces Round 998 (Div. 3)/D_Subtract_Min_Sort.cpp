#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
    int n;  cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    for(int i = 0; i < n-1; i++){

        if(v[i] > v[i+1]){
            cout << "NO\n";
            return;
        }
        v[i] = 0;
        v[i+1] -= v[i];
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