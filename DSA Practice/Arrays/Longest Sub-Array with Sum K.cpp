class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        int n = arr.size(); 
        map<long long, int> mp;
        long long sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){

            sum += arr[i];
            if (sum == k)   ans = max(ans, i + 1);
            
            long long rem = sum - k;
    
            if(mp.find(rem) != mp.end()){
                int len = i - mp[rem];
                ans = max(ans, len);
            }
    
            if(mp.find(sum) == mp.end())   mp[sum] = i;
        }
    
        return ans;
    }
};