#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    vector<vector<int>> v(n, vector<int> (n));

    vector<int> bits(n, 1073741823);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
            if(i != j){
                bits[i] &= v[i][j];
                bits[j] &= v[i][j];
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && (bits[i] | bits[j]) != v[i][j]){
                cout << "NO\n";
                return;
            } 
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) cout << bits[i] << " ";
    cout << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}