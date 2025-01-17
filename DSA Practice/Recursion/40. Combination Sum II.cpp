class Solution {
private:
    void sol(vector<int>& candidates, int i, int n, int target, vector<vector<int>>& ans, vector<int>& v){
        
        if(target == 0){
            ans.push_back(v);
            return;
        }

        for(int j = i; j < n; j++){
            if(j > i && candidates[j-1] == candidates[j]) continue;
            if(candidates[j] > target) break;

            v.push_back(candidates[j]);
            sol(candidates, j+1, n, target - candidates[j], ans, v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int>v;
        sol(candidates, 0, candidates.size(), target, ans, v);
        return ans;
    }
};