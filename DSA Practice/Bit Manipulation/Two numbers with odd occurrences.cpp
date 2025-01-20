class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long Xor = 0;
        for(int i = 0; i < N; i++) Xor ^= Arr[i];
    
        Xor = (Xor & (Xor - 1)) ^ Xor;
        
        long long a = 0, b = 0;
        for(int i = 0; i < N; i++){
            if( Xor & Arr[i])      a ^= Arr[i];
            else                   b ^= Arr[i];
        }
        
        if(a < b) swap(a, b);
        return {a, b};
    }
};