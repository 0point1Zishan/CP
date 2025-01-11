#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int N = 2e5 + 5;
int v[N], tr[3 * N];

void build(int node, int l, int r){

    if(l == r){
        tr[node] = v[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    tr[node] = tr[2*node] & tr[2*node+1];
}

int and_(int node, int l, int r, int a, int b){

    if(r < a || l > b)   return LLONG_MAX;
    if(l >= a && r <= b) return tr[node];

    int mid = (l + r) / 2;
    return and_(2*node, l, mid, a, b) & and_(2*node+1, mid+1, r, a, b);
}

void solve(){

    int n;  cin >> n;
    memset(tr, 0, sizeof(tr));
    memset(v, 0, sizeof(v));
    for(int i = 1; i <= n; i++)  cin >> v[i];
    build(1, 1, n);

    auto mx_range = [&](int l, int k){
        int ans = -1;
        int s = l, e = n;
        while(s <= e){

            int mid = s + (e - s) / 2;
            if(and_(1, 1, n, l, mid) >= k){
                ans = mid;
                s = mid + 1;
            } 
            else  e = mid - 1;
        }
        return ans;
    };
    int q;  cin >> q;
    while(q--){
        int l, k;   cin >> l >> k;
        cout << mx_range(l, k) << " ";
    }cout << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}