class Solution {
    public:
        void dfs(vector<vector<int>> &adj, vector<int> &visited, int par){
            visited[par] = true;
            for(auto it: adj[par]){
                if(!visited[it]) dfs(adj, visited, it);
            }
        }
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();
            vector<vector<int>> adj(n+1);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(isConnected[i][j] && i != j) adj[i+1].push_back(j+1);
                }
            }
            vector<int> visited(n+1, false);
            int cnt = 0;
            for(int i = 1; i <= n; i++){
                if(!visited[i]){
                    dfs(adj, visited, i);
                    cnt++;
                }
            }
            return cnt;
        }
    };