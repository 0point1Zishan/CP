#include<bits/stdc++.h>
#define int long long int
#define nline "\n"
using namespace std;

int pw(int a, int b, int m){
    if(b == 0)  return 1;

    if(b & 1){
        int t = pw(a, (b-1) / 2, m);
        t = (t * t) % m;
        return (a * t % m);
    }
    else{
        int t = pw(a, b / 2, m);
        return (t * t % m);
    }

}

signed main(){
    
    int a, b, m;    cin >> a >> b >> m;
    cout << pw(a, b, m);
    
    return 0;
}