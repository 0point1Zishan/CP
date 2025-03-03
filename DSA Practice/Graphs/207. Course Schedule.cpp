class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
            vector<vector<int>> adj(numCourses);
            for(auto it: prerequisites)   adj[it[0]].push_back(it[1]);
            
            vector<int> indegree(numCourses, 0);
            for(auto i: adj){
                for(auto j: i) indegree[j]++;
            }
    
            queue<int> q;
            for(int i = 0; i < numCourses; i++){
                if(!indegree[i]) q.push(i);
            }
    
            int cnt = 0;
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                cnt++;
    
                for(auto it: adj[curr]){
                    indegree[it]--;
                    if(!indegree[it]) q.push(it);
                }
            }
            return cnt == numCourses;
        }
    };