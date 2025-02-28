class Solution {
    public:
        int n, m;
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        void dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int x, int y){
            visited[x][y] = true;
            for(auto it: dir){
                int r = x + it.first;
                int c = y + it.second;
                if(r >= 0 && c >= 0 && r < n-1 && c < m-1 && grid[x][y] && !visited[r][c]){
                    dfs(grid, visited, r, c);
                }
            }
        }
        int numEnclaves(vector<vector<int>>& grid) {
            n = grid.size(), m = grid[0].size();
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            for(int i = 0; i < n; i++){
                if(grid[i][0] && !visited[i][0]) dfs(grid, visited, i, 0);
                if(grid[i][m-1] && !visited[i][m-1]) dfs(grid, visited, i, m-1);
            }
            for(int i = 0; i < m; i++){
                if(grid[0][i] && !visited[0][i]) dfs(grid, visited, 0, i);
                if(grid[n-1][i] && !visited[n-1][i]) dfs(grid, visited, n-1, i);
            }
            int cnt = 0;
            for(int i = 1; i < n-1; i++){
                for(int j = 1; j < m-1; j++){
                    if(grid[i][j] && !visited[i][j]) cnt++;
                }
            }
            return cnt;
        }
    };