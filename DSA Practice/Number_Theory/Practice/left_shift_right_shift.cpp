#include<bits/stdc++.h>
#define int long long int
#define nline "\n"
using namespace std;

signed main(){
    
    int n;  cin >> n;
    cout << (n >> 1) << "\n";   // 4
    cout << (n >> 2) << "\n";   // 2

    cout << "\n";

    cout << (n << 1) << "\n";  // 18
    cout << (n << 2) << "\n";  // 32
    cout << (n << 3) << "\n";  // 64
    cout << (n << 4) << "\n";  // 144
    
    return 0;
}