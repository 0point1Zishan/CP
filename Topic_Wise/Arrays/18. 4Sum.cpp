class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n; j++){
                int k = j+1, l = n-1;
                while(k < l){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum > target) l--;
                    else if(sum < target) k++;
                    else{
                        vector<int> a = {nums[i], nums[j], nums[k], nums[l]};
                        ans.insert(a);
                        l--;
                        k++;
                        while(k < l && nums[l] == nums[l+1]) l--;
                        while(k < l && nums[k] == nums[k-1]) k++;
                    }
                }
            }
        }
        vector<vector<int>> re(ans.begin(), ans.end());
        return re;
    }
};