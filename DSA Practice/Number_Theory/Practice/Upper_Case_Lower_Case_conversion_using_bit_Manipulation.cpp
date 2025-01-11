#include<bits/stdc++.h>
#define int long long int
#define nline "\n"
using namespace std;

signed main(){
    
    
    char ch_u, ch_l;  cin >> ch_u >> ch_l;

    ch_u = ch_u | ' ';
    ch_l = ch_l & '_';

    cout << ch_u << "\n";

    cout << ch_l << "\n";
    
    return 0;
}