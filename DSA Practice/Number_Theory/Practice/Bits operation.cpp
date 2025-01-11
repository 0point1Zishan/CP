#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n, k;  cin >> n >> k;
    
    cout << k << "th bit is set?: " << (n & (1 << k)  ?  "YES"  : "NO") << endl;

    cout << n << "'s NOT: " << (n ^ (1 << k)) << endl;

    cout << "After set " << k << "th bit: " << (n | (1 << k)) << endl;

    cout << "After unset " << k << "th bit: " << (n & (~(1 << k))) << endl; 
    
    return 0;
}