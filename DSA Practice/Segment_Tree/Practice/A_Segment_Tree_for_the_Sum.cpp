#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int N = 1e5 + 5;
int v[N], tr[4 * N];

void build(int node, int l, int r){

    if(l == r){
        tr[node] = v[l];
        return;
    }

    int mid = (l + r) / 2;
    int ln = 2 * node, rn = (2 * node) + 1;

    build(ln, l, mid);
    build(rn, mid+1, r);
    tr[node] = tr[ln] + tr[rn];
}

void update(int node, int l, int r, int idx, int num){
    
    if(idx < l || idx > r)
        return;

    if(l == r){
        tr[node] = num;
        return;
    }
    
    int mid = (l + r) / 2;
    int ln = 2 * node, rn = (2 * node) + 1;

    update(ln, l, mid, idx, num);
    update(rn, mid+1, r, idx, num);
    tr[node] = tr[ln] + tr[rn];
}

int sum(int node, int l, int r, int a, int b){

    if(r < a || l > b) return 0;
    if(l >= a && r <= b) return tr[node];

    int mid = (l + r) / 2;
    int ln = 2 * node, rn = (2 * node) + 1;

    return sum(ln, l, mid, a, b) + sum(rn, mid+1, r, a, b);
}

void solve(){

    int n, m;   cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> v[i];
    build(1, 1, n);

    while(m--){
        int op; cin >> op;
        if(op == 2){
            int l, r;   cin >> l >> r;
            cout << sum(1, 1, n, l+1, r) << "\n";
        }
        else{
            int idx, num;   cin >> idx >> num;
            update(1, 1, n, idx+1, num);
        }
    }

}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){solve();}
    return 0;
}