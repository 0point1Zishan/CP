#include<bits/stdc++.h>
#define int long long int
#define nline "\n"
using namespace std;

signed main(){
    
    int a;  cin >> a;

    cout << bitset<8>(a).to_string() << endl;
    cout << bitset<10>(a).to_string() << endl;
    cout << bitset<14>(a).to_string() << endl;
    
    return 0;
}