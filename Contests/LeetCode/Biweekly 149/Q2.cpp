#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();

    vector<int> diff;
    diff.push_back(startTime[0]);
    for(int i = 1; i < n; i++)      diff.push_back(startTime[i] - endTime[i-1]);
    diff.push_back(eventTime - endTime.back());

    int currTime = 0;
    for(int i = 0; i <= k; i++) currTime += diff[i];
    int ans = currTime;
    for(int i = k + 1; i < n+1; i++){ 
        currTime += (diff[i] - diff[i-k-1]);
        ans = max(ans, currTime);
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