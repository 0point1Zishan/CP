class Solution {
    public:
        void dfs(vector<vector<int>>& graph, vector<int> &color, int par, bool &isB, int c){
            color[par] = c;
            for(auto it: graph[par]){
                if(color[it] == c){
                    isB = false;
                    return;
                }
                else if(!color[it]) dfs(graph, color, it, isB, (c == -1) ? -2  :  -1);
            }
        }
        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> color(n, 0);
            bool isB = true;
            for(int i = 0; i < n; i++){
                if(!color[i] && graph[i].size()){
                    dfs(graph, color, i, isB, -1);
                }
            }
            return isB;
        }
    };