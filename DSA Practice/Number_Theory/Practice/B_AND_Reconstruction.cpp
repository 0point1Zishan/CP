#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    vector<int> v(n-1);
    for(int i = 0; i < n-1; i++)  cin >> v[i];

    if(n == 2){
        cout << v[0] << " " << v[0] << "\n";
        return;
    }
    vector<int> ans(n);
    ans[0] = v[0]; ans.back() = v.back();

    for(int i = 0; i < n-2; i++){
        ans[i+1] = (v[i] | v[i+1]);
    }
    
    for(int i = 0; i < n-1; i++){
        if((ans[i] & ans[i+1]) != v[i]){
            cout << -1 << "\n";
            return;
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}