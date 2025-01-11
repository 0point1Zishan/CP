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
    build(node*2, l, mid);
    build(node*2 + 1, mid+1, r);
    tr[node] = min(tr[node*2], tr[node*2 + 1]);
}

void update(int node, int l, int r, int idx, int num){
    
    if(idx < l || idx > r)
        return;

    if(l == r){
        tr[node] = num;
        return;
    }
    
    int mid = (l + r) / 2;

    update(node*2, l, mid, idx, num);
    update(node*2 + 1, mid+1, r, idx, num);
    tr[node] = min(tr[node*2], tr[node*2 + 1]);
}

int mini(int node, int l, int r, int a, int b){

    if(r < a || l > b) return INT_MAX;
    if(l >= a && r <= b) return tr[node];

    int mid = (l + r) / 2;

    return min(mini(node*2, l, mid, a, b), mini(node*2 + 1, mid+1, r, a, b));
}

void solve(){

    int n, m;   cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> v[i];
    build(1, 1, n);

    while(m--){
        int op; cin >> op;
        if(op == 2){
            int l, r;   cin >> l >> r;
            cout << mini(1, 1, n, l+1, r) << "\n";
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