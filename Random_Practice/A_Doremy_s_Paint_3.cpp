#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        mp[x]++;
    }

    int a = -1, b = -1;
    int t = 2;
    for(auto it: mp){
        if(t == 2) a = it.second;
        else if(t == 1) b = it.second;
        else break;
        t--;
    }

    if(mp.size() == 1 || (mp.size() == 2 && abs(a - b) <= 1)) cout << "Yes\n";
    else cout << "No\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}