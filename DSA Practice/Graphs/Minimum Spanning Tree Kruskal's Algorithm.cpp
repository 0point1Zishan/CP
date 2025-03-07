class DisjointSet{
    public:
      vector<int> rank, parent;
      DisjointSet(int n){
          rank.resize(n+1,0);
          parent.resize(n+1);
          for(int i = 0; i <= n; i++) parent[i] = i;
      }
  
      int findUPar(int node){
          if(node == parent[node]) return node;
          return parent[node] = findUPar(parent[node]);
      }
  
      void unionByRank(int u, int v){
          int parU = findUPar(u);
          int parV = findUPar(v);
  
          if(parU == parV) return;
          if(rank[parU] < rank[parV]) parent[parU] = parV;
          else if(rank[parU] > rank[parV]) parent[parV] = parU;
          else{
            parent[parV] = parU;
            rank[parU]++;
          }
      }
  };
  
  class Solution {
    public:
      // Function to find sum of weights of edges of the Minimum Spanning Tree.
      int spanningTree(int V, vector<vector<int>> adj[]) {
          // code here
          vector<pair<int, pair<int, int>> > edges;
          for(int i = 0; i < V; i++){
              for(auto it: adj[i]){
                  edges.push_back({it[1], {i, it[0]}});
              }
          }
          sort(edges.begin(), edges.end());
          
          DisjointSet ds(V);
          int total = 0;
          for(auto it: edges){
              int u = it.second.first;
              int v = it.second.second;
              int w = it.first;
              
              if(ds.findUPar(u) != ds.findUPar(v)){
                  total += w;
                  ds.unionByRank(u, v);
              }
          }
          return total;
      }
  };