class Solution {
    public:
      // Function to find the shortest path from source to all other nodes
      vector<int> shortestPath(vector<vector<int>>& adj, int src) {
          // code here
          int n = adj.size();
          vector<int> parent(n, -1);
          
          queue<int> q;
          q.push(src);
          parent[src] = 0;
          
          while(!q.empty()){
              int par = q.front();
              q.pop();
              
              for(auto it: adj[par]){
                  if(parent[it] == -1){
                      parent[it] = parent[par] + 1;
                      q.push(it);
                  }
              }
          }
          return parent;
      }
  };