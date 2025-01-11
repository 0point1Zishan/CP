# ETF and Euler's Theorem:


##### When MOD is prime:
```cpp
int binExp(int a, int b, int m){
	int ans = 1;
	while(b){
		if(b & 1) ans = (ans * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return ans;
}

void solve(){

	int a, b, c;	cin >> a >> b >> c;
	cout << binExp(a, binExp(b, c, MOD-1), MOD) << "\n";

}
```
##### IF (a <= 10^18 / 2^1024, b <= 10^9 & MOD <= 10^9)

```cpp
int binMul(int a, int b){
    int ans = 0;
    while(b){
        if(b & 1) ans = (ans + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    return ans;
}

int binExp(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1)   ans = binMul(ans, a);
        a = binMul(a, a);
        b >>= 1;
    }
    return ans;
}
``` 
### Time Complexity: O(log^2(N))