class Solution {
  private:
    int Xor(int r){
        if(r % 4 == 1)       return 1;
        else if(r % 4 == 2)  return r+1;
        else if(r % 4 == 3)  return 0;
        return r;
    }
  public:
    int findXOR(int l, int r) {
        // complete the function here
        return Xor(r) ^ Xor(l-1);
    }
};