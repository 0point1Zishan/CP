class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        int sign = 1;
        if(dividend >= 0 && divisor < 0) sign = 0;
        if(dividend < 0 && divisor > 0) sign = 0;

        long long n = (dividend < 0) ? (long long)dividend * -1  : dividend;
        long long a = (divisor < 0) ? (long long)divisor * -1  : divisor;
        long long d = a;

        long long ans = 0;
        while(n >= d){
            long long bits = 0;
            while(n >= (d << (bits + 1))) bits++;

            ans += (1LL << bits);
            n = n - (d * (1LL << bits));
        }


        if(sign && ans >= INT_MAX) return INT_MAX;
        if(!sign && ans >= (1LL << 31)) return INT_MIN;

        return (sign) ? ans  :  ans * -1;
    }
};