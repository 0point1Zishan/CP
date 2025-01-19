#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
    int n, k;   cin >> n >> k;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        mp[x]++;
    }

    int p = k / 2;
    int s = 1;
    bool isExtra = false;
    int ans = 0;
    while(s <= p){

        if(mp[s] && mp[k - s]){
            int cnt = min(mp[s], mp[k-s]);
            if(s == k - s) cnt /= 2;
            if(mp[s] != mp[k-s]) isExtra = true;
            ans += cnt;
        }
        s++;
    }
    
    if((n&1) && (!isExtra)) ans--;
    cout << ans << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}