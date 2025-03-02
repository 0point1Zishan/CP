class Solution {
    public:
      // Function to detect cycle in a directed graph.
      bool dfs(vector<vector<int>> &adj, vector<int> &visited, int par){
          visited[par] = 2;
          for(auto it: adj[par]){
              if(!visited[it]){
                  if(dfs(adj, visited, it)) return true;
              }
              if(visited[it] == 2)  return true;
          }
          visited[par] = 1;
          return false;
      }
      bool isCyclic(vector<vector<int>> &adj) {
          // code here
          int v = adj.size();
          vector<int> visited(v, 0);
          
          for(int i = 0; i < v; i++){
              if(!visited[i] && dfs(adj, visited, i)) return true;
          }
          return false;
      }
  };