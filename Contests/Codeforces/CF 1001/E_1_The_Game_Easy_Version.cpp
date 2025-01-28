#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

struct FenwickTree{
    vector<int> ft;
    FenwickTree(int n){
        ft.resize(n);
    }

    FenwickTree(vector<int> v){
        ft.assign(v.size(), 0);
        for(int i = 0; i < v.size(); i++){
            ft[i] += v[i];
            if((i | (i + 1)) < v.size()){
                ft[i | (i + 1)] += ft[i];
            }
        }
    }

    void build(vector<int>& v){
        ft.assign(v.size(), 0);
        for(int i = 0; i < v.size(); i++){
            ft[i] += v[i];
            if((i | (i + 1)) < v.size()){
                ft[i | (i + 1)] += ft[i];
            }
        }
    }

    int sum(int r){
        int idx = r, ans = 0;
        while(idx >= 0){
            ans += ft[idx];
            idx = (idx & (idx + 1)) - 1;
        }
        return ans;
    }

    int sum(int l, int r){
        return sum(r) - sum(l - 1);
    }

    void add(int i, int v){
        int idx = i;
        while(idx < ft.size()){
            ft[idx] += v;
            idx = idx | (idx + 1);
        }
    }
};

void dfs(vector<vector<int>>& adj, vector<int>& tin, vector<int>& tout, int& time, int v, int par){
    tin[v] = time++;
    for(auto x : adj[v]){
        if(x != par) dfs(adj, tin, tout, time, x, v);
    }
    tout[v] = time;
}

void solve(){
    int n; cin >> n;
    vector<int> col(n + 1);
    for(int i = 1; i <= n; i++) cin >> col[i];

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int time = 0;
    vector<int> tin(n + 1), tout(n + 1);
    dfs(adj, tin, tout, time, 1, 0);

    FenwickTree ft(n);
    vector<vector<int>> ai(n + 1);
    for(int i = 1; i <= n; i++){
        ai[col[i]].push_back(i);
    }

    int sum = 0;
    for(int i = n; i >= 1; i--){
        for(auto x : ai[i]){
            if(ft.sum(tin[x], tout[x] - 1) != sum){
                cout << x << "\n";
                return;
            }
        }
        for(auto x : ai[i]){
            ft.add(tin[x], 1);
            sum++;
        }
    }
    cout << 0 << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
