#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n, k;   cin >> n >> k;

    vector<int> v(n+1);
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        v[x]++;
    }
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
    }

    vector<int> aK(2*k), bK(2*k);
    int a = 0, b = 0;
    for(int i = 1; i <= n && a < 2*k; i++){
        if(v[i] == 1){
            aK[a++] = i;
            bK[b++] = i;
        }
    }

    if(a != 2*k && (2*k - a) & 1) a--, b--;
    for(int i = 1; i <= n && a < 2*k; i++){
        if(v[i] == 2){
            aK[a++] = i;
            aK[a++] = i;
        }
    }

    for(int i = 1; i <= n && b < 2*k; i++){
        if(v[i] == 0){
            bK[b++] = i;
            bK[b++] = i;
        }
    }

    for(int i = 0; i < 2*k; i++) cout << aK[i] << " ";
    cout << "\n";
    for(int i = 0; i < 2*k; i++) cout << bK[i] << " ";
    cout << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}