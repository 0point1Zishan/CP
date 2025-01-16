class Solution {
private:
    void allsubset(vector<int>& nums, int i, int n, vector<int>& v, vector<vector<int>>& ans){
        if(i == n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        allsubset(nums, i+1, n, v, ans);
        v.pop_back();

        allsubset(nums, i+1, n, v, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        allsubset(nums, 0, nums.size(), v, ans);
        return ans;
    }
};