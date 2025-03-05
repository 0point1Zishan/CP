#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int n, int edges, int src) {
    // Write your code here.

    vector<vector<pair<int, int>> > adj(n);
    for(auto it: vec){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    vector<int> dis(n, 1e9);
    dis[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0, src});
    
    while(!pq.empty()){
        int par = pq.top().second;
        int parDis = pq.top().first;
        pq.pop();
        
        for(auto it: adj[par]){
            if(it.second + parDis < dis[it.first]){
                dis[it.first] = it.second + parDis;
                pq.push({dis[it.first], it.first});
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(dis[i] == 1e9) dis[i] = INT_MAX;
    }return dis;
}