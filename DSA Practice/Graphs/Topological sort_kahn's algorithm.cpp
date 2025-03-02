class Solution {
    public:
      // Function to return list containing vertices in Topological order.
      vector<int> topologicalSort(vector<vector<int>>& adj) {
          // Your code here
          int n = adj.size();
          vector<int> indegree(n, 0);
          for(auto it: adj){
              for(auto j: it) indegree[j]++;
          }
          
          queue<int> q;
          for(int i = 0; i < n; i++){
              if(!indegree[i]) q.push(i);
          }
          vector<int> topoSort;
          while(!q.empty()){
              topoSort.push_back(q.front());
              q.pop();
              
              for(auto it: adj[topoSort.back()]){
                  indegree[it]--;
                  if(!indegree[it]) q.push(it);
              }
          }
          return topoSort;
      }