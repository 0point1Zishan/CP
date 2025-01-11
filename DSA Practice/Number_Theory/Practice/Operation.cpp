#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int l, r;   cin >> l >> r;

    int x = 1;
    while(x < l)     x *= 2;
    
    int ans = 0;
    while(x <= r){
        ans += x;
        x *= 2;
    }
    cout << ans << "\n";
}

signed main(){
    fast;
    int t = 1;
    //cin >> t;
    while(t--){solve();}
    return 0;
}