#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int maximumAmount(vector<vector<int>>& coins){
    int n=coins.size(),m=coins[0].size();
    using ll=long long;
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(m,vector<ll>(3,INT_MIN)));
    dp[0][0][0]=coins[0][0];
    dp[0][0][1]=max(0,coins[0][0]);
    dp[0][0][2]=dp[0][0][1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0&&j==0)continue;
            if(i>0){
                for(int k=0;k<3;k++)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+coins[i][j]);
                for(int k=0;k<2;k++)dp[i][j][k+1]=max(dp[i][j][k+1],dp[i-1][j][k]);
            }
            if(j>0){
                for(int k=0;k<3;k++)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+coins[i][j]);
                for(int k=0;k<2;k++)dp[i][j][k+1]=max(dp[i][j][k+1],dp[i][j-1][k]);
            }
        }
    }
    ll ret=max({dp[n-1][m-1][0],dp[n-1][m-1][1],dp[n-1][m-1][2]});
    return int(ret);
}

void solve(){
    int n, m;   cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> v[i][j];
    }
    cout << maximumAmount(v) << "\n";
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}