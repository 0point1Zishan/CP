class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        if(n == 1 && !grid[0][0]) return 1;

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1}};
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq; 
        if(!grid[0][0]) pq.push({1, {0, 0}});
        grid[0][0] = 1;
        
        while(!pq.empty()){
            
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int dis = pq.top().first;
            pq.pop();

            for(auto it: dir){
                int r = x + it.first;
                int c = y + it.second;
                
                if(make_pair(r, c) == make_pair(n-1, n-1) && !grid[r][c])  return dis + 1;
                
                if(r >= 0 && c >= 0 && r < n && c < n && !grid[r][c]){
                    pq.push({dis+1, {r, c}});
                    grid[r][c] = 1;
                }  
                
            }
        }return -1;
    }
};