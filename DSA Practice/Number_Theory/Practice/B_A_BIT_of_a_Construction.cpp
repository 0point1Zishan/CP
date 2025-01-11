#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, k;   cin >> n >> k;
    vector<int> v(n);

    int j = 0;
    int mx = 31 - __builtin_clz(k);

    v[j++] = (1 << mx) -1;
    if(j < n) v[j] = k - ((1 << mx) - 1);
    else v[0] += k - ((1 << mx) - 1);

    for(int i = 0; i < n; i++) cout << v[i] << " ";
    cout << "\n";   
    
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}