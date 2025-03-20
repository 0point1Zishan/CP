class Solution {
    public:
      int LongestBitonicSequence(int n, vector<int> &arr) {
          // code here
          vector<int> dp1(n, 1), dp2(n, 1);
          for(int i = 1; i < n; i++){
              for(int j = 0; j < i; j++){
                  if(arr[i] > arr[j] && dp1[i] < dp1[j] + 1) dp1[i] = dp1[j] + 1;
              }
          }
          for(int i = n-2; i >= 0; i--){
              for(int j = n-1; j > i; j--){
                  if(arr[i] > arr[j] && dp2[i] < dp2[j] + 1) dp2[i] = dp2[j] + 1;
              }
          }
          int mx = 1;
          for(int i = 0; i < n; i++){
               if(dp1[i] > 1 && dp2[i] > 1){
                   mx = max(mx, dp1[i] + dp2[i] - 1);
               }
          }
          return mx < 3 ? 0 : mx;
      }
  };