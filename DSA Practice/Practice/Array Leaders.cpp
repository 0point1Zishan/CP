class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> ans;
        int mx = arr.back();
        ans.push_back(mx);
        for(int i = n-2; i >= 0; i--){
            if(mx <= arr[i]){
                mx = arr[i];
                ans.push_back(mx);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};