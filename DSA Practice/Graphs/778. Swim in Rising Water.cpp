class Solution {
    public:
        int swimInWater(vector<vector<int>>& grid) {
            int n = grid.size(), mx = 0;
            vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
            pq.push({grid[0][0], {0, 0}});
            vis[0][0] = true;
    
            while(!pq.empty()){
                int v = pq.top().first;
                int x = pq.top().second.first;
                int y = pq.top().second.second;
                pq.pop();
    
                mx = max(mx, v);
                if(x == n-1 && y == n-1) return mx;
    
                for(auto it: dir){
                    int r = it.first + x;
                    int c = it.second + y;
                    if(r >= 0 && c >= 0 && r < n && c < n && !vis[r][c]){
                        vis[r][c] = true;
                        pq.push({grid[r][c], {r, c}});
                    }
                }
            }
            return -1;
        }
    };