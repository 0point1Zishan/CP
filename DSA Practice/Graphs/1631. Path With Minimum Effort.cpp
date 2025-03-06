class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            int n = heights.size(), m = heights[0].size(), miniEffort = 0;
            vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            vector<vector<bool>> visited(n, vector<bool>(m, false));
    
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
            pq.push({0, {0, 0}});
    
            while(!pq.empty()){
                int x = pq.top().second.first;
                int y = pq.top().second.second;
                int effort = pq.top().first;
    
                miniEffort = max(effort, miniEffort);
                if(x == n-1 && y == m-1) return miniEffort;
    
                int val = heights[x][y];
                visited[x][y] = true;
                pq.pop();
    
                for(auto it: dir){
                    int r = x + it.first;
                    int c = y + it.second;
    
                    if(r >= 0 && c >= 0 && r < n && c < m && !visited[r][c]){
                        int curVal = heights[r][c];
                        pq.push({abs(curVal - val), {r, c}});
                    }
                }
            }
            return -1;
        }
    };