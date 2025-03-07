class Solution {
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> t(n, 1e18);
        vector<long long> ways(n, 0);
        
        pq.push({0, 0});
        t[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            
            long long par = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();
            
            if(dis > t[par]) continue;
            
            for(auto it: adj[par]){
                
                long long node = it.first;
                long long tt = it.second;
                
                if(dis + tt < t[node]){
                    t[node] = dis + tt;
                    ways[node] = ways[par];
                    pq.push({t[node], node});
                }
                else if(dis+tt == t[node]){
                    ways[node] = (ways[node] + ways[par]) % MOD;
                }
            }
        }
        return (t[n-1] == 1e18)  ?  0 :  ways[n-1] % MOD;
    }
};