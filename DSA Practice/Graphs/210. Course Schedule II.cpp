class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> adj(numCourses);
            for(auto it: prerequisites)   adj[it[1]].push_back(it[0]);
            
            vector<int> indegree(numCourses, 0);
            for(auto i: adj){
                for(auto j: i) indegree[j]++;
            }
    
            queue<int> q;
            for(int i = 0; i < numCourses; i++){
                if(!indegree[i]) q.push(i);
            }
    
            vector<int> ans;
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
    
                for(auto it: adj[curr]){
                    indegree[it]--;
                    if(!indegree[it]) q.push(it);
                }
            }
            if(ans.size() != numCourses) ans.clear();
            return ans;
        }
    };