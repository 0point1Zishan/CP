class Solution {
  public:
    // Function to find the number of islands.
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1}};
    int row = 0, col = 0;
    void dfs(vector<vector<char>>& grid, int x, int y){
        grid[x][y] = '0';
        for(auto it: dir){
            int r = x + it.first;
            int c = y + it.second;
            if(r >= 0 && c >= 0 && r < row && c < col && grid[r][c] == '1'){
                dfs(grid, r, c);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        row = grid.size(), col = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};