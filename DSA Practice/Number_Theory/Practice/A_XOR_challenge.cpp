#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;

    int bits_ = (int)log2(n) + 1;

    vector<int> a;
    int x = 0, y = 0;
    for(int i = 0; i < bits_; i++){
        if(n & (1 << i))  a.push_back(i);
        else{
            x |= (1 << i);
            y |= (1 << i);
        }
    }

    int sz = 1 << a.size();
    int ans = -1;
    for(int i = 0; i < sz; i++){
        int temp_x = x, temp_y = y;
        for(int j = 0; j < a.size(); j++){

            if(i & (1 << j))  temp_x |= (1 << a[j]);
            else              temp_y |= (1 << a[j]);
        }

        ans = max(ans, temp_x * temp_y);
    }
    cout << ans << "\n";

}

signed main(){
    fast;
    int t = 1;
    //cin >> t;
    while(t--){solve();}
    return 0;
}