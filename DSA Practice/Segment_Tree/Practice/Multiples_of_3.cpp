#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int N = 1e5 + 5;
vector<vector<int>> tr(3*N, vector<int>(3));
vector<int> lazy(3*N);

void push_(int n, int l, int r){
    if(l != r){
        lazy[2*n] = (lazy[n] + lazy[2*n]) % 3;
        lazy[2*n+1] = (lazy[n] + lazy[2*n+1]) % 3;
    }
    if(lazy[n] == 1) rotate(tr[n].rbegin(), tr[n].rbegin() + 1, tr[n].rend());
    if(lazy[n] == 2) rotate(tr[n].begin(), tr[n].begin() + 1, tr[n].end());
    lazy[n] = 0;
}

void init(int n, int l, int r){
    if(l == r){
        tr[n][0] = 1;
        tr[n][1] = tr[n][2] = 0;
        return;
    }

    int mid = l + (r - l) / 2;
    init(2*n, l, mid);
    init(2*n+1, mid+1, r);

    tr[n][0] = tr[2*n][0] + tr[2*n+1][0];
    tr[n][1] = tr[n][2] = 0;
}

void update(int n, int l, int r, int st, int end){
    if(lazy[n]) push_(n, l, r);
    if(l > end || r < st) return;
    if(l >= st && r <= end){
        if(l != r){
            lazy[n*2] = (lazy[n*2] + 1) % 3;
            lazy[n*2+1] = (lazy[n*2+1] + 1) % 3;
        }
        rotate(tr[n].rbegin(), tr[n].rbegin() + 1,tr[n].rend());
        return;
    }

    int mid = l + (r - l) / 2;
    update(2*n, l, mid, st, end);
    update(2*n+1, mid+1, r, st, end);

    tr[n][0] = tr[2*n][0] + tr[2*n+1][0];
    tr[n][1] = tr[2*n][1] + tr[2*n+1][1];
    tr[n][2] = tr[2*n][2] + tr[2*n+1][2];
}

int cnt(int n, int l, int r, int st, int end){
    if(lazy[n]) push_(n, l, r);
    if(l > end || r < st)  return 0;
    if(l >= st && r <= end)  return tr[n][0];

    int mid = l + (r - l) / 2;
    return cnt(2*n, l, mid, st, end) + cnt(2*n+1, mid+1, r, st, end);
}

void solve(){
    int n, q; cin >> n >> q;
    init(1, 1, n);

    while(q--){
        int op; cin >> op;
        if(op == 0){
            int l, r; cin >> l >> r;
            update(1, 1, n, l+1, r+1);
        }
        else{
            int l, r; cin >> l >> r;
            cout << cnt(1, 1, n, l+1, r+1) << "\n";
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
