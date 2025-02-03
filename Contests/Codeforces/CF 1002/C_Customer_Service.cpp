#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
    int n;  cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    vector<int> ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)  cin >> v[i][j];

        ans.push_back(0);
        while(v[i].size() && v[i].back() == 1){
            ans.back()++;
            v[i].pop_back();
        }
    }
    sort(ans.begin(), ans.end());

    int res = 0, i = 0;
    while(i < n){
        i = lower_bound(ans.begin()+i, ans.end(), res+1) - ans.begin();
        if(i == n)   break;
        res++;
        i++;
    }
    cout << min(res+1, n) << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}