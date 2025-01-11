#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, m;   cin >> n >> m;
    
    int l = max(0LL, n - m), r = n + m;

    int ans = 0;
    for(int i = 0; i < 31; i++){

        if((r / (1 << i)) & 1){
            ans |= (1 << i);
        }
        else if(l == 0 && ((r / (1 << i)) > 0)){
            ans |= (1 << i);
        }
        else if((l / (1 << i)) != (r / (1 << i))){
            ans |= (1 << i);
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