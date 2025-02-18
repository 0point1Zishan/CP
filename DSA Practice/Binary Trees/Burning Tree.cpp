class Solution {
  public:
    void makeParents(Node* root,  unordered_map<Node*, Node*>& parent, Node* &targetNode, int target){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto top = q.front();
                q.pop();
                
                if(top->data == target)  targetNode = top;
                if(top->left){
                    q.push(top->left);
                    parent[top->left] = top;
                }
                if(top->right){
                    q.push(top->right);
                    parent[top->right] = top;
                }
            }
        }
    }
    int findMinTime(Node* root, unordered_map<Node*, Node*>& parent, unordered_map<Node*, bool>& visited){
        if(!root) return 0;
        int left = 0, right = 0, par = 0;
        
        if(root->left && !visited[root->left]){
            visited[root->left] = true;
            left = 1 + findMinTime(root->left, parent, visited);
        }
        if(root->right && !visited[root->right]){
            visited[root->right] = true;
            right = 1 + findMinTime(root->right, parent, visited);
        }
        if(parent[root] && !visited[parent[root]]){
            visited[parent[root]] = true;
            par = 1 + findMinTime(parent[root], parent, visited);
        }
        return max({left, right, par});
    }
    
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*, Node*> parent;
        Node* targetNode = NULL;
        makeParents(root, parent, targetNode, target);
        
        unordered_map<Node*, bool> visited;
        visited[targetNode] = true;
        return findMinTime(targetNode, parent, visited);
    }
};