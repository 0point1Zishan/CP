class Solution {
    public:
      // Function to return list containing vertices in Topological order.
      void dfs(vector<vector<int>>& adj, vector<bool> &visited, stack<int> &st, int par){
          visited[par] = true;
          for(auto it: adj[par]){
              if(!visited[it]) dfs(adj, visited, st, it);
          }
          st.push(par);
      }
      vector<int> topologicalSort(vector<vector<int>>& adj) {
          // Your code here
          int n = adj.size();
          vector<bool> visited(n, false);
          stack<int> st;
          for(int i = 0; i < n; i++){
              if(!visited[i]) dfs(adj, visited, st, i);
          }
  
          vector<int> ans(st.size());
          for(int i = 0; i < ans.size(); i++){
              ans[i] = st.top();
              st.pop();
          }
          
          return ans;
      }
  };