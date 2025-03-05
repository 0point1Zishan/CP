class Solution {
    public:
      void topoSort(vector< vector<pair<int, int> > > &adj, vector<bool> &visited, stack<int>& st, int cur){
          visited[cur] = true;
          for(auto it: adj[cur]){
              if(!visited[it.first]){
                  topoSort(adj, visited, st, it.first);
              }
          }
          st.push(cur);
      }
      vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
          // code here
          vector<int> dis(V, 1e9);
          dis[0] = 0;
          vector< vector<pair<int, int> > > adj(V);
          for(auto it: edges){
              adj[it[0]].push_back({it[1], it[2]});
          }
          
          stack<int> st;
          vector<bool> visited(V, false);
          for(int i = 0; i < V; i++){
              if(!visited[i])  topoSort(adj, visited, st, i);
          }
          
          while(!st.empty()){
              int par = st.top();
              st.pop();
              
              for(auto it: adj[par]){
                  if(dis[par] + it.second < dis[it.first])  dis[it.first] = dis[par] + it.second;
  
              }
          }
          for(int i = 0; i < V; i++){
              if(dis[i] == 1e9) dis[i] = -1;
          }return dis;
      }
  };