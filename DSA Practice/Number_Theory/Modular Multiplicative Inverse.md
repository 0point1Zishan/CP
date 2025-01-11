# [MMI](https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/tutorial/)

[Prime Factorization](Prime & Prime Factorization.md)
~~~
(A / B)  %= (A / B) (A * B^{-1}) % M 
          = ((A % M) * (B^{-1} %M)) % M

If (A * B = 1):    B is Multiplicative Inverse

If (A * B) % M = 1:  B is MMI of A

(A % M * B % M) % M = 1    [1 <= B < M]
~~~

```cpp
for(int i = 1; i < M; i++){
    if( (A * B) % M == 1){
        cout << "B is Inverse\n";
    }
}
```

## Introduction
The **multiplicative inverse** of an integer a under modulo m is an integer x such that:
#### a * x ≡ 1 (mod m)
In other words, when you multiply a and x and take the remainder after dividing by m, you get 1.


### Conditions:
1. The multiplicative inverse exists if and only if a and m are coprime (i.e., gcd(a, m) = 1).
2. If m is prime, the inverse can be found using **Fermat's Little Theorem**.



## Fermat's Little Theorem

Fermat's Little Theorem states that if p is a prime number and a is an integer not divisible by p, then:

#### a^(p-1) ≡ 1 (mod p)

From this, we can derive that: 
#### a^(p-2) ≡ a^(-1) (mod p)

This means a^(p-2) is the multiplicative inverse of a modulo p.


### Conditions:
- M is prime
- A is not multiple of M



### C++ Code(Find Inverse)

```cpp
int binExp(int x, int p, int m){
    int res = 1;
    x %= p;

    while(p){
        if(p & 1)  res = (res * x) % m;

        x = (x * x) % m;

        p >>= 1;
    }
    return res;
}
void solve(){
    int M = 1e9 + 7;
    cout << binExp(2, M-2, M) << "\n";
}
```

### Ex

Let's say we want to find the multiplicative inverse of \( 3 \) modulo \( 11 \):

1. **Input**: a = 3, m = 11
2. Using Fermat's Little Theorem:
**Inverse = (3^(11-2) % 11 = 3^9) % 11 [Multiplicative Inverse of 3 under modulo 11 is: 4]**
   

### Conc
- The multiplicative inverse under modulo exists if a and m are coprime.
- For a prime m, use Fermat's Little Theorem to compute the inverse.



## Problem
~~~
There are N children and K trophies. k < N count the number of ways
to distribute trophy among N students such that each students get 1
trophy only.

Mod M = 10^9 + 7
N <= 10^6 
k < N < 10^6
Q < 10^5
~~~


### Sol:
~~~
1. In this case the answer will be NCK(nCr = n! / ((n - r)! * r!)).
2. M is Prime.
~~~

### Code:
```cpp
#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e6 + 10;
int fact[N];

int binExp(int x, int p, int m){
    int res = 1;
    x %= p;

    while(p){
        if(p & 1)  res = (res * x) % m;

        x = (x * x) % m;

        p >>= 1;
    }
    return res;
}

void solve(){

    fact[0] = 1;
    for(int i = 1; i <= N; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }

    int q;  cin >> q;
    while(q--){
        int n, k;   cin >> n >> k;
        int ans = fact[n];
        int den = (fact[n-k] * fact[k] ) % MOD;
        cout << ans * binExp(den, MOD-2, MOD) % MOD << "\n";
    }

}

signed main(){
    fast;
    int t = 1;
    //cin >> t;
    while(t--){solve();}
    return 0;
}
```