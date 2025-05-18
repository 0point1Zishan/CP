class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(i && nums[i] == nums[i-1]) continue;
            int req = -(nums[i]);

            int s = i+1, e = n-1;
            while(s < e){
                if(nums[s] + nums[e] == req){
                    vector<int> v = {nums[i], nums[s], nums[e]};
                    sort(v.begin(), v.end());
                    ans.push_back(v);
                    while(s+1 < e && nums[s] == nums[s+1]) s++;
                    while(e-1 > s && nums[e] == nums[e-1]) e--;
                    s++;
                }
                else if(nums[s] + nums[e] > req) e--;
                else s++;
            }
        }
        return ans;
    }
};