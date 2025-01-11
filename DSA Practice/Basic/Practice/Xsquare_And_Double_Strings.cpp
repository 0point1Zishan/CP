#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    string s;   cin >> s;
    vector<int> fr(26, 0);
    for(int i = 0; i < s.size(); i++){
        fr[s[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(fr[i] >= 2){
            cout << "Yes" << "\n";
            return;
        }
    }
    cout << "No" << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}