#include<bits/stdc++.h>
using namespace std;

//! DisjointSet template:
class DisjointSet{
    vector<int> rank, parent;
  public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int parU = findUPar(u);
        int parV = findUPar(v);

        if(parU == parV) return;
        if(rank[parU] < rank[parV]) parent[parU] = parV;
        else if(rank[parU] > rank[parV]) parent[parV] = parU;
        else{
          parent[parV] = parU;
          rank[parU]++;
        }
    }
};

int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2); 
    ds.unionByRank(2, 3); 
    ds.unionByRank(4, 5); 
    ds.unionByRank(6, 7); 
    ds.unionByRank(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.unionByRank(3, 7); 

    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
    return 0;
}