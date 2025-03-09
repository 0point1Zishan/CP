class Solution {
    public:
      int count(vector<int>& coins, int sum) {
          // code here.
          int n = coins.size();
          vector<long> pre(sum+1, 0);
          for(int i = 0; i <= sum; i++){
              if(i % coins[0] == 0) pre[i] = 1;
          }
      
          for(int i = 1; i < n; i++){
              vector<long>cur(sum+1, 0);
              for(int t = 0; t <= sum; t++){
                  long notTake = pre[t], take = 0;
                  if(coins[i] <= t) take = cur[t - coins[i]];
      
                  cur[t] = notTake + take;
              }
              pre = cur;
          }
          return pre[sum];
      }
  };