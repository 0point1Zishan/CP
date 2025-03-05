class Solution {
    public:
      vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
          // Code here
          vector<vector<pair<int, int>> > adj(n + 1);
          for(auto it: edges){
              adj[it[0]].push_back({it[1], it[2]});
              adj[it[1]].push_back({it[0], it[2]});
          }
      
          vector<int> dis(n + 1, 1e9);
          vector<int> parent(n+1, -1);
          dis[1] = 0;
          priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
          pq.push({0, 1});
          
          while(!pq.empty()){
              int par = pq.top().second;
              int parDis = pq.top().first;
              pq.pop();
              
              if(parDis > dis[par]) continue;
              for(auto it: adj[par]){
                  if(it.second + parDis < dis[it.first]){
                      parent[it.first] = par;
                      dis[it.first] = it.second + parDis;
                      pq.push({dis[it.first], it.first});
                  }
              }
          }
          
          if(dis[n] == 1e9)  return {-1};
          vector<int> ans;
          int cur = n;
          while(cur != -1){
              ans.push_back(cur);
              cur = parent[cur];
          }
          reverse(ans.begin(), ans.end());
          ans.insert(ans.begin(), dis[n]);
  
          return ans;
      }
  };