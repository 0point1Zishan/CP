class Solution {
    public:
      // Function to find sum of weights of edges of the Minimum Spanning Tree.
      int spanningTree(int V, vector<vector<int>> adj[]) {
          // code here
          vector<bool> visited(V, false);
          int sum = 0;
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
          pq.push({0, 0});
          
          while(!pq.empty()){
              int node = pq.top().second;
              int cost = pq.top().first;
              pq.pop();
              
              if(visited[node]) continue;
              sum += cost;
              visited[node] = true;
              
              for(auto it: adj[node]){
                  int adjNode = it[0];
                  int weight = it[1];
                  
                  if(!visited[adjNode]){
                      pq.push({weight, adjNode});
                  }
              }
          }
          return sum;
      }
  };