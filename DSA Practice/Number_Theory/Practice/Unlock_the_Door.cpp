#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int fact[N];

int binExp(int x, int p, int m){
    int res = 1;
    x %= p;

    while(p){
        if(p & 1)  res = (res * x) % m;

        x = (x * x) % m;

        p >>= 1;
    }
    return res;
}

void solve(){

    fact[0] = 1;
    for(int i = 1; i <= N; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }

    int q;  cin >> q;
    while(q--){
        int n, k;   cin >> n >> k;
        int ans = (fact[n] * fact[k]) % MOD;
        int den = (fact[k - n] * fact[n] ) % MOD;
        cout << (ans * binExp(den, MOD-2, MOD)) % MOD << "\n";
    }

}

signed main(){
    fast;
    int t = 1;
    //cin >> t;
    while(t--){solve();}
    return 0;
}