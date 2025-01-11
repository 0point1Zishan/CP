#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int aggressiveCows(vector<int> &stalls, int n, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());
    int s = 0, e = stalls.back() - stalls[0], mx = 0;

    auto isPos = [&](int dis){
        int cnt = 1, t = 0;
        for(int i = 1; i < n; i++){
            t += stalls[i] - stalls[i-1];
            if(t >= dis) cnt++, t = 0;
        }
        return cnt >= k;
    };

    while(s <= e){
        int mid = s + (e - s) / 2;
        if(isPos(mid)){
            s = mid + 1;
            mx = mid;
        }
        else e = mid - 1;
    }return mx;
}

void solve(){
    int n, k;   cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << aggressiveCows(v, n, k) << "\n";
}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}