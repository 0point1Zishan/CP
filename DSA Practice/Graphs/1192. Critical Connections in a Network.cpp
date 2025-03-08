class Solution {
    private:
        int t = 1;
        void dfs(int node, int par, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& time, vector<int>& low, vector<vector<int>>& bridges){
            vis[node] = true;
            time[node] = low[node] = t;
            t++;
    
            for(auto it: adj[node]){
                if(it == par) continue;
                if(!vis[it]){
                    dfs(it, node, adj, vis, time, low, bridges);
                    low[node] = min(low[it], low[node]);
                    if(low[it] > time[node]) bridges.push_back({it, node});
                }
                else  low[node] = min(low[node], low[it]);
            }
        }
    public:
        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            vector<vector<int>> adj(n);
            for(auto it: connections){
                int u = it[0], v = it[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
            vector<bool> vis(n, false);
            vector<int> time(n), low(n);
            vector<vector<int>> bridges;
    
            dfs(0, -1, adj, vis, time, low, bridges);
            return bridges;
        }
    };