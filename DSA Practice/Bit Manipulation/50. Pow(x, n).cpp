class Solution {
private:
    double binaryExponentiation(double x, int n){
        double res = 1;
        while(n){
            if(n & 1) res = res * x;
            x *= x;
            n = n / 2;
        }
        return res;
    }
public:
    double myPow(double x, int n) {
        double val = binaryExponentiation(x, n);
        if(n < 0) val = 1.0 / val;
        return val;
    }
};