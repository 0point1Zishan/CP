long long int floorSqrt(long long int N)
{
    long long s = 0, e = N, ans = N;
    while(s <= e){
        long long mid = s + (e - s) / 2;
        if((mid * mid) <= N){
            ans = mid;
            s = mid + 1;
        }
        else e = mid - 1;
    }
    return ans;
}