#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector<int> zigzagTraversal(vector<vector<int>>& grid) {
    vector<int> ans;
    int n = grid.size(), m = grid[0].size();
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            for(int j = 0; j < m; j++){
                if(j % 2 == 0) ans.push_back(grid[i][j]);
            }
        }
        else{
            for(int j = m-1; j >= 0; j--){
                if(j % 2 == 1) ans.push_back(grid[i][j]);
            }
        }
    }
    return ans;
}

void solve(){
    int n, m;   cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> v[i][j];
    }

    vector<int> ans = zigzagTraversal(v);
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << '\n';
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}