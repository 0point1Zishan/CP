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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> margeMail;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(margeMail.find(mail) == margeMail.end()){
                    margeMail[mail] = i; 
                }
                else{
                    ds.unionByRank(i, margeMail[mail]);
                }
            }
        }
        vector<string> par[n];
        for(auto it: margeMail){
            string m = it.first;
            int p = ds.findPar(it.second);
            par[p].push_back(m);
        }
        
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(par[i].size() == 0) continue;
            sort(par[i].begin(), par[i].end());
            
            vector<string> temp = {accounts[i][0]};
            for(auto it: par[i]) temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};