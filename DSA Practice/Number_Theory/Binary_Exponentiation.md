# Binary Exponentiation:

To abode precision error we are using binary exponentiation & optimize time complexity;

##### IF (a <= 10^9, b <= 10^9 & MOD <= 10^9)
```cpp
int binaryEXp(int a, int b){
    
    int ans = 1;
    while(b){
        if(b & 1)  ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
```

##### IF (a <= 10^18 / 2^1024, b <= 10^9 & MOD <= 10^9)
```cpp
int binaryEXp(int a, int b){
    
    int ans = binaryExp(base, power);
    // a %= MOD;
    while(b){
        if(b & 1)  ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
```
### Time Complexity: O(log(b))