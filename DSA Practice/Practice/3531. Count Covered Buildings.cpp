class Solution {
    int INF = 1e9;
    public:
        int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
            vector<vector<int>> v(n+1, vector<int>{INF, -1, INF, -1});
            int cnt = 0;
            for(auto it: buildings){
                int row = it[0];
                int col = it[1];
    
                // U, D
                v[col][2] = min(v[col][2], row);
                v[col][3] = max(v[col][3], row);
    
                // L, R
                v[row][0] = min(v[row][0], col);
                v[row][1] = max(v[row][1], col);
            }
            for(auto it: buildings){
                int row = it[0];
                int col = it[1];
                if(v[col][2] < row && v[col][3] > row && v[row][0] < col && v[row][1] > col) cnt++;
            }
            return cnt;
        }
    };