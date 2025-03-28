class Solution {
    private:
        long long sol(int n){
            long long inc = 4, k = 1, i = 1, ans = 0;
            while(1){
                if(k > n) return ans;
    
                long long maximum = min(inc - 1, n * 1LL);
                ans += (i * (maximum - k + 1));
    
                inc *= 4;
                k *= 4;
                i++;
            }
            return ans;
        }
    public:
        long long minOperations(vector<vector<int>>& queries) {
            long long ans = 0;
            for(auto &it: queries){
                
                long long left = sol(it[0] - 1), right = sol(it[1]);
                ans += (right - left + 1) / 2;
            }
            return ans;
        }
    };
    