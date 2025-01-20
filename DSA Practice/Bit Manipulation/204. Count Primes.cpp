class Solution {
public:
    int countPrimes(int n) {
        if(n < 3) return 0;
        vector<bool> prime(n+1, 1);
        for(int i = 3; i * i <= n; i += 2){
            if(prime[i]){
                for(int j = i * i; j <= n; j += i) prime[j] = 0;
            }
        }
        int cnt = 1;
        for(int i = 3; i < n; i += 2){
            if(prime[i]) cnt++;
        }
        return cnt;
    }
};