# Factors and Divisors:

```cpp
int n;  cin >> n;
for(int i = 1; i * i <= n; i++){
    if(n % i == 0){
        cout << i << " ";
        if(n % i != i) cout << n / i << " ";
    }
}
cout << "\n";
```
#### TC: O(sqrt(N))
<br>

## We can more optimize it using prime factors. Let's see:

### Number of Divisors
~~~
Give a number = X. 
After prime factor we get, X = P1^N1 * P2^N2 * P3^N3

So, Number of Divisors will be = (N1+1) * (N2+1) * (N3+1)
~~~ 


### All Divisors:
~~~
(1 + P1 + p1^2 + P1^3 + ... + P1^N1)
(1 + P2 + p2^2 + P2^3 + ... + P2^N2)
(1 + P3 + p3^2 + P3^3 + ... + P3^N3)
.
.
(1 + pM + PM^2 + PM^3 + ... + PM^NM)


==> 
a + b + c + d...
e + f + g + h...
...
...


Divisors: a*e, a*f, a*g, a*h, b*e, b*f, b*g, b*h, .....
~~~

### Sum of All Divisors:
~~~
P1^(N1+1)-1      P2^(N2+1)-1       P3^(N3+1)-1
------------  * --------------  * -------------
    P1 - 1        P2 - 1             P3 - 1
~~~
