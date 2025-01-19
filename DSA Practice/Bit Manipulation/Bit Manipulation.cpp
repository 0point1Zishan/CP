class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        if((num & (1 << (i-1)))){
            cout << 1 << " ";
        }else cout << 0 << " ";
        
        if(!(num & (1 << (i-1))) ){
            num = num | (1 << (i - 1));
        }
        cout << num << " ";
        if((num & (1 << (i-1)))){
            num = num ^ (1 << (i - 1));
        }
        cout << num;
    }
};