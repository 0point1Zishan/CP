#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

unordered_map<int, int> dp;

void solve(){

    int m;  cin >> m;
    vector<int> bit(31, 0);

    auto isPos = [&](vector<int> &v, int &x){
        for(int i = 30; i >= 0; i--){

            if(v[i] && ((1 << i) <= x)){
                int k = x / ((1 << i));
                int mn = min(k, v[i]);
                x -= (mn * (1 << i));
            }
        }
        return x == 0;
    };

    while(m--){
        int op, x;  cin >> op >> x;
        if(op == 1){
            bit[x]++;
        }
        else{
            if(dp[x] || isPos(bit, x)){
                cout << "YES\n";
                dp[x]++;
            }
            else cout << "NO\n";
        }
    }

}

signed main(){
    fast;
    int t = 1;
    //cin >> t;
    while(t--){solve();}
    return 0;
}