class Solution {
    public:
        long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
            int n = nums.size();
            vector<long long> preNums(n+1, 0), preCost(n+1, 0);
            for(int i = 1; i <= n; i++){
                preNums[i] = preNums[i-1] + nums[i-1];
                preCost[i] = preCost[i-1] + cost[i-1];
            }
    
            vector<long long> mnCost(n+2, 0);
            mnCost[n] = (nums[n-1] + k) * cost[n-1];
    
            for(int i = n-1; i > 0; i--){
    
                mnCost[i] = (preNums[n] - preNums[i-1] + k) * (preCost[n] - preCost[i-1]);
                for(int j = n; j > i; j--){
    
                    long long cur = (preNums[j-1] - preNums[i-1] + k) * (preCost[n] - preCost[i-1]);
                    mnCost[i] = min(mnCost[i], mnCost[j] + cur);
                }
            }
            return mnCost[1];
        }
    };