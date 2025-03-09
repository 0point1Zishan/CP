class Solution {
    private:
    int t = 1;
    void dfs(int node, int par, vector<int>& ti, vector<int>& low, vector<bool>& vis, vector<bool>& isArti, vector<int>adj[]){
        vis[node] = true;
        ti[node] = low[node] = t;
        t++;
        
        int child = 0;
        for(auto it: adj[node]){
            if(it == par) continue;
            if(!vis[it]){
                dfs(it, node, ti, low, vis, isArti, adj);
                low[node] = min(low[node], low[it]);
                
                if(low[it] >= ti[node] && par != -1) isArti[node] = true;
                child++;
            }
            else low[node] = min(low[node], ti[it]);
        }
        if(child > 1 && par == -1) isArti[node] = true;
    }
    
    public:
      vector<int> articulationPoints(int V, vector<int>adj[]) {
          // Code here
          vector<bool> vis(V, false), isArti(V, false);
          vector<int> ti(V), low(V);
          for(int i = 0; i < V; i++){
              if(!vis[i]) dfs(i, -1, ti, low, vis, isArti, adj);
          }
          
          vector<int> ans;
          for(int i = 0; i < V; i++){
              if(isArti[i]) ans.push_back(i);
          }
          if(ans.size()) return ans;
          return {-1};
      }
  };