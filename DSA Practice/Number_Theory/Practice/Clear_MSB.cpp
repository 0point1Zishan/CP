#include<bits/stdc++.h>
#define int long long int
#define nline "\n"
using namespace std;

signed main(){
    
    int n, bit; cin >> n >> bit;

    cout << bitset<10>(n).to_string() << "\n";

    n = (n & ( (1 << (bit + 1)) - 1) );
    cout << bitset<10>(n).to_string() << "\n";
    
    return 0;
}