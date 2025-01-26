#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
    int n;  cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    int ans = accumulate(v.begin(), v.end(), 0);
    while(1){
        if(v.size() == 1){
            cout << max(v[0], ans) << "\n";
            return;
        }
        vector<int> d;
        for(int i = 0; i < v.size()-1; i++) d.push_back(v[i+1] - v[i]);

        if(accumulate(d.begin(), d.end(), 0) < 0){
            for(int i = 0; i < d.size(); i++) d[i] *= -1;
        }

        reverse(d.begin(), d.end());
        v = d;        

        int sum = accumulate(v.begin(), v.end(), 0);
        ans = max(ans, sum);
    }
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