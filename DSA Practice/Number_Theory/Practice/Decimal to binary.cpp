#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;    cin >> num;
    int n = (int)(log2(num));
    cout << bitset<64>(num).to_string().substr(64 - n - 1);
}