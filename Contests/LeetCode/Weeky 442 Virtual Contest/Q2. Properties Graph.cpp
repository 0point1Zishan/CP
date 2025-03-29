class Solution {
    private:
        void dfs(int node, vector<vector<int>> &adj, vector<bool>& vis){
            vis[node] = true;
            for(auto &it: adj[node]){
                if(!vis[it]) dfs(it, adj, vis);
            }
        }
    public:
        int numberOfComponents(vector<vector<int>>& properties, int k) {
            int n = properties.size();
            vector<vector<int>> adj(n);
    
            auto intersect = [&](int i, int j){
                unordered_set<int> st;
                for(auto &i: properties[i]){
                    for(auto &j: properties[j]){
                        if(i == j) st.insert(i);
                    }
                }
                return (st.size() >= k);
            };
            
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    if(intersect(i, j)){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
            int cnt = 0;
            vector<bool> vis(n, 0);
            for(int i = 0; i < n; i++){
                if(!vis[i]){
                    dfs(i, adj, vis);
                    cnt++;
                }
            }
            return cnt;
        }
    };