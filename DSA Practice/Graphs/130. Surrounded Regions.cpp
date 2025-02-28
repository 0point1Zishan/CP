class Solution {
    public:
        int n, m;
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        void dfs(vector<vector<char>>& board, vector<vector<bool>> &visited, int x, int y){
            visited[x][y] = true;
            for(auto it: dir){
                int r = x + it.first;
                int c = y + it.second;
                if(r >= 0 && c >= 0 && r < n-1 && c < m-1 && board[x][y] == 'O' && !visited[r][c]){
                    dfs(board, visited, r, c);
                }
            }
        }
        void solve(vector<vector<char>>& board) {
            n = board.size(), m = board[0].size();
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            for(int i = 0; i < n; i++){
                if(board[i][0] == 'O' && !visited[i][0]) dfs(board, visited, i, 0);
                if(board[i][m-1] == 'O' && !visited[i][m-1]) dfs(board, visited, i, m-1);
            }
            for(int i = 0; i < m; i++){
                if(board[0][i] == 'O' && !visited[0][i]) dfs(board, visited, 0, i);
                if(board[n-1][i] == 'O' && !visited[n-1][i]) dfs(board, visited, n-1, i);
            }
            for(int i = 1; i < n-1; i++){
                for(int j = 1; j < m-1; j++){
                    if(board[i][j] == 'O' && !visited[i][j]) board[i][j] = 'X';
                }
            }
        }
    };