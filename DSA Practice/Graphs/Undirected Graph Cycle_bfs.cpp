class Solution {
    public:
      // Function to detect cycle in an undirected graph.
      bool bfs(vector<vector<int>>& adj, vector<bool> &visited, int i){
          queue<pair<int, int>> q;
          q.push({i, -1});
          visited[i] = true;
          
          while(!q.empty()){
              int curr = q.front().first, par = q.front().second;
              q.pop();
              for(auto it: adj[curr]){
                  if(it != par){
                      if(visited[it]) return true;
                      q.push({it, curr});    
                      visited[it] = true;
                  }
              }
          }
          return false;
      }
      bool isCycle(vector<vector<int>>& adj) {
          // Code here
          int n = adj.size();
          vector<bool> visited(n, false);
          for(int i = 0; i < n; i++){
              if(!visited[i]){
                  if(bfs(adj, visited, i)) return true;
              }
          }
          return false;
      }
  };