#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int N = 1e5 + 5;
int v[N], tr[4*N], lazy[4*N];

void push_(int n, int l, int r){  
    if(lazy[n] != 0){
        tr[n] ^= lazy[n];

        if(l != r){
            lazy[2*n] ^= lazy[n];
            lazy[2*n+1] ^= lazy[n];
        }
        lazy[n] = 0;
    }
}

void build(int n, int l, int r, string &s){
    lazy[n] = 0;
    if(l == r){
        tr[n] = s[l - 1] - '0';
        return; 
    }
    int mid = l + (r - l) / 2;
    build(2*n, l, mid, s);
    build(2*n+1, mid+1, r, s);
    tr[n] = 0;
}

void update(int n, int l, int r, int i, int j){

    push_(n, l, r);
    if(r < i || j < l) return;

    if(l >= i && r <= j){
        lazy[n] ^= 1;
        push_(n, l, r);
        return;
    }
    int mid = l + (r - l) / 2;
    update(2*n, l, mid, i, j);
    update(2*n+1, mid+1, r, i, j);
    // tr[n] = tr[2*n] & tr[2*n+1];
}

int ans(int n, int l, int r, int idx){
    push_(n, l, r);
    
    if(l == r) return tr[n];
    int mid = l + (r - l) / 2;

    if(mid >= idx) return ans(2*n, l, mid, idx);
    else           return ans(2*n+1, mid+1, r, idx);

}

void solve(){

    string s;   cin >> s;
    int m;  cin >> m;

    build(1, 1, s.size(), s);

    while(m--){
        string t;   cin >> t;

        if(t == "I"){
            int l, r;   cin >> l >> r;
            update(1, 1, s.size(), l, r);
        }
        else{
            int idx;    cin >> idx;
            cout << ans(1, 1, s.size(), idx) << "\n";
        }
    }

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    int i = 1;
    while(i <= t){cout << "Case " << i << ":\n";solve(); i++;}
    return 0;
}