class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int n = nums.size(), ans = 0;
            for(int i = 0; i < pow(2, n); i++){
                int x = 0;
                for(int j = 0; j < n; j++){
                    if( (i & (1 << j)) ){
                        x ^= nums[j];
                    }
                }
                ans += x;
            }
            return ans;
        }
    };