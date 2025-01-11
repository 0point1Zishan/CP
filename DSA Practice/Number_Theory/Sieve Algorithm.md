# Sieve Algorithm:

```cpp
// PreChecking Prime Number Algorithm:

const int N = 1e6 + 10;
vector<bool> isPrime(N, 1);

int main(){
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i < N; i++){
        if(isPrime[i] == true){
            for(int j = 2 * i; j < N; j += i){
                isPrime[j] = false;
            }
        }
    }
    
    int q;  cin >> q;
    while(q--){
        int n;  cin >> n;
        if(isPrime[n]){
            cout << "Prime\n";
        }
        else   cout << "Not Prime\n";
    }
}
```



## Lowest and Highest Prime:
```cpp
const int N = 1e6 + 10;
vector<bool> isPrime(N, 1);
vector<int> lp(N, 0), hp(N, 0);  // lowest & hight prime numbers:

signed main(){
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i < N; i++){
        if(isPrime[i] == true){
            lp[i] = hp[i] = i;    
            for(int j = 2 * i; j < N; j += i){
                isPrime[j] = false;
                hp[j] = i;
                if(lp[j] == 0)  lp[j] = i;
            }
        }
    }

    for(int i = 1; i <= 100; i++)  cout << lp[i] << " " hp[i] <<  "\n";
    
    int q;  cin >> q;
    while(q--){
        int n;  cin >> n;
        if(isPrime[n]){
            cout << "Prime\n";
        }
        else   cout << "Not Prime\n";
    }
}
``` 

## Find Prime factor in Optimize way:

~~~
Using Highest and lowest prime factors we can find a number prime factors easily.
~~~

```cpp
const int N = 1e6 + 10;
vector<bool> isPrime(N, 1);
vector<int> hp(N, 0);

signed main(){
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < N; i++){
        if(isPrime[i] == true){
            hp[i] = i;    
            for(int j = 2 * i; j < N; j += i){
                isPrime[j] = false;
                hp[j] = i;
            }
        }
    }
    
    int q;  cin >> q;
    while(q){
        int num;  cin >> num;

        vector<int> prime_factor;
        while(num > 1){
            int pFact = hp[num];
            while(num % pFact == 0){
                num /= pFact;
                prime_factor.push_back(pFact);
            }
        }
        // O(log(n)) Time Complexity
        for(int i = 0; i < prime_factor.size(); i++){
            cout << prime_factor[i] << " ";
        }cout << "\n";
    }
}
```

## Divisors:
```cpp
const int N = 1e5 + 5;
vector<int> divisors[N + 1];

void solve(){
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j += i){
            divisors[j].push_back(i);
        }
    }

    for(int i = 1; i <= 10; i++){
        for(int d: divisors[i]){
            cout << d << " ";
        }cout << "\n";
    }
}
```