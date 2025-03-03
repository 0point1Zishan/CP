class Solution {
    public:
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<vector<int>> adj(n);
            vector<int> indegree(n, 0);
    
            for(int i = 0; i < n; i++){
                for(auto it: graph[i]){
                    adj[it].push_back(i);
                    indegree[i]++;
                }
            }
    
            queue<int> q;
            for(int i = 0; i < n; i++){
                if(!indegree[i]) q.push(i);
            }
            vector<int> ans;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                ans.push_back(cur);
    
                for(auto it: adj[cur]){
                    indegree[it]--;
                    if(!indegree[it]) q.push(it);
                }
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
    
    };