#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, t, m;    cin >> n >> t >> m;
    if(n - (t + m) < abs(t - m)) cout << "Yes";
    else  cout << "No";
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){solve();}
    return 0;
}