class Solution{
    private:
    int mxBit(int n){
        int cnt = 0;
        while(n){
            cnt++;
            n = n >> 1;
        }
        return cnt-1;
    }
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        if(n == 0) return 0;
        int x = mxBit(n);

        return  x * (1 << (x-1)) + (n - (1 << x)) + 1 + countSetBits(n - (1 << x));
    }
};