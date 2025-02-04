#include <bits/stdc++.h> 
class node{
    public:
    int data;
    int row;
    int col;

    node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class cmp{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node*, vector<node*>, cmp> pq;

    for(int i = 0; i < k; i++){
        node* newNode = new node(kArrays[i][0], i, 0);
        pq.push(newNode);
    }
    vector<int> ans;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        ans.push_back(it->data);
        if(it->col + 1 < kArrays[it->row].size()){
            node* newNode = new node(kArrays[it->row][it->col + 1], it->row, it->col + 1);
            pq.push(newNode);
        }
    }
    return ans;
}