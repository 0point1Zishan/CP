#include<bits/stdc++.h>
#define int long long int
#define MOD 1e9 + 7
#define nline "\n"
using namespace std;

const int N = 1e6;

#define NCR
#define PRIME MOD

int pw(int a, int p = MOD- 2, int M = MOD){
    int result = 1;
    while(p > 0){
        if(p & 1)   result = a * result % M;

        a = a * a % M;
        p >>= 1;
    }
    return result;
}

vector<int> fact(N), invFact(N);
int init(){
    int p = PRIME;
}

signed main(){
    
    
    
    return 0;
}