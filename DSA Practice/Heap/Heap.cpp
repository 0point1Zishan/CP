#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

class heap{
    public:
        vector<int> v;
    heap(){
        v.push_back(-1);
    }

    void insert(int val){
        v.push_back(val);

        int sz = v.size()-1;
        while(sz > 1 && v[sz/2] < v[sz]){
            swap(v[sz/2], v[sz]);
            sz /= 2;
        }
    }
    void print(){
        for(int i = 1; i < v.size(); i++) cout << v[i] << " ";
        cout << "\n";
    }
    void deleteMX(){
        if(v.size() <= 1) return;
        swap(v[1], v.back());
        v.pop_back();
        heapfy(1);

    }
    void heapfy(int i){
        int idx = i;
        int l = 2 * i, r = 2 * i + 1;

        if(l < v.size() && v[l] > v[idx]) idx = l;
        if(r < v.size() && v[r] > v[idx]) idx = r;

        if(i != idx){
            swap(v[i], v[idx]);
            heapfy(idx);
        }
    }
};

void solve(){
    heap a;
    int n;  cin >> n;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        a.insert(x);
    }
    a.print();
    a.deleteMX();
    a.print();

}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}