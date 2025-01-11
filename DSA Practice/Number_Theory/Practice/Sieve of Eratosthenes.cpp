#include<bits/stdc++.h>
#define int long long int
#define nline "\n"
using namespace std;

signed main(){
    
    int n;  cin >> n;
    vector<bool> pr(n+1, true);
    for(int i = 2; i * i <= n; i++){
        if(pr[i]){
            for(int j = i * i; j <= n; j += i)   pr[j] = false;
        }
    }
    
    for(int i = 2; i <= n; i++){
        if(pr[i])  cout << i << " ";
    }
    return 0;
}