#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int N = 1e5 + 5;
int v[N], tr[3 * N];

void init(int n, int l, int r){
    if(l == r){
        tr[n] = v[l];
        return;
    }
    int mid = l + (r - l) / 2;
    init(2*n, l, mid);
    init(2*n+1, mid+1, r);
    tr[n] = min(tr[2*n], tr[2*n+1]);
}

int mini(int n, int l, int r, int st, int end){
    if(l > end || r < st) return INT_MAX;
    if(l >= st && r <= end) return tr[n];

    int mid = l + (r - l) / 2;
    return min(mini(2*n, l, mid, st, end), mini(2*n+1, mid+1, r, st, end));
}

void solve(){

    int n, q; cin >> n >> q;
    for(int i = 1; i <= 3*n; i++) tr[i] = 0;
    for(int i = 1; i <= n; i++) cin >> v[i];
    init(1, 1, n);

    while(q--){
        int l, r;   cin >> l >> r;
        cout << mini(1, 1, n, l, r) << "\n";
    }

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    int i = 1;
    while(i <= t){cout << "Case " << i << ":\n"; solve(); i++;}
    return 0;
}