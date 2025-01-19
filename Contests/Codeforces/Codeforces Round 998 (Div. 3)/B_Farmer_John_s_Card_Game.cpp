#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
    int n, m;   cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));

    vector<pair<int, int>> ans;
    bool ist = true;
    for(int i = 0; i < n; i++){
        vector<int>t(m);
        for(int j = 0; j < m; j++) cin >> t[j];
        sort(t.begin(), t.end());

        if(ist){
            for(int j = 1; j < m; j++){
                if(t[j] - t[j-1] != n){
                    ist = false;
                    break;
                }
            }
        }
        v.push_back(t);
        ans.push_back({t[0], i + 1});
    }
    if(!ist) cout << -1 << "\n";
    else{
        sort(ans.begin(), ans.end());
        for(int i = 0; i < n; i++)  cout << ans[i].second << " ";
        cout << "\n";
    }
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}