class DisjointSet{
    vector<int> rank, parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }
    int findPar(int n){
        if(parent[n] == n) return n;
        return parent[n] = findPar(parent[n]);
    }
    void unionByRank(int u, int v){
        int paru = findPar(u);
        int parv = findPar(v);
        
        if(paru == parv) return;
        if(rank[parv] < rank[paru]) parent[parv] = paru;
        else if(rank[paru] < rank[parv]) parent[paru] = parv;
        else{
            parent[parv] = paru;
            rank[paru]++;
        }
    }
};
// User function Template for C++
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>>visited (n, vector<int>(m, false));
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<int> ans;
        
        int cnt = 0;
        for(auto it: operators){
            
            int x = it[0], y = it[1];
            if(visited[x][y]){
                ans.push_back(cnt);
                continue;
            }
            
            visited[x][y] = true;
            cnt++;
            
            for(auto it: dir){
                int r = it.first + x;
                int c = it.second + y;
                if(r >= 0 && c >= 0 && r < n && c < m && visited[r][c]){
                    int u = x * m + y;
                    int v = r * m + c;
                    if(ds.findPar(u) != ds.findPar(v)){
                        cnt--;
                        ds.unionByRank(u, v);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};