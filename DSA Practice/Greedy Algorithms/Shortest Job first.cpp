class Solution {
    public:
      long long solve(vector<int>& bt) {
          // code here
          int n = bt.size();
          sort(bt.begin(), bt.end());
          
          long long ans = 0, total = 0;
          for(int i = 1; i < n; i++){
              total += bt[i-1];
              ans += total;
          }
          return ans / n;
      }
  };