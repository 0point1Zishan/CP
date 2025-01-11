class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_set<int> row, col;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0)  row.insert(i), col.insert(j);
            }
        }
        for(auto it: row){
            for(int i = 0; i < m; i++) matrix[it][i] = 0;
        }
        for(auto it: col){
            for(int i = 0; i < n; i++) matrix[i][it] = 0;
        }
    }
};