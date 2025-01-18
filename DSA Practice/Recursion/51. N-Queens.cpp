class Solution {
    bool valid(int x, int y, vector<string>& v){
        int n = v.size();

        int i = x, j = y;
        while(i >= 0 && j >= 0){
            if(v[i][j] == 'Q') return false;
            i--;  j--;
        }
        i = x, j = y;
        while(i >= 0 && j < n){
            if(v[i][j] == 'Q') return false;
            i--; j++;
        }

        for(int i = 0; i <= x; i++){
            if(v[i][y] == 'Q') return false;
        }
        return true;

    }
    void sol(int x, int y, int n, vector<vector<string>>& ans, vector<string>& v){
        if(x >= n){
            ans.push_back(v);
            return;
        }
        for(int j = 0; j < n; j++){
            if(valid(x, j, v)){
                v[x][j] = 'Q';
                sol(x+1, j, n, ans, v);
                v[x][j] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> v(n, string(n, '.'));
        sol(0, 0, n, ans, v);
        return ans;
    }
};