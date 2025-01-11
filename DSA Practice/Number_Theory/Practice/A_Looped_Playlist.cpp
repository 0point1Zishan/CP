#include <bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, p;     cin >> n >> p;
    vector<int> v(n);

    int sum = 0;
    for(int i = 0; i < n; i++)  cin >> v[i], sum += v[i];
    

    int ans = (p - v[0]) / sum * n + 1;
    int k = (p - v[0]) / sum * sum + v[0];

    int l = 0, pos = 0;
    if(k >= p)   l = pos = 0;
    else{
        for(int i = n - 1; i >= 0; i--){
            k += v[i];
            ans++;
            if(k >= p){
                pos = l = i;
                break;
            }
        }
    }

    int sz = ans;
    for(int i = 1; i < n; i++){

        k += v[i];
        sz++;

        while(k >= p){
            k -= v[l++];
            l %= n;
            sz--;
        }
        if(sz + 1 < ans)   pos = (l - 1 + n) % n,   ans = sz + 1;
        
    }

    cout << pos + 1 << " " << ans << "\n";
}

signed main(){
    fast;
    int t = 1;
    //cin >> t;
    while(t--){solve();}
    return 0;
}
