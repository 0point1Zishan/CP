#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
    int n;  cin >> n;
    set<int> st1, st2;

    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        st1.insert(x);
    }

    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        st2.insert(x);
    }

    cout << ((st1.size() + st2.size() < 4) ?  "NO"  :  "YES" )<< "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}