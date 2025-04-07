class Solution {
    public:
        int minimumPairRemoval(vector<int>& nums) {
            int cost = 0;
            while(1){
    
                int sum = INT_MAX, idx = 0;
                bool isSorted = true;
                for(int i = 0; i < nums.size()-1; i++){
    
                    if(nums[i] + nums[i+1] < sum){
                        sum = nums[i] + nums[i+1];
                        idx = i;
                    }
                    if(nums[i] > nums[i+1]) isSorted = false;
                }
                if(isSorted) return cost;
    
                cost++;
                nums[idx+1] += nums[idx];
                nums.erase(nums.begin() + idx);
            }
            return cost;
        }
    };