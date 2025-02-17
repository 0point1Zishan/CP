/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

bool isParentSum(Node *root){
    // Write your code here.
    queue<Node*> q;
    if(root) q.push(root);

    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            Node* p = q.front();
            q.pop();

            int sum = p->data;
            if(p->left) q.push(p->left), sum -= p->left->data;
            if(p->right) q.push(p->right),  sum -= p->right->data;

            if((p->left || p->right) && sum != 0) return false;  
        }
    }
    return true;
}