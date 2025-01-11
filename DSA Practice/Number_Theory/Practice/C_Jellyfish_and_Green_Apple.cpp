#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int k, m;   cin >> k >> m;
    k %= m;

    int op = 0;
    double cnt = k, num = 1;

    for(int i = 0; i <= 32; i++){

        if(cnt == 0){
            cout << op << "\n";
            return;
        }

        op += cnt;
        int total = cnt * 2;
        total %= m;
        cnt = total;
        num /= 2;
    }       

    cout << -1 << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}