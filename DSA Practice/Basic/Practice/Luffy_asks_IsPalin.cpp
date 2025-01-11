#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, q;   cin >> n >> q;
    string s;   cin >> s;

    vector<vector<int>> v(n+1, vector<int>(26, 0));
    vector<vector<int>> pf(n+1, vector<int>(26, 0));
    for(int i = 1; i <= n; i++){
        v[i][s[i-1]-'a']++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 26; j++){
            pf[i][j] = v[i][j] + pf[i-1][j];
        }
    }

    while(q--){
        int l, r;   cin >> l >> r;
        int odd = 0;
        for(int i = 0; i < 26; i++){
            if(pf[r][i] - pf[l-1][i] & 1) odd++;
        }
        if(odd > 1) cout << "NO" << "\n";
        else        cout << "YES" << "\n";
    }
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}