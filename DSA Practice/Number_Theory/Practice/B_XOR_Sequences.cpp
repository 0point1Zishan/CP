#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int x, y;   cin >> x >> y;

    int i = 0;
    for(; i < 31; i++){
        bool find = ((((x >> i) & 1) == 0) && (((y >> i) & 1) == 1)) || (((x >> i) & 1) == 1) && (((y >> i) & 1) == 0);
        if(find){
            break;
        }
    }
    cout << (1 << i) << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}