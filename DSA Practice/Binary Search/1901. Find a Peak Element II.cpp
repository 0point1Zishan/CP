class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int s = 0, e = m-1;
        while(s <= e){
            int col = s + (e - s) / 2;

            int row = -1, mx = INT_MIN;
            for(int i = 0; i < n; i++){
                if(mat[i][col] > mx){
                    mx = mat[i][col];
                    row = i;
                }
            }

            if(col > 0 && mat[row][col-1] > mat[row][col])    e = col-1;
            else if(col < m-1 && mat[row][col+1] > mat[row][col])  s = col + 1;
            else return {row, col};
        }
        return {-1, -1};
    }
};