# Bit manipulation and Bit Masking

## **Check a number is even or odd:**   


```cpp
if(x & 1)  cout << "ODD";
else       cout << "EVEN";
```
#### Example:
X = 9;             bit(9) = 1001;   1001 & 1 = 9 & 1 = 1;
X = 8;             bit(8) = 1000;   1000 & 1 = 8 & 1 = 0
<br><br>

## **Check a number is power of two or not:**
```cpp
if(x & (x - 1) == 0)   cout << "power of 2";
else                   cout << "Not power of 2";
```
***Corner Case:*** If the number is 0. we can't use it. But we already know that 0 is not power of 2.
#### TC:  O(1)
<br><br>


## **Playing with the kth bit**
(1 << k)  = 2^k  bit = kth least significant;

#### Check if kth bit is set:       n & (1 << k);
```cpp
cout << (n & (1 << k)  ?  "YES"  : "NO") << endl;
```

#### Toggle the kth bit:       x ^ (1 << k);
```cpp
cout << (n ^ (1 << k)) << endl;
```

#### Set the kth bit:    x | ( 1 << k);
```cpp
cout << (n | (1 << k)) << endl;
```
#### invert a binary number ~a;
```cpp
cout << ~a << endl;
```
#### Unset the kth bit:         x & (~(1 << k));
```cpp
cout << (x & (~(1 << k))) << endl;
```
<br><br>

## **Multiply or Divide a number by 2^k**

	#Multiply: (x << k) left shift;   
	#Division: (x >> k) right shift;


### **Decimal to  binary and binary to decimal**

**Dec to Bin:**
#Code:
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;    cin >> n;
    string binary = bitset<32>(n).to_string();
    cout << binary << endl;
}
```

**Binary to Dec:**
#Code 
```cpp
#include <iostream>
using namespace std;
int main(){

	string bin; cin >> bin;
	cout << stoi(bin, 0, 2);
	return 0;
}
```
<br><br>


### Uppercase to lowercase && lowercase to uppercase:

```cpp
char ch = 'A';
char smallCh = ch | ' ';
cout << smallCh << "\n";

ch = 'z';
char capitalCh = ch & '_';
cout << capitalCh << "\n";
```

## **Kth bit set / unset?:**

```cpp
if((x >> k) & 1 == 1)   cout << k << "bit on";
else                    cout << k << "bit off";
```

```cpp
int check_kth_bit_on_off(int x, int k){
	return (x >> k) & 1;
}

void no_of_bits_on(int x){
	int cnt = 0;
	for(int k = 0; k <= 31; k++){
		if(check_kth_bit_on_off(x, k))  cnt++;
	}
	cout << cnt << "bit's on" << endl;
}
```

*******

### **Find Out n % (2 ^ k):**

```cpp
cout << n & ((1 << k) - 1);
```
#### TC O(1)
<br><br>

## **Swapping 2 numbers without using temporary variable:**

```cpp
X = X ^ Y;
Y = X ^ Y;
X = X ^ Y;
```

******
## **Bit Property:**

- If number of set bit in A = x, number of set bit in B = y, number of set bit in (A ^ B) = Z;
then, Z is even if (x + y) is even &  Z is odd if(x + y) is odd.

<br><br>

### **Toggle number from one to another:**

Let x is 5 or 10. if the number is 5 then toggle it in 10. and if the number is 10 then toggle it in 5.

```cpp
n = 10 ^ 5 ^ n;
```

if n is 10 then after this operation we will get 5 &
if n is 5 then after this operation we will get 10.

****
<br>

### **Bit Property:**

```cpp
A + B = (A + B) + 2 * (A & B)
```

```cpp
A + B = (A | B) + (A & B)
```

<br><br>


### **Finding number of set bits in a number:**

**X is on int:**
```cpp
__builtin_popcount(x)
```

**X is a long long:**
```cpp
__builtin_popcountll(x)
```
#### TC  O(1)

****
<br>

### **Find Most significant Bit**

```cpp
int setBit(int n){
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n = n + 1;
	return (n >> 1);
}

//!Or:
mx = 31 - __builtin_clz(n);
```
**** 
<br>

### **Bit Property:**


##### 1) XOR:

1. 0 XOR X == X
2. 0 XOR 0 == 0
3. 0 XOR 1 == 1
4. X XOR X == 0

5. A XOR B = C
6. A XOR C = B
7. B XOR C = A
##### 2) 
![alt text](image.png)


```cp
          0 ^ 1 ^ 2 ^ 3 == 0;
          4 ^ 5 ^ 6  ^ 7 == 0;
          8 ^ 9 ^ 10 ^ 11 == 0;
          12 ^ 13 ^ 14 ^ 15 == 0;
  and,
          0 ^ 1 == 1;
          4 ^ 5 == 1;
          8 ^ 9 == 1;
   and,
		   0 ^ 1 ^ 2 == 3;
		   4 ^ 5 ^ 6 == 7;
		   8 ^ 9 ^ 10 == 11;
```
### Code:
```cpp
if(n % 4 == 0)  cout << n << endl;
if(n % 4 == 3)  cout << 0 << endl;
if(n % 4 == 2)  cout << n + 1 << endl;
if(n % 4 == 1)  cout << 1 << endl;
```


##### 3
```cpp
(x & a) == (x & b);
(x | a) == (x | b);
(x ^ a) == (x ^ b);
``` 
##### Example 
	if(X ^ Y == k). given X and k. what will be Y?
#### sol:
	X ^ (X ^ Y) == X ^ k;
	Y = X ^ K;


<br><br>

####  **Number of bits all subsequences:**

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;  cin >> n;
	for(int i = 0; i < (1 << n); i++){
		for(int b = 0; b < n; b++){
			if( (b >> k) & 1)  cout << 1 << " ";
			else               cout << 0 << " ";
			
		}
		cout << "\n";
	}
}
```
#### TC O(2^n * n);


## Some building function:
### 