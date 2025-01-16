class Solution {
public:
    double binaryExponentiation(double a, int b){
        if(b == 0) return 1;

        double res = binaryExponentiation(a, b / 2);
        if(b & 1) return res * res * a;
        else return res * res;
        
    }
    double myPow(double x, int n) {
        double ans = binaryExponentiation(x, n);
        if(n < 0) ans = 1.0 / ans;
        return ans;
    }
};