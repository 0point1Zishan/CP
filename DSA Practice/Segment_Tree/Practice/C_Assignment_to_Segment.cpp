#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int N = 1e5 + 5;
int v[N], tr[4*N], lazy[4*N];

void push_(int n, int l, int r){  
    if(lazy[n] != -1){
        tr[n] = lazy[n];

        if(l != r){
            lazy[2*n] = lazy[n];
            lazy[2*n+1] = lazy[n];
        }
        lazy[n] = -1;
    }
}

void build(int n, int l, int r){
    lazy[n] = -1;
    if(l == r){
        tr[n] = v[l];
        return; 
    }
    int mid = l + (r - l) / 2;
    build(2*n, l, mid);
    build(2*n+1, mid+1, r);
    tr[n] = 0;
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
}

int value(int n, int l, int r, int a){
    push_(n, l, r);
    
    if(l == r)  return tr[n];
    int mid = l + (r - l) / 2;
    if(a <= mid) return value(2*n, l, mid, a);
    else         return value(2*n+1, mid+1, r, a);

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
            int l;   cin >> l;
            cout << value(1, 1, n, l+1) << "\n";
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