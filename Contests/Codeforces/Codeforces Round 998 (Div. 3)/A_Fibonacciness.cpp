#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
    int a1, a2, a4, a5;  cin >> a1 >> a2 >> a4 >> a5;

    int mx = 0;
    int a3 = -200;
    while(a3 <= 200){
        int cnt = 0;
        if(a1 + a2 == a3) cnt++;
        if(a2 + a3 == a4) cnt++;
        if(a3 + a4 == a5) cnt++;

        mx = max(mx, cnt);
        a3++;
    }

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