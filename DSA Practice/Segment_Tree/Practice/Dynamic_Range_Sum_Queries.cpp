#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int N = 2e5 + 5;
int v[N], tr[3*N];

void build(int n, int l, int r){
    if(l == r){
        tr[n] = v[l];
        return;
    }

    int mid = l + (r - l) / 2;
    build(2*n, l, mid);
    build(2*n+1, mid+1, r);
    tr[n] = tr[2*n] + tr[2*n+1];
}

void update(int n, int l, int r, int idx, int x){

    if(l > idx || r < idx) return;

    if(l == r){
        tr[n] = x;
        return;
    }

    int mid = l + (r - l) / 2;
    update(2*n, l, mid, idx, x);
    update(2*n+1, mid+1, r, idx, x);

    tr[n] = tr[2*n] + tr[2*n+1];
}

int sum(int n, int l, int r, int a, int b){

    if(l > b || r < a) return 0;
    if(l >= a && r <= b) return tr[n];

    int mid = l + (r - l) / 2;
    return sum(2*n, l, mid, a, b) + sum(2*n+1, mid+1, r, a, b);
}


void solve(){

    int n, q;   cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> v[i];

    build(1, 1, n);

    while(q--){
        int op; cin >> op;
        if(op == 1){
            int idx, x; cin >> idx >> x;
            update(1, 1, n, idx, x);
        }
        else{
            int l, r;   cin >> l >> r;
            cout << sum(1, 1, n, l, r) << "\n";
        }
    }

}

signed main(){
    fast;
    int t = 1;
    //cin >> t;
    while(t--){solve();}
    return 0;
}