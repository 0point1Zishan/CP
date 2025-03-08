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
        int paru = findPar(u);
        int parv = findPar(v);
        
        if(paru == parv) return;
        if(rank[parv] < rank[paru]) parent[parv] = paru;
        else if(rank[paru] < rank[parv]) parent[paru] = parv;
        else{
            parent[parv] = paru;
            rank[paru]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int mxRow = 0, mxCol = 0, n = stones.size();
        for(auto it: stones){
            mxRow = max(mxRow, it[0]);
            mxCol = max(mxCol, it[1]);
        }
        DisjointSet ds(mxRow + mxCol + 1);
        unordered_set<int> st;
        for(auto it: stones){
            int u = it[0], v = it[1] + mxRow + 1;
            ds.unionByRank(u, v);
            st.insert(u);
            st.insert(v);
        }
        int component = 0;
        for(auto it: st){
            if(ds.findPar(it) == it){
                component++;
            }
        }
        return n - component;
    }
};