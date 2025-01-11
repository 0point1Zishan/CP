# Prime & Prime Factorization#Code

```cpp
int n;  cin >> n;
map<int , int> cnt;
for(int i = 2; i * i <= n; i++){
    
    while(n % i == 0){
        cnt[i]++;
        n /= i;
    }
}
if(n > 1) cnt[n]++;
```
#### TC  O(sqrt(n));

### Note:
~~~
Every Non-Prime number's smallest factor is prime.
~~~