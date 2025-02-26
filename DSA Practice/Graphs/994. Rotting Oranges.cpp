class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            queue<pair<int, int>> q;
            int empty = 0, others = 0;
            int n = grid.size(), m = grid[0].size();
            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[0].size(); j++){
                    if(grid[i][j] == 2){
                        q.push({i, j});
                    }
                    else if(!grid[i][j]) empty++;
                }
            }
            int cnt = 0;
            vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            while(!q.empty()){
                int sz = q.size(), flag = 0;
                others += sz;
                for(int i = 0; i < sz; i++){
                    auto top = q.front();
                    q.pop();
                    for(int j = 0; j < 4; j++){
                        int x = top.first + dir[j].first;
                        int y = top.second + dir[j].second;
                        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1){
                            q.push({x, y});
                            grid[x][y] = 2;
                            flag = 1;
                        }
                    }
                }
                if(flag) cnt++;
            }
            return (n * m == others + empty)  ? cnt : -1;
        }
    };