#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int N = 1e5 + 5;
int v[N], tr[4*N], lazy[4*N];

void push_(int n, int l, int r){
    if(lazy[n] == 0)  return;
    tr[n] += (1LL * (r - l + 1)) * lazy[n];
    if(r != l)   lazy[2*n] += lazy[n],     lazy[2*n+1] += lazy[n];
    lazy[n] = 0;
}

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

void update(int n, int l, int r, int i, int j, int num){

    push_(n, l, r);
    if(r < i || j < l) return;

    if(l >= i && r <= j){
        lazy[n] = num;
        push_(n, l, r);
        return;
    }
    int mid = l + (r - l) / 2;
    update(2*n, l, mid, i, j, num);
    update(2*n+1, mid+1, r, i, j, num);
    tr[n] = tr[2*n] + tr[2*n+1];
}

int sum(int n, int l, int r, int a, int b){
    push_(n, l, r);
    if(l > b || r < a) return 0;
    if(l >= a && r <= b) return tr[n];
    int mid = l + (r - l) / 2;
    return sum(2*n, l, mid, a, b) + sum(2*n+1, mid+1, r, a, b);
}

void solve(){

    int n, m;   cin >> n >> m;
    build(1, 1, n);

    while(m--){
        int t;  cin >> t;
        if(t == 1){
            int l, r, num;    cin >> l >> r >> num;
            update(1, 1, n, l+1, r, num);
        }
        else{
            int l, r;   cin >> l >> r;
            cout << sum(1, 1, n, l+1, r) << "\n";
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