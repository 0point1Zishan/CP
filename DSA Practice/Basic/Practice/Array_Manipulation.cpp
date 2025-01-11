#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, m;   cin >> n >> m;
    vector<int> v(n+2);
    while(m--){
        int l, r, a;    cin >> l >> r >> a;
        v[l] += a;
        v[r+1] -= a;
    }

    vector<int> pf(n+2);
    for(int i = 1; i <= n; i++){
        pf[i] = v[i] + pf[i-1];
    }
    
    cout << *max_element(pf.begin(), pf.end());

}

signed main(){
    fast;
    int t = 1;
    //cin >> t;
    while(t--){solve();}
    return 0;
}