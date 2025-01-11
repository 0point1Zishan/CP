#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


void bubbleSort(vector<int>& arr) {
    // Your code here
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr.size()-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
void solve(){
    int n;  cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    bubbleSort(v);
    for(int i = 0; i < n; i++)  cout << v[i] << " ";
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