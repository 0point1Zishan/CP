#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
    int n;  cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    int ans = accumulate(v.begin(), v.end(), 0LL);
    while(v.size() > 1){
        for(int i = 0; i < v.size()-1; i++){
            v[i] = v[i+1] - v[i];
        }
        v.pop_back();
        ans = max(ans, abs(accumulate(v.begin(), v.end(), 0LL)));
    }
    cout << max(ans, v[0]) << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}