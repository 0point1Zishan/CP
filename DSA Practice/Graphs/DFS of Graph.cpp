class Solution {
    public:
      // Function to return a list containing the DFS traversal of the graph.
      void dfs(vector<vector<int>>& adj, vector<int>& v, vector<bool> &visited, int par){
          v.push_back(par);
          visited[par] = true;
          for(auto it: adj[par]){
              if(!visited[it]) dfs(adj, v, visited, it);
          }
      }
      vector<int> dfsOfGraph(vector<vector<int>>& adj) {
          // Code here
          vector<int>v;
          vector<bool> visited(adj.size(), false);
          dfs(adj, v, visited, 0);
          return v;
      }
  };