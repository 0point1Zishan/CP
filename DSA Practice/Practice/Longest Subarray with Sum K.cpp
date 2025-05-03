class Solution {
    public:
      int longestSubarray(vector<int>& arr, int k) {
          // code here
          int n = arr.size(), sum = 0, ans = 0;
          map<int, int> mp;
          for(int i = 0; i < n; i++){
              
              sum += arr[i];
              if(sum == k) ans = i + 1;
              
              else{
                  int rem = sum - k;
                  if(mp.find(rem) != mp.end()){
                      int len = i - mp[rem];
                      ans = max(ans, len);
                  }
              }
              if(mp.find(sum) == mp.end()) mp[sum] = i;
          }
          return ans;
      }
  };