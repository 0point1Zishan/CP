#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;

    vector<int> curr(21, 0), pre(21,0);
    int k = 0;

    for(int i = 1; i <= n; i++){
        int x;  cin >> x;
        k |= x;

        for(int j = 0; j <= 20; j++){
            if((x >> j) & 1){
                curr[j] = max(i - pre[j], curr[j]);
                pre[j] = i;
            }
        }
    }   

    int ans = 1;
    for(int i = 0; i <= 20; i++){
        if((k >> i) & 1){
            curr[i] = max(curr[i], n + 1 - pre[i]);
            ans = max(ans, curr[i]);
        }
    }
    cout << ans << "\n";


}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}