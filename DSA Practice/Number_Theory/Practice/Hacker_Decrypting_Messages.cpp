#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int N = 2e6 + 5;
int a[N];
int hp[N];
bool isRemoved[N];

vector<int> pri_Fac(int x){
    vector<int> ans;
    while(x > 1){
        int pf = hp[x];
        while(x % pf == 0) x /= pf;
        ans.push_back(pf);
    }
    return ans;
}

void solve(){

    int n, q;   cin >> n >> q;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        a[x] = 1;
    }

    for(int i = 2; i < N; i++){
        if(a[i]){
            for(int j = i; j < N; j *= i)   isRemoved[j] = 1;
        }
    }

    while(q--){
        int x;  cin >> x;
        vector<int> pf = pri_Fac(x);
        bool isPos = false;

        for(int i = 0; i < pf.size(); i++){
            for(int j = i; j < pf.size(); j++){

                int pro = pf[i] * pf[j];
                if(i == j && x % pro != 0)   continue;

                if(isRemoved[x / pro] == 1 || x / pro == 1){
                    isPos = true;
                    break;
                }
            }
            if(isPos) break;
        }
        cout << (isPos ? "YES\n"  : "NO\n");
    }
    
}

signed main(){
    fast;
    int t = 1;
    for(int i = 2; i < N; i++){
        if(hp[i] == 0){
            for(int j = i; j < N; j += i){
                hp[j] = i;
            }
        }
        
    }
    //cin >> t;
    while(t--){solve();}
    return 0;
}