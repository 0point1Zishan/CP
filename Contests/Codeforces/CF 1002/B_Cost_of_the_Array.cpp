#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
    int n, k;  cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    if(n == k){
        int j = 1;
        for(int i = 1; i < n; i += 2){
            if(v[i] != j){
                cout << j << "\n";
                return;
            }j++;
        }
        cout << n/2 + 1 << "\n";
        return;
    }
    int cnt = 0;
    for(int i = 1; i < n - k + 2; i++){
        if(v[i] == 1) cnt++;
    }
    cout << ((cnt == n - k + 1) ?  2 :  1) << "\n";
    
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}