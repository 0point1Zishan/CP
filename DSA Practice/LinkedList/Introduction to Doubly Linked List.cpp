class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // code here
        int n = arr.size();
        Node* head = new Node(arr[0]);
        Node *temp = head;
    
        for(int i = 1; i < n; i++){
            Node* a = new Node(arr[i]);
            a->prev = temp;
            temp->next = a;
            temp = a;
        }
        return head;
    }
};