class DisjointSet{
    vector<int> rank, parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }
    int findPar(int n){
        if(parent[n] == n) return n;
        return parent[n] = findPar(parent[n]);
    }
    void unionByRank(int u, int v){
        int parU = findPar(u);
        int parV = findPar(v);

        if(parU == parV) return;
        if(rank[parV] < rank[parU]) parent[parV] = parU;
        else if(rank[parV] > rank[parU]) parent[parU] = parV;
        else{
            parent[parV] = parU;
            rank[parU]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cnt = 0, ans = 0;
        for(auto it: connections){
            int u = it[0], v = it[1];
            if(ds.findPar(u) == ds.findPar(v)) cnt++;
            else ds.unionByRank(u, v);
        }
        for(int i = 1; i < n; i++){
            if(ds.findPar(0) != ds.findPar(i)){
                cnt--; ans++;
                ds.unionByRank(0, i);
            }
        }
        return (cnt >= 0) ? ans : -1;
    }
};