#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if(!root) return ans;

    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    map<int, int> mp;

    while(!q.empty()){
        
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            auto top = q.front();
            q.pop();
            if(mp.find(top.second - 1) == mp.end()) mp[top.second - 1] = top.first->data;

            if(top.first->left)   q.push({top.first->left, top.second - 1});
            if(top.first->right)   q.push({top.first->right, top.second + 1});
        }
    }
    for(auto it: mp) ans.push_back(it.second);
    return ans;
}