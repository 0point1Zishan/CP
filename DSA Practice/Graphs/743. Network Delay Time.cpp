class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            vector<vector<pair<int, int>>> adj(n+1);
            for(auto it: times){
                adj[it[0]].push_back({it[1], it[2]});
            }
            if(!adj[k].size()) return -1;
            vector<int> time(n+1, 1e9);
            time[0] = 0;
            time[k] = 0;
    
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
            pq.push({k, 0});
    
            int ans = -1;
            while(!pq.empty()){
                int cur = pq.top().first;
                int t = pq.top().second;
                pq.pop();
    
                for(auto it: adj[cur]){
                    if(t + it.second < time[it.first]){
                        time[it.first] = t + it.second;
                        pq.push({it.first, time[it.first]});
                    }
                }
            }
            for(auto it: time){
                if(it == 1e9) return -1;
                else ans = max(ans, it);
            }
            return ans;
        }
    };