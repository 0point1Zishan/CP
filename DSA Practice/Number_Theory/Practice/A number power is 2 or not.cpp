#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;  cin >> n;
    cout << ((n & (n-1)) == 0   ?  "YES"  : "NO") << endl;
    
    return 0;
}