class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<vector<pair<int, int>>> adj(n);
            for(auto it: flights){
                adj[it[0]].push_back({it[1], it[2]});
            }
    
            vector<int> costVec(n, 1e9);
            costVec[src] = 0;
    
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
            pq.push({0, {src, 0}});
    
            int ans = INT_MAX;
            while(!pq.empty()){
                int par = pq.top().second.first;
                int stops = pq.top().first;
                int cost = pq.top().second.second;
                pq.pop();
    
                for(auto it: adj[par]){
                    if(cost + it.second < costVec[it.first] && stops <= k){
                        costVec[it.first] = cost + it.second;
                        pq.push({stops+1, {it.first, costVec[it.first]}});
                    }
                }
            }
            return (costVec[dst] == 1e9)  ? -1 : costVec[dst];
        }
    };