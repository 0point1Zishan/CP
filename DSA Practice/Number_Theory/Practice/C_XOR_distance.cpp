#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int a, b, r;    cin >> a >> b >> r;
    if(a < b) swap(a, b);

    bool found = false;
    for(int i = 63; i >= 0; i--){

        if(b >= a) break;

        if( ((a >> i) & 1) == ((b >> i) & 1)) continue;

        else if(!found) found = true;
        else if( ((a >> i) & 1) && ((1LL << i) <= r)){
            r -= (1LL << i);
            a -= (1LL << i);
            b += (1LL << i);
        }
    }

    cout << abs(a - b) << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}