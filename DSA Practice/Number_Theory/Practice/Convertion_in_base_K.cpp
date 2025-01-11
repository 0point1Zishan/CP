#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int number; cin >> number;

    int bit;    cin >> bit;

    cout << ((number & (1 << bit)) ?   "YES set"  :  "NOT") << endl;
    
    return 0;
}