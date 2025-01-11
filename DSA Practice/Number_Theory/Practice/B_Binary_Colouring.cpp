#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    if(n == 1){
        cout << 1 << "\n" << 1 << "\n";
        return;
    }

    vector<int> ans;

    int temp = n;
    while(n){
        if(n & 1){
            ans.push_back(1);
        }
        else  ans.push_back(0);
        n /= 2;
    }

    int i = 0;
    while(i < ans.size()-1){

        if(ans[i] != 0 && ans[i+1] != 0){

            ans[i] = -1;
            int j = i+1;

            while(j < ans.size() && ans[j] == 1){
                ans[j++] = 0;
            }

            if(j < ans.size()){
                ans[j] = 1;
            }
            else{
                ans.push_back(1);
            }
            i = j-1;
        }
        i++;
    }

    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }cout << "\n";

}

signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}