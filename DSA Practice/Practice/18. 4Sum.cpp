class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            if(i && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n; j++){
                if(j > i + 1 && nums[j] == nums[j-1]) continue;

                long long req = target - (0LL + nums[i] + nums[j]);
                int s = j + 1, e = n-1;
                while(s < e){
                    if(nums[s] + nums[e] == req){
                        vector<int> v = {nums[i], nums[j], nums[s], nums[e]};
                        sort(nums.begin(), nums.end());
                        ans.push_back(v);
                        s++;
                        e--;
                        while(s < e && nums[s] == nums[s-1]) s++;
                        while(e > s && nums[e] == nums[e+1]) e--;
                    }
                    else if(nums[s] + nums[e] > req) e--;
                    else s++;
                }
            }
        }
        return ans;
    }
};