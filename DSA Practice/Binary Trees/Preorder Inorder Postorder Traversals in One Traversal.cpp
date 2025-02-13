/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
#include<bits/stdc++.h>
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>> ans(3);
    stack< pair<TreeNode*, int> > st;
    if(root) st.push({root, 1});

    while(!st.empty()){
        auto top = st.top();
        st.pop();

        if(top.second == 1){
            ans[1].push_back(top.first->data);
            top.second++;
            st.push(top);

            if(top.first->left)  st.push({top.first->left, 1});
        }
        else if(top.second == 2){
            ans[0].push_back(top.first->data);
            top.second++;
            st.push(top);

            if(top.first->right)  st.push({top.first->right, 1});
        }
        else ans[2].push_back(top.first->data);
    }

    return ans;
}