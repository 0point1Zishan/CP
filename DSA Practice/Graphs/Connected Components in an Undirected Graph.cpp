class Solution {
    public:
      void bfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &v, int pre){
          queue<int>q;
          q.push(pre);
          visited[pre] = true;
          while(!q.empty()){
              auto node = q.front();
              q.pop();
              v.push_back(node);
              for(auto it: adj[node]){
                  if(!visited[it]){
                      q.push(it);
                      visited[it] = true;
                  }
              }
          }
      }
      vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
          // code here
          vector<vector<int>> adj(v);
          vector<bool> visited(v, false);
          for(auto it: edges){
              adj[it[0]].push_back(it[1]);
              adj[it[1]].push_back(it[0]);
          }
          
          vector<vector<int>> ans;
          for(int i = 0; i < v; i++){
              if(!visited[i]){
                  vector<int>v;
                  bfs(adj, visited, v, i);
                  sort(v.begin(), v.end());
                  ans.push_back(v);
              }
          }
          return ans;
      }
  };