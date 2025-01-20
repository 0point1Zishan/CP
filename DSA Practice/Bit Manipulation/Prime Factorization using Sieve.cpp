class Solution {
  public:
    void sieve() {
    }

    vector<int> findPrimeFactors(int N) {

        // Write your code here
        vector<int> lowPriFactor(N+1);
        iota(lowPriFactor.begin(), lowPriFactor.end(), 0);
        
        for(int i = 2; i * i <= N; i++){
            if(lowPriFactor[i] == i){
                for(int j = i * i; j <= N; j += i){
                    if(lowPriFactor[j] == j) lowPriFactor[j] = i;
                }
            }
        }
        
        vector<int> ans;
        while(N > 1){
            ans.push_back(lowPriFactor[N]);
            N /= lowPriFactor[N];
        }
        return ans;
    }
};