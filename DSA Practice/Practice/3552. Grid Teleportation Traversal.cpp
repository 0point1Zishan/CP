class Solution {
int n, m;
vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
vector<vector<pair<int,int>>> v;

public:
    int minMoves(vector<string>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        auto it = matrix;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        deque<pair<int,int>> dq;

        v.assign(26, {});
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char ch = it[i][j];
                if(ch >= 'A' && ch <= 'Z')    v[ch - 'A'].push_back({i, j});
            }
        }

        dist[0][0] = 0;
        dq.push_back({0, 0});

        while(!dq.empty()){
            auto [x, y] = dq.front();
            dq.pop_front();

            int k = dist[x][y];
            if(x == n - 1 && y == m - 1)   return k;

            for(auto &d : dir){
                int nx = x + d.first;
                int ny = y + d.second;

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(it[nx][ny] == '#') continue;

                if(k + 1 < dist[nx][ny]){
                    dist[nx][ny] = k + 1;
                    dq.push_back({nx, ny});
                }
            }

            char ch = it[x][y];
            if(ch >= 'A' && ch <= 'Z'){
                int idx = ch - 'A';

                for(auto &p : v[idx]){

                    int px = p.first, py = p.second;
                    if(px == x && py == y) continue;

                    if(k < dist[px][py]){
                        dist[px][py] = k;
                        dq.push_front({px, py});
                    }
                }
                v[idx].clear();
            }
        }
        return -1;
    }
};