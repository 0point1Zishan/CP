class Solution {
private:
    void sol(vector<int>& candidates, int i, int n, int target, vector<vector<int>>& ans, vector<int>& v){
        if(i == n && target != 0)   return;
        
        if(target == 0){
            ans.push_back(v);
            return;
        }

        if(candidates[i] <= target){
            v.push_back(candidates[i]);
            sol(candidates, i, n, target - candidates[i], ans, v);
            v.pop_back();
        }
        sol(candidates, i+1, n, target, ans, v);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int>v;
        sol(candidates, 0, candidates.size(), target, ans, v);
        return ans;
    }
};