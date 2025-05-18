class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int n = arr.size();
        int s = 0, e = n-1,ans = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        long long sum = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i] == 0) ans = max(ans, 1);
            sum += arr[i];
            if(mp.find(sum) != mp.end()){
                ans = max(ans, i - mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
        return ans;
    }
};