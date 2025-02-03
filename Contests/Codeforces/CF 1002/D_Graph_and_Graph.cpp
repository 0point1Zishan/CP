#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
    int n, s1, s2;  cin >> n >> s1 >> s2;
    vector<vector<int>> adj1(n), adj2(n);
    vector<pair<int, int> > g1;
    set<pair<int, int>> g2;

    s1--, s2--;
    int m1; cin >> m1;
    for(int i = 0; i < m1; i++){
        int u, v;   cin >> u >> v;
        if(u > v) swap(v, u);
        u--, v--;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
        g1.push_back({u, v});
    }

    int m2; cin >> m2;
    for(int i = 0; i < m2; i++){
        int u, v;   cin >> u >> v;
        if(u > v) swap(v, u);
        u--, v--;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
        g2.insert({u, v});
    }

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    set<pair<int, pair<int, int>>> st;
    st.insert({0, {s1, s2}});
    dp[s1][s2] = 0;

    while(st.size()){

        auto v = *st.begin();
        st.erase(st.begin());
        int x = v.second.first,  y = v.second.second, dist = v.first;

        for(auto it1 : adj1[x]){

            for(auto it2 : adj2[y]){

                if(dp[it1][it2] > dist + abs(it1 - it2)){
                    st.erase({dp[it1][it2], {it1, it2}});
                    dp[it1][it2] = dist + abs(it1 - it2);
                    st.insert({dp[it1][it2], {it1, it2}});
                }
            }
        }
    }
    int ans = INT_MAX;
    for(auto it: g1){
        if(g2.find(it) != g2.end())   ans = min(ans, dp[it.first][it.first]);
    }
    cout << ((ans == INT_MAX)  ?  -1   :  ans) << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}