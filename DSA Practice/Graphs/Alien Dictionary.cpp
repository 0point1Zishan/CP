class Solution{
    public:
        bool dfs(vector<vector<int>> &adj, vector<int> &visited, int node){
            visited[node] = 2;
            for(auto it: adj[node]){
                if(!visited[it]){
                    if(dfs(adj, visited, it)) return true;
                }
                if(visited[it] == 2) return true;
            }
            visited[node] = 1;
            return false;
        }
    
        bool isCyclic(vector<vector<int>> &adj, int k){
            vector<int> visited(26, 0);
            for(int i = 0; i < k; i++){
                if(!visited[i] && dfs(adj, visited, i)) return true;
            }
            return false;
        }
    
        string findOrder(vector<string> &dictionary){
            vector<vector<int>> adj(26);  
            vector<int> indegree(26, 0); 
            vector<bool> present(26, false);
            int k = 0;
    
            for(auto &word: dictionary){
                for(auto &ch: word) present[ch - 'a'] = true;
            }
    
            for(int i = 0; i < dictionary.size() - 1; i++){
                string &a = dictionary[i];
                string &b = dictionary[i+1];
    
                int len = min(a.size(), b.size()), j = 0;
                for(; j < len; j++){
                    if(a[j] != b[j]){
                        adj[a[j] - 'a'].push_back(b[j] - 'a');
                        indegree[b[j] - 'a']++;
                        break;
                    }
                }
                if(j == len && a.size() > b.size()) return "";
            }
    
            k = 0;
            for(int i = 0; i < 26; i++) if(present[i]) k++;
    
            if(isCyclic(adj, k)) return "";
    
            queue<int> q;
            for(int i = 0; i < 26; i++){
                if(present[i] && indegree[i] == 0) q.push(i);
            }
    
            string ans;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                ans += (cur + 'a');
    
                for(auto it: adj[cur]){
                    indegree[it]--;
                    if(indegree[it] == 0) q.push(it);
                }
            }
    
            return (ans.size() == k) ? ans : "";
        }
    };