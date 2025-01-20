class Solution {
  public:
    bool isEven(int n) {
        // code here
        return (n & 1) == 0;
    }
};