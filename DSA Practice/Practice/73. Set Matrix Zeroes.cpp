class Solution {
    public:
      void setMatrixZeroes(vector<vector<int>> &mat) {
          // code here
          int n = mat.size(), m = mat[0].size();
          bool row0 = false;
          for(int i = 0; i < n; i++){
              for(int j = 0; j < m; j++){
                  if(!mat[i][j]){
                      mat[0][j] = 0;
                      
                      if(!i) row0 = true;
                      else   mat[i][0] = 0;
                  }
              }
          }
          for(int i = 1; i < n; i++){
              for(int j = 1; j < m; j++){
                  if(!mat[i][0] || !mat[0][j]){
                      mat[i][j] = 0;
                  }
              }
          }
          if(!mat[0][0]){
              for(int i = 0; i < n; i++) mat[i][0] = 0;
          }
          if(row0){
              for(int j = 0; j < m; j++) mat[0][j] = 0;
          }
      }
  };