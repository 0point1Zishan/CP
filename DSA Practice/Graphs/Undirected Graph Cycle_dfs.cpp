class Solution {
    public:
      // Function to detect cycle in an undirected graph.
      bool dfs(vector<vector<int>>& adj, vector<bool> &visited, int curr, int par){
          visited[curr] = true;
  
          for(auto it: adj[curr]){
              if(it != par){
                  if(visited[it]) return true;
                  if(dfs(adj, visited, it, curr)) return true;;
              }
          }
          return false;
      }
      bool isCycle(vector<vector<int>>& adj) {
          // Code here
          int n = adj.size();
          vector<bool> visited(n, false);
          for(int i = 0; i < n; i++){
              if(!visited[i] && dfs(adj, visited, i, -1)) return true;
          }
          return false;
      }
  };