#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();
    vector<int> diff;
    diff.push_back(0);
    diff.push_back(startTime[0] - 0);
    for(int i = 1; i < n; i++){
        diff.push_back(startTime[i] - endTime[i-1]);
    }
    diff.push_back(eventTime - endTime.back());

    vector<int> pf;
    pf.push_back(diff[0]);
    for(int i = 1; i < diff.size(); i++){
        pf.push_back(diff[i] + pf.back());
    }

    int ans = 0;
    for(int i = 1; i < pf.size()-k; i++){
        ans = max(ans, pf[i+k] - pf[i-1]);
    }
    
    return ans;
}

void solve(){
    // vector<int> a = {0,2, 9};
    // vector<int> b = {1, 4, 10};

    // vector<int> a = {1, 3};
    // vector<int> b = {2, 5};

    // vector<int> a = {0,1,2,3,4};
    // vector<int> b = {1,2,3,4,5};

    vector<int> a = {0, 3, 7, 9};
    vector<int> b = {1, 4, 8, 10};

    cout << maxFreeTime(10, a, b) << "\n";
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}