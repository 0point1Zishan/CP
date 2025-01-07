class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        int s = 0, e = m;
        while(s <= e){
            int mid = s + (e - s) / 2;
            long long mul = 1, i = 1;
            for(; i <= n; i++){
                mul *= mid;
                if(mul > m) break;
            }
            if(mul == m) return mid;
            else if(mul > m) e = mid - 1;
            else             s = mid + 1;
        }return -1;
    }
};