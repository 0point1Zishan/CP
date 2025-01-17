class Solution {
private:
    void sol(vector<int>& nums, int i, int n, vector<int>& v, vector<vector<int>>& ans){
        ans.push_back(v);

        for(int j = i; j < n; j++){
            if(j > i && nums[j] == nums[j-1]) continue;
            v.push_back(nums[j]);
            sol(nums, j+1, n, v, ans);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        sol(nums, 0, nums.size(), v, ans);
        return ans;
    }
};