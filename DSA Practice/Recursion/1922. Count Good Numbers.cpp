class Solution {
public:
    int mod = 1e9 + 7;
    long long binaryExponentiation(long long a, long long b){
        if(b == 0) return 1;
        long long res = binaryExponentiation(a, b / 2);

        if(b & 1) return ((res * res) % mod * a) % mod;
        else      return (res * res) % mod;
    }
    int countGoodNumbers(long long n) {
        long long nofive = (n / 2) + ((n & 1) ? 1 : 0);
        long long nofour = (n / 2);

       return  (binaryExponentiation(5, nofive) * binaryExponentiation(4, nofour)) % mod;
    }
};