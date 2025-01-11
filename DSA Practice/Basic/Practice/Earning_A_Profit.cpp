#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, a;   cin >> n >> a;
    vector<pair<int,int> > v;
    for(int i = 0; i < n; i++)  cin >> v[i].first >> v[i].second;

    int ans = 0;
    for(int i = 0; i < n; i++){
        int sum = 0, mx = v[i].second, mn = v[i].second;

        for(int j = i; j < n; j++){
            sum += v[j].first;
            mx = max(mx, v[j].second);
            mn = min(mn, v[j].second);

            int profit = (a * (j-i+1)) - sum - ((mx - mn)*(mx -mn));
            ans = max(ans, profit);
        }
    }
    cout << ans << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}