#include<bits/stdc++.h>
#define int long long int
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int N = 1e5 + 5;
int v[N];
pair<int, int> tr[4*N];

pair<int, int>  merge(pair<int, int>& a, pair<int, int>& b){
    pair<int, int> ans;
    ans.ff = min(a.ff, b.ff);
    ans.ss = 0;
    if(a.ff == ans.ff) ans.ss += a.ss;
    if(b.ff == ans.ff) ans.ss += b.ss;
    return ans;
}

void build(int n, int l, int r){
    if(l == r){
        tr[n].ff = v[l];
        tr[n].ss = 1;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2*n, l, mid);
    build(2*n+1, mid+1, r);

    tr[n] = merge(tr[2*n], tr[2*n+1]);
}

void update(int n, int l, int r, int idx, int val){
    if(idx < l || idx > r) return;
    if(l == r){
        tr[n].ff = val;
        tr[n].ss = 1;
        return;
    }

    int mid = l + (r - l) / 2;
    update(2*n, l, mid, idx, val);
    update(2*n+1, mid+1, r, idx, val);

    tr[n] = merge(tr[2*n], tr[2*n+1]);
}

pair<int, int> mini(int n, int l, int r, int a, int b){
    if(r < a || l > b) return {INT_MAX, 0};
    if(l >= a && r <= b)  return tr[n];

    int mid = l + (r - l) / 2;
    pair<int,int> x = mini(2*n, l, mid, a, b);
    pair<int, int> y = mini(2*n+1, mid+1, r, a, b);
    return merge(x, y);
}

void solve(){

    int n, m;   cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i];

    build(1, 1, n);

    while(m--){
        int op; cin >> op;
        if(op == 1){
            int idx, val;   cin >> idx >> val;
            update(1, 1, n, idx+1, val);
        }
        else{
            int l, r;   cin >> l >> r;
            pair<int, int> ans = mini(1, 1, n, l+1, r);
            cout << ans.ff << " " << ans.ss << "\n";
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