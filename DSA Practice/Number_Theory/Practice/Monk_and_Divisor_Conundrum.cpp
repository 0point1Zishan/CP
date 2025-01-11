#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int N = 2e5 + 10;
int cnt[N];
int cnt_mul[N];

void solve(){

    int n;  cin >> n;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        cnt[x]++;
    }
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            cnt_mul[i] += cnt[j];
        }
    }

    int q;  cin >> q;
    while(q--){
        int p, q;   cin >> p >> q;

        int lcm = (p * q) / __gcd(p, q);
        int ans = cnt_mul[p] + cnt_mul[q];
        if(lcm < N) ans -= cnt_mul[lcm];
        cout << ans << "\n";
    }

}

signed main(){
    fast;
    int t = 1;
    //cin >> t;
    while(t--){solve();}
    return 0;
}