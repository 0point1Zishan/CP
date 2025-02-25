class Solution {
    public:
      long long count(int n) {
          // your code here
          long long prev = 1, multi = 1;
          while(n--){
              prev *= multi;
              multi *= 2;
          }
          return prev;
      }
  };