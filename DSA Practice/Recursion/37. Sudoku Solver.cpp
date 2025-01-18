class Solution {
bool isPossible(vector<vector<char>>& board, int x, int y, char ch){
    for(int i = 0; i < 9; i++){
        if(board[i][y] == ch) return false;
        if(board[x][i] == ch) return false;
    }
    int bx = (x / 3) * 3;
    int by = (y / 3) * 3;
    for(int i = bx; i < (bx+3); i++){
        for(int j = by; j < (by + 3); j++){
            if(board[i][j] == ch) return false;
        }
    }return true;
}
private:
    bool sol(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){

                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(isPossible(board, i, j, c)){
                            board[i][j] = c;
                            if(sol(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        sol(board);
    }
};