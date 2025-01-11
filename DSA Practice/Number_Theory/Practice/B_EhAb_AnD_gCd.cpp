#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            cout << i << " " << n - i << "\n";
            return;
        }
    }
    cout << 1 << " " << n - 1 << "\n";


}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}