class Solution {
    public:
      // Function to return Breadth First Traversal of given graph.
      vector<int> bfsOfGraph(vector<vector<int>> &adj) {
          // Code here
          vector<int> v;
          queue<int> q;
          vector<bool> visited(adj.size(), false);
          v.push_back(0);
          q.push(0);
          visited[0] = true;
          
          while(!q.empty()){
              auto pre = q.front();
              q.pop();
              for(auto it: adj[pre]){
                  if(!visited[it]){
                      v.push_back(it);
                      visited[it] = true;
                      q.push(it);
                  }
              }
          }
          return v;
      }
  };