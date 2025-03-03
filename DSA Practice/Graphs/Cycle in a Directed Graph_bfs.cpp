class Solution {
    public:
      // Function to detect cycle in a directed graph.
      bool isCyclic(vector<vector<int>> &adj) {
          // code here
          int n = adj.size();
          vector<int> indegree(n, 0);
          for(auto i: adj){
              for(auto j: i) indegree[j]++;
          }
          
          queue<int> q;
          for(int i = 0; i < n; i++){
              if(!indegree[i]) q.push(i);
          }
          
          int cnt = 0;
          while(!q.empty()){
              int curr = q.front();
              q.pop();
              cnt++;
              
              for(auto it: adj[curr]){
                  indegree[it]--;
                  if(!indegree[it])  q.push(it);
              }
          }
          return (cnt != n);
      }
  };