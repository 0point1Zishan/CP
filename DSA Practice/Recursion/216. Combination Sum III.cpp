class Solution {
private:
    void sol(int i, int target, int k, int sz, vector<int>& v, vector<vector<int>>& ans){

        if(i == 10){
            if(target == 0 && k == sz){
                ans.push_back(v);
            }
            return;
        }
        if(i <= target){
            v.push_back(i);
            sol(i+1, target - i, k, sz+1, v, ans);
            v.pop_back();
        }

        sol(i+1, target, k, sz, v, ans);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        sol(1, n, k, 0, v, ans);
        return ans;
    }
};