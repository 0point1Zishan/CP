class Solution {
 private:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool isExist(int i, int n, int x, int y, string &word, vector<vector<char>> &board){
        if(i == n) return true;
        int row = board.size(), col = board[0].size();

        if(x < 0 || y < 0 || x >= row || y >= col || board[x][y] != word[i]) return false;

        char ch = board[x][y];
        board[x][y] = '*';

        for(auto &d : dir){
            int xx = x + d.first, yy = y + d.second;
            if(isExist(i + 1, n, xx, yy, word, board)){
                board[x][y] = ch;
                return true;
            }
        }
        board[x][y] = ch;

        return false;
    }

 public:
    bool exist(vector<vector<char>> &board, string word) {
        int n = board.size(), m = board[0].size();
        int sz = word.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    if(isExist(0, sz, i, j, word, board))  return true;
                }
            }
        }
        return false;
    }
};
