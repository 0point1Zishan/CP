class Solution {
  private:
    bool isSafe(int node, vector<int>& color, int c, vector<vector<int>>& adj){
        for(int i = 0; i < adj[node].size(); i++){
            if(color[adj[node][i]] == c) return false;
        }return true;
    }
    bool isPossible(int node, vector<int>& color, int m, int v, vector<vector<int>>& adj){
        if(node == v) return true;
        
        for(int i = 1; i <= m; i++){
            if(isSafe(node, color, i, adj)){
                color[node] = i;
                if(isPossible(node+1, color, m, v, adj)) return true;
                color[node] = -1;
            }
        }
        return false;
    }
  public:
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<vector<int>> adj(v);
        int edgSz = edges.size();
        
        for(int i = 0; i < edgSz; i++){
            int a = edges[i].first;
            int b = edges[i].second;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> color(v, -1);
        return isPossible(0, color, m, v, adj);
    }
};