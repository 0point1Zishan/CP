class Solution {
    public:
      int findMinDiff(vector<int>& a, int m) {
          // code here
          sort(a.begin(), a.end());
          int mn = INT_MAX;
          for(int i = 0; i <= a.size() - m; i++){
              mn = min(mn, a[i+m-1] - a[i]);
          }
          return mn;
      }
  };