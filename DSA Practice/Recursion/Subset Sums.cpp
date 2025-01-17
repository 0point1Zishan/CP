class Solution {
  private:
    void sol(vector<int>& arr, int i, int n, int sum, vector<int>& ans){
        if(i == n){
            ans.push_back(sum);
            return;
        }
        sol(arr, i+1, n, sum + arr[i], ans);
        sol(arr, i+1, n, sum, ans);
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        vector<int> ans;
        sol(arr, 0, arr.size(), 0, ans);
        return ans;
    }
};