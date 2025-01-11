#include<bits/stdc++.h>
#define int long long int
#define nline "\n"
using namespace std;

int gcd(int a, int b){
    if(a == 0)  return b;
    return gcd(b % a, a);
}

signed main(){
    
    int a, b;   cin >> a >> b;
    cout << gcd(a, b) << nline;

    //! OR:
    cout << __gcd(a, b) << nline;
    
    return 0;
}