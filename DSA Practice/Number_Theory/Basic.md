## Power
int power(int x, int n){
    double result = exp(log(x) * n);
    result = round(result);
    return static_cast<int>(result);
}