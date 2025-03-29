#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        
    map<int, int> mp;
    mp[startTime[0] - 0]++;
    int n = startTime.size();
    for(int i = 1; i < n; i++)     mp[startTime[i] - endTime[i-1]]++;
    mp[eventTime - endTime.back()]++;

    int mx = 0;
    for(int i = 1; i < n-1; i++){
        int t = endTime[i] - startTime[i];
        int gap1 = startTime[i] - endTime[i-1];
        int gap2 = startTime[i+1] - endTime[i];

        mp[gap1]--; mp[gap2]--;
        if(mp[gap1] == 0) mp.erase(gap1);
        if(mp[gap2] == 0) mp.erase(gap2);

        if(mp.lower_bound(t) != mp.end())     mx = max(mx, startTime[i+1] - endTime[i-1]);
        mx = max(mx, startTime[i+1] - endTime[i-1] - t);
        mp[gap1]++;  mp[gap2]++;        
    }

    //! First:
    int t = endTime[0] - startTime[0];
    int gap1 = startTime[0];
    int gap2 = startTime[1] - endTime[0];

    mp[gap1]--; mp[gap2]--;
    if(mp[gap1] == 0) mp.erase(gap1);
    if(mp[gap2] == 0) mp.erase(gap2);

    if(mp.lower_bound(t) != mp.end())     mx = max(mx, startTime[1]);
    mx = max(mx, startTime[1] - t);
    mp[gap1]++;  mp[gap2]++;        


    //! Last:
    t = endTime.back() - startTime.back();
    gap1 = startTime.back() - endTime[n-2];
    gap2 = eventTime - endTime.back();

    mp[gap1]--; mp[gap2]--;
    if(mp[gap1] == 0) mp.erase(gap1);
    if(mp[gap2] == 0) mp.erase(gap2);

    if(mp.lower_bound(t) != mp.end())     mx = max(mx, eventTime - endTime[n-2]);
    mx = max(mx, eventTime - endTime[n-2] - t);
    mp[gap1]++;  mp[gap2]++;

    return mx;
}

void solve(){
    int n, k;  cin >> n >> k;
    vector<int> s(n), e(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) cin >> e[i];

    cout << maxFreeTime(k, s, e) << "\n";
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}