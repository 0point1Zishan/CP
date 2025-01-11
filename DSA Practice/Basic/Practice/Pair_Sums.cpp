#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, k;   cin >> n >> k;
    vector<int> fr(2e6+5);
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        fr[x]++;
    }

    for(int i = 0; i <= k/2; i++){

        if(fr[i] > 0 && fr[k-i] > 0){

            if( (i != k-i) || ((i == k-i) && fr[i] > 1)){
                cout << "YES";
                return;
            }
        }
    }cout << "NO";
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){solve();}
    return 0;
}