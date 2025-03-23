class Solution {
    public:
      int countWays(string &exp) {
          // code here
          int n = exp.size();
          vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, 0)));
          for(int i = n-1; i >= 0; i--){
              for(int j = 0; j < n; j++){
                  if(i > j) continue;
      
                  for(int isT = 0; isT < 2; isT++){
                      if(i == j){
                          if(isT) dp[i][j][isT] = exp[i] == 'T';
                          else    dp[i][j][isT] = exp[i] == 'F';
                          continue;
                      }
                      
                      int way = 0;
                      for(int idx = i+1; idx < j; idx += 2){
                          int lT = dp[i][idx-1][1];
                          int lF = dp[i][idx-1][0];
                          int rT = dp[idx+1][j][1];
                          int rF = dp[idx+1][j][0];
                  
                          if(exp[idx] == '&'){
                              if(isT) way = way + (lT * rT);
                              else    way = (way + (lF * rT) + (lT * rF) + (lF * rF) ) ;
                          }
                          else if(exp[idx] == '|'){
                              if(!isT) way = (way + (lF * rF));
                              else    way = (way + (lF * rT) + (lT * rF)  + (lT * rT));
                          }
                          else{
                              if(!isT) way = (way + (lF * rF) + (lT * rT));
                              else     way = (way + (lF * rT) + (lT * rF));
                          }
                      }
                      dp[i][j][isT] = way;
                  }
              }
          }
          return dp[0][n-1][1];
          
      }
  };