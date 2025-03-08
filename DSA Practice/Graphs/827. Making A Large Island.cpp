class DisjointSet{
    public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }
    int findPar(int n){
        if(parent[n] == n) return n;
        return parent[n] = findPar(parent[n]);
    }
    void unionBySize(int u, int v){
        int parU = findPar(u);
        int parV = findPar(v);
        if(parU == parV) return;
        if(size[parU] < size[parV]){
            size[parV] += size[parU];
            parent[parU] = parV;
        }
        else if(size[parV] < size[parU]){
            size[parU] += size[parV];
            parent[parV] = parU;
        }
        else{
            parent[parV] = parU;
            size[parU] += size[parV];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int n = grid.size();
        DisjointSet ds(n*n);
        vector<vector<int>>visited (n, vector<int>(n, false));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] && !visited[i][j]){
                    
                    visited[i][j] = true;
                    for(auto it: dir){
                        int r = it.first + i;
                        int c = it.second + j;
                        if(r >= 0 && c >= 0 && r < n && c < n && visited[r][c]){
                            int u = i * n + j;
                            int v = r * n + c;
                            if(ds.findPar(u) != ds.findPar(v))   ds.unionBySize(u, v);
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                
                if(!grid[i][j]){
                    set<int> st;
                    
                    for(auto it: dir){
                        int r = it.first + i;
                        int c = it.second + j;
                        
                        if(r >= 0 && c >= 0 && r < n && c < n && grid[r][c]){
                            int v = r * n + c;
                            st.insert(ds.findPar(v));
                        }
                    }
                    int cnt = 1;
                    for(auto it: st){
                        cnt += ds.size[it];
                    }
                    ans = max(ans, cnt);
                }
                else if(ds.findPar(i * n + j) == i * n + j){
                    ans = max(ans, ds.size[i*n+j]);
                }
            }
        }
        return ans;
    }
};