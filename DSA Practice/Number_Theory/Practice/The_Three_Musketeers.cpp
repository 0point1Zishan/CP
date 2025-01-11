#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;


vector<string> _subset(string s){
    vector<string> ans;
    int sz = (1 << s.size());

    for(int i = 0; i < sz; i++){
        string k = "";
        for(int j = 0; j < s.size(); j++){
            if(i & (1 << j))  k.push_back(s[j]);
        }
        if(k.size())  ans.push_back(k);
    }
    return ans;
}

void solve(){

    int n;  cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++)  cin >> s[i];

    unordered_map<string, int> mp;
    for(int i = 0; i < n; i++){
        set<char> ch;
        for(auto it: s[i]){
            bool isV = (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u');
            if(isV) ch.insert(it);
        }

        string vowel_str(ch.begin(), ch.end());
        vector<string> _subsets = _subset(vowel_str);
        for(auto it: _subsets)    mp[it]++;
    }

    int ans = 0;
    for(auto it: mp){
        if(it.second >= 3){

            int way = it.second * (it.second - 1) * (it.second - 2) / 6;
            if(it.first.size() % 2 == 0)  ans -= way;
            else ans += way;
        }
    }
    cout << ans << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}