class value{
    public:
    int x, y, dis;
    value(int x, int y, int dis){
        this->x = x;
        this->y = y;
        this->dis = dis;
    }
};
class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> ans = mat;
        
        queue<value> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push(value(i, j, 0));
                    visited[i][j] = true;
                }
            }
        }
        
        while(!q.empty()){
            int r = q.front().x;
            int c = q.front().y;
            int val = q.front().dis;
            q.pop();
            ans[r][c] = val;
            
            for(auto it: dir){
                int x = r + it.first;
                int y = c + it.second;
                
                if(x >= 0 && y >= 0 && x < n && y < m && !visited[x][y]){
                    q.push(value(x, y, val+1));
                    visited[x][y] = true;
                }
            }
        }
        return ans;
    }
};