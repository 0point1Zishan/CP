#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)          cin >> v[i];
    string bin;   cin >> bin;

    int one = 0, zero = 0;
    vector<int> pf_one(n), pf_zero(n);

    for(int i = 0; i < n; i++){
        if(bin[i] == '1')    one ^= v[i];
        else                zero ^= v[i];
        pf_one[i] = one;
        pf_zero[i] = zero;
    }

    int q;  cin >> q;
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int l, r;   cin >> l >> r;
            l--;  r--;

            int a = pf_one[r], b = pf_zero[r];
            if(l > 0)  a ^= pf_one[l-1], b ^= pf_zero[l-1];

            one ^= (a^b), zero ^= (a ^ b);
        }
        else{
            int w;  cin >> w;
            cout << (w == 0 ?  zero  :  one) << " ";
        }
    }cout << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}