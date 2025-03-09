class Solution {
    private:
      void dfs(int node, vector<bool>& vis, vector<vector<int>> &adj, stack<int> &st, bool &isT){
          vis[node] = true;
          for(auto it: adj[node]){
              if(!vis[it]) dfs(it, vis, adj, st, isT);
          }
          if(isT) st.push(node);
      }
    public:
      int kosaraju(vector<vector<int>> &adj) {
          // code here
          int n = adj.size();
          vector<bool> vis(n, false);
          stack<int> st;
          
          bool isT = true;
          for(int i = 0; i < n; i++){
              if(!vis[i]) dfs(i, vis, adj, st, isT);
          }
          
          vector<vector<int>> adj2(n);
          for(int i = 0; i < n; i++){
              vis[i] = false;
              for(auto it: adj[i]) adj2[it].push_back(i);
          }
          
          int scc = 0;
          isT = false;
          while(!st.empty()){
              if(!vis[st.top()]){
                  scc++;
                  dfs(st.top(),vis, adj2, st, isT);
              }
              st.pop();
          }
          return scc;
      }
  };