#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int m = 1e5 + 10;
    vector<bool> prime_(m, 1);
    vector<int> lp(m);
    prime_[0] = prime_[1] = false;
    for(int i = 2; i < m; i++){
        if(prime_[i] == true){
            lp[i] = i;
            for(int j = 2 * i; j < m; j += i){
                prime_[j] = false;
                if(lp[j] == 0)  lp[j] = i;
            }
        }
    }


    int n;  cin >> n;
    vector<int> ans(n, 1);
    bool isPre = false;

    for(int i = n+1; i >= 2; i--){

    	int k = i;

    	while(k > 1){

    		int pF = lp[k];
    		if(pF != k) ans[k-2] = 2, isPre = true;

    		while(k % pF == 0){
    			k /= pF;
    		}
    	}

    }
    cout << (isPre ?  2  :  1) << "\n";
    for(int i = 0; i < n; i++) cout << ans[i] << " ";

}

signed main(){
    fast;
    int t = 1;
    //cin >> t;
    while(t--){solve();}
    return 0;
}