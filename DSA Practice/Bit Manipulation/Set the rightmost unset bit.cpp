class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        int temp = n, x = 0;
        while(n){
            if( (n & 1) == 0) break;
            n = n >> 1;
            x++;
        }
        return temp | (1 << x);
    }
};