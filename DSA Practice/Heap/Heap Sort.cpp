#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void heapify(vector<int>& v, int sz, int i){
    int l = 2*i + 1, r = 2*i + 2, idx = i;

    if(l < sz && v[l] > v[idx]) idx = l;
    if(r < sz && v[r] > v[idx]) idx = r;

    if(i != idx){
        swap(v[i], v[idx]);
        heapify(v, sz, idx);
    }
}
void buildHeap(vector<int>& v){
    int n = v.size();
    for(int i = n/2 - 1; i >= 0; i--) heapify(v, n, i);
}

void heapSort(vector<int>& v){
    buildHeap(v);
    int sz = v.size();
    for(int i = sz-1; i > 0; i--){
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

void solve(){
    int n;  cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    heapSort(v);
    for(int i = 0; i < n; i++) cout << v[i] << " ";
    cout << "\n"; 
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}