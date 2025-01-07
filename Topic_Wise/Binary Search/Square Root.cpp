class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int s = 0, e = n, ans = n;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if( (mid * mid) <= n){
                ans = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }return ans;
    }
};